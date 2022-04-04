#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// Add linker section here

// Length of the DIGITS set
const int DIGITS_LENGTH = 10;

// Lentgh of the SYMBOLS set
const int SYMBOLS_LENGTH = 6;

// Length of the PERIOD set
const int PERIOD_LENGTH = 1;

// Length of the AMPERSAND set
const int AMPERSAND_LENGTH = 1;

// Length of the SIGMA set
const int SIGMA_LENGTH = DIGITS_LENGTH + SYMBOLS_LENGTH + PERIOD_LENGTH + AMPERSAND_LENGTH;

// Set of all digits
std::string DIGITS[DIGITS_LENGTH];

// Set of all SYMBOLS
std::string SYMBOLS[SYMBOLS_LENGTH];

// Set of a period
std::string PERIOD[PERIOD_LENGTH];

// Set of an ampersand
std::string AMPERSAND[AMPERSAND_LENGTH];

// Set of all allowed letters in previous sets, combined
std::string SIGMA[SIGMA_LENGTH];

// Concatenate DIGITS, SYMBOLS, PERIOD, and AMPERSAND into SIGMA
void concat() {
    for (int i = 0; i < DIGITS_LENGTH; i++) SIGMA[i] = DIGITS[i];
    for (int i = DIGITS_LENGTH; i < DIGITS_LENGTH + SYMBOLS_LENGTH; i++) SIGMA[i] = SYMBOLS[i - DIGITS_LENGTH];
    SIGMA[DIGITS_LENGTH + SYMBOLS_LENGTH] = PERIOD[0];
    SIGMA[DIGITS_LENGTH + SYMBOLS_LENGTH + 1] = AMPERSAND[0];
}

class Transition {
    private:
        // List of strings that allow for a transition to be followed
        std::string accept;

        // What will get popped following this transition
        std::string pop;

        // What will get pushed following this transition
        std::string push;

        // ID of the node that initialized this transition
        int from;

        // ID of the ndoe that ends this transition (will become the new head of PDA)
        int to;

    public:
        Transition(std::string accepting, std::string popping, std::string pushing, int from, int to): accept(accepting), pop(popping), push(pushing), from(from), to(to) {};

        // Get the list of acceptable strings to transition on
        std::string getAccept() {
            return accept;
        }

        // Get pop
        std::string getPop() {
            return pop;
        }

        // Get push
        std::string getPush() {
            return push;
        }

        // Get the ID of the node that initialized this transition
        int getFrom() {
            return from;
        }

        // Get the ID of the node that ends this transition
        int getTo() {
            return to;
        }

        bool compare(std::string accept, std::string push) {
            return this->accept.compare(accept) == 0 && this->push.compare(push) == 0;
        }
};

class Node {
    private:
        // List of possible transitions from node
        std::vector<Transition> transitions;

        // Unique id number
        int id;

        // True if accept state, otherwise false
        bool state;

    public: 
        // Create a regular node with default accept state
        Node(int id): id(id), state(false) {};

        // Create an accept state node
        Node(int id, bool acceptState): id(id), state(acceptState) {};

        // Get the current state of a node (if it's an accepting state)
        bool getState() {
            return state;
        }

        // Get the unique id of a node
        int getID() {
            return id;
        }
        
        // Add a new transition between the current node and a new node
        // The transition is only followed if the accept string matches the input string
        void addTransition(std::string accept, std::string pop, std::string push, int id) {
            Transition t(accept, pop, push, this->getID(), id);
            this->transitions.push_back(t);
        }

        // Get a list of all transitions a node has
        std::vector<Transition> getTransitions() {
            return this->transitions;
        }

        // Given an input character determine which transition should be followed
        // Return the node id of the transitioned to node
        int next(std::string input, std::string stack, std::string &push, std::string &pop) {
            // Iterate through every transition looking for an accept
            for (int i = 0; i < transitions.size(); i++) {
                Transition* p_temp = &transitions.at(i);

                // Transition is supposed to accept a digit
                if (p_temp->getAccept().compare("D") == 0) {
                    // Input is a digit
                    // Never have to check the stack for when a digit is being added
                    if (isdigit(input.at(0))) {
                        push = "";
                        pop = "";
                        return p_temp->getTo();
                    }
                }
                // Transition is supposed to accept a period
                else if (p_temp->getAccept().compare("P") == 0) {
                    if (input.compare(".") == 0) {
                        push = "";
                        pop = "";
                        return p_temp->getTo();
                    }
                }
                // Transition is supposed to accept a left parenthesis
                else if (p_temp->getAccept().compare("L") == 0) {
                    if (input.compare("(") == 0) {
                        // Change the push element for the PDA to recognize on return
                        push = "L";
                        pop = "!";
                        return p_temp->getTo();
                    }
                }
                // Transition is supposed to accept a right parenthesis
                else if (p_temp->getAccept().compare("R") == 0) {
                    if (input.compare(")") == 0) {
                        // Only allow transition if top of stack matches what should be popped
                        if (stack.compare("L") == 0) {
                            push = "L";
                            pop = p_temp->getPop();
                            return p_temp->getTo();
                        }
                    }
                }
                // Transition is supposed to accept a symbol
                else if (p_temp->getAccept().compare("S") == 0) {
                    if (input.compare("+") == 0 || input.compare("-") == 0 ||
                        input.compare("*") == 0 || input.compare("/") == 0)
                            return p_temp->getTo();
                }
                else if (p_temp->getAccept().compare("A") == 0) {
                    if (input.compare("&") == 0) {
                        // Check if ! transition is pushing or popping a &
                        if (p_temp->getPush().compare("A") == 0) {
                            push = "A";
                            pop = "!";
                            return p_temp->getTo();
                        }
                        else {
                            // Only allow transition if top of stack matches what should be popped
                            if (stack.compare("A") == 0) {
                                push = "A";
                                pop = p_temp->getPop();
                                return p_temp->getTo();
                            }
                        }
                    }
                }
            }
            // No transition was found, crash
            return -1;
        }
};

class PDA {
    private:
        // Private ticket counter for each PDA
        // Nodes will increment each ID by 1
        int ticket = 0;

        // List of nodes for a given PDA
        std::vector<Node> nodes;

        // Head node responsible for transitioning to the next state
        Node* head;

        // Stack of elements
        std::vector<std::string> stack;

    public:
        PDA() {};
        
        // Create PDA with set of initial nodes
        void setNodes(std::vector<Node> qNodes) {
            nodes = qNodes;
            
            // Head will be set to the first node within the nodes list
            this->head = &nodes.at(0);
        }

        // Reset the PDA so the head node is back in its starting state
        void reset() {
            this->head = &nodes.at(0);
        }

        // Push a new symbol on top of the stack
        void push(std::string symbol) {
            this->stack.push_back(symbol);
        }

        // Remove the top symbol from the stack
        void pop() {
            this->stack.pop_back();
        }

        // Look at the symbol on top of the stack without removing it
        std::string peak() {
            if (this->stack.size() == 0)
                return "";
            return this->stack.back();
        }

        // Get a list of every node within the PDA
        std::vector<Node> getNodes() {
            return nodes;
        }

        // Get a node by its unique id number
        Node* getNode(int id) {
            // Iterate through the list and check the id against the given id
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes.at(i).getID() == id)
                    return &nodes.at(i);
            }

            // If the node isn't found (this should never happen) return the null ptr
            return nullptr;
        }

        // Generate a new ticket for a node
        int getTicket() {
            return ++ticket; 
        }

        // Run through the PDA given input
        bool next(std::string input) {
            char currentCharacter;
            std::string pushStack = "";
            std::string popStack  = "";

            // Loop through the entire input string and iterate the PDA transition state
            for (int i = 0; i < input.size(); i++) {
                // Get a single character to test
                currentCharacter = input[i];

                // Get the unique id of the node that should be transitioned to
                int ticket = head->next(std::string(1, currentCharacter), this->peak(), pushStack, popStack);

                // The string analysis crashed
                if (ticket == -1) {
                    // Accept or reject the input string based on the PDA characteristics
                    std::cout << "Machine Crashed" << std::endl;
                    return false;
                }

                // Make sure stack is only manipulated when a push or pop operation is called
                if (pushStack.compare("") != 0 && popStack.compare("") != 0) {
                    if (pushStack.compare(popStack) == 0) {
                        this->pop();
                    }
                    else if (pushStack.compare("") != 0 && popStack.compare("!") == 0) {
                        this->push(pushStack);
                    }
                }

                if (pushStack.compare("") == 0 || pushStack.compare("!") == 0)
                    pushStack = "ε";
                if (popStack.compare("") == 0 || popStack.compare("!") == 0)
                    popStack = "ε";
                if (popStack.compare(pushStack) == 0)
                    pushStack = "ε";
                std::cout << "State q" << head->getID() << ": " << currentCharacter << ", " << popStack << " ➜ " << pushStack << std::endl;

                // Head now becomes the transitioned node
                head = getNode(ticket);
                pushStack = "";
                popStack = "";
            }

            // Accept or reject the input string based on the PDA characteristics
            std::cout << "State q" << head->getID() << std::endl;
            std::cout << "Final q" << head->getID() << ": " << (head->getState() ? "accept" : "reject") << std::endl;

            return head->getState();
        }
};

PDA pda;

// Print the required opening text
void printOpening();

// Create the nodes and set up the required transitions for the PDA to work
void createPDA();

// Analyze a given string on the PDA
void start(std::string input);

int main(int argc, char* argv[]) {
    // Concatenate the sets together
    concat();

    // Print the opening, has to be the first printed statements
    printOpening();

    // Set up the PDA
    createPDA();

    // Ask user if they want to enter a string and continue on with the program; otherwise terminate
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);
    std::cout << user_input << std::endl;

    // Once PDA is finished loop back until the user terminates they program
    while (user_input != "N" || user_input != "n") {
        if (user_input == "Y" || user_input == "y") {
            // If user enters a string read the string but if user enters a file read all input from file
            std::cout << "Enter string or file to be read: ";
            std::string input;
            getline(std::cin, input);

            // The inputs are being written again only to create output.txt with the make output version
            std::cout << input << std::endl;
            std::cout << std::endl;

            // Check if the given string is a file
            std::fstream file(input);
            if (file.is_open()) {
                // While more lines can be read, start both DFAs
                while (!file.eof()) {
                    getline(file, input);
                    start(input);

                    // Need to reset the PDA's head node in order to be run again
                    pda.reset();
                }
                // Close the file being read from
                file.close();
            }
            else {
                // File could not be read, must be string input
                start(input);

                // Need to reset the PDA's head node in order to run again
                pda.reset();
            }
        }
        // If user does not want to enter a string or file terminate the program
        else if (user_input == "N" || user_input == "n") {
            std::cout << "No input string being read. Terminating." << std::endl;
            return 0;
        }
        // If input is not understood terminate the program
        else {
            std::cout << "Cannot understand input string. Terminating." << std::endl;
            return 0;
        }
        // Loop back
        std::cout << "Would you like to enter a string? Y or N: ";
        getline(std::cin, user_input);
        // The inputs are being written again only to create output.txt with the make output version
        std::cout << user_input << std::endl;
        std::cout << std::endl;
    }
    // Exit
    return 0;
}

// Analyze a given string on the DFA
void start(std::string input) {
    bool test = pda.next(input);

    std::cout << "Final Result: " << input << ((test) ? " is accepted" : " is rejected") << std::endl;
    std::cout << std::endl;
}

// Print the custom opening section required by project instructions
void printOpening() {
    std::cout << "Project 2 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

// Create the nodes and set up the required transitions for the DFA to work
void createPDA() {
    // Create each node
    Node q1(pda.getTicket()), q2(pda.getTicket()), q3(pda.getTicket());
    Node q4(pda.getTicket()), q5(pda.getTicket()), q6(pda.getTicket());
    Node q7(pda.getTicket(), true);

    // Add transitions between the nodes
    q1.addTransition("A", "!", "A", q2.getID());
    q2.addTransition("L", "!", "L", q2.getID());

    // Q2 - Q5 for float starting with a digit
    q2.addTransition("D", "!", "!", q3.getID());
    q3.addTransition("D", "!", "!", q3.getID());
    q3.addTransition("P", "!", "!", q5.getID());

    // Q2 - Q5 for float starting with a period
    q2.addTransition("P", "!", "!", q4.getID());
    q4.addTransition("D", "!", "!", q5.getID());

    // Q5 transitions
    q5.addTransition("R", "L", "!", q6.getID());
    q5.addTransition("S", "!", "!", q2.getID());
    q5.addTransition("A", "A", "!", q7.getID());
    q5.addTransition("D", "!", "!", q5.getID());

    // Q6 transitions
    q6.addTransition("R", "L", "!", q6.getID());
    q6.addTransition("S", "!", "!", q2.getID());
    q6.addTransition("A", "A", "!", q7.getID());

    // Put the nodes into the DFA
    std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7};
    pda.setNodes(nodes);
}
