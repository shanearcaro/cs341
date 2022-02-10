/**
 * @brief Author
 * Shane Arcaro sma237
 * CS 341 Spring Semester 2022
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Length of the GAMMA set
const int GAMMA_LENGTH = 26;

// Length of the DELTA set
const int DELTA_LENGTH = 1;

// Length of the PHI set
const int PHI_LENGTH = 1;

// LENGTH of the SIGMA set
const int SIGMA_LENGTH = GAMMA_LENGTH + DELTA_LENGTH + PHI_LENGTH;

// Set of all lowercase roman letters (a-z)
std::string GAMMA[GAMMA_LENGTH] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// Set of a period (.)
std::string DELTA[DELTA_LENGTH] = {"."};

// Set of an at sign (@)
std::string PHI[PHI_LENGTH] = {"@"};

// Set of all allowed letters in previous sets, combined
std::string SIGMA[SIGMA_LENGTH];

// Concatenate GAMMA, DELTA, and PHI iinto SIGMA
void concat() {
    for (int i = 0; i < GAMMA_LENGTH; i++) {
        SIGMA[i] = GAMMA[i];
    }
    SIGMA[GAMMA_LENGTH] = DELTA[0];
    SIGMA[GAMMA_LENGTH + DELTA_LENGTH] = PHI[0];
}

class Transition {
    private:
        // List of strings that allow for a transition to be followed
        std::string accept;

        // ID of the node that initialized this transition
        int from;

        // ID of the ndoe that ends this transition (will become the new head of DFA)
        int to;

    public:
        Transition(std::string accepting, int from, int to): accept(accepting), from(from), to(to) {};

        // Get the list of acceptable strings to transition on
        std::string getAccept() {
            return accept;
        }

        // Get the ID of the node that initialized this transition
        int getFrom() {
            return from;
        }

        // Get the ID of the node that ends this transition
        int getTo() {
            return to;
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
        void addTransition(std::string accept, int id) {
            Transition t(accept, this->getID(), id);
            this->transitions.push_back(t);
        }

        // Get a list of all transitions a node has
        std::vector<Transition> getTransitions() {
            return this->transitions;
        }

        // Given an input character determine which transition should be followed
        // Return the node id of the transitioned to node
        int next(std::string input) {
            // Iterate through every transition looking for an accept
            // If a transition is never found follow the trap transition (the last transition)
            for (int i = 0; i < transitions.size() - 1; i++) {
                Transition* p_temp = &transitions.at(i);
                // If input is a direct match
                if (input.compare(p_temp->getAccept()) == 0) {
                    return p_temp->getTo();
                }
                // If the input belongs to the GAMMA set (lower case letters)
                else if (p_temp->getAccept().compare("G") == 0) {
                    // If input is a letter
                    if (isalpha(input[0])) {
                        return p_temp->getTo();
                    }
                }
                // If the input belongs to the GAMMA set except for x in G-x
                else if (p_temp->getAccept().substr(0, 2).compare("G-") == 0) {
                    // Find out which letter should be ignored
                    std::string letter = p_temp->getAccept().substr(2);
                    if (isalpha(input[0]) && input.compare(letter) != 0) {
                        return p_temp->getTo();
                    }
                }
            }

            // No transition was found: follow trap transition
            Transition* p_trap = &transitions.back();
            return p_trap->getTo();
        }
};

class DFA {
    private:
        // Private ticket counter for each DFA
        // Nodes will increment each ID by 1
        int ticket = 0;

        // List of nodes for a given DFA
        std::vector<Node> nodes;

        // Head node responsible for transitioning to the next state
        Node* head;

    public:
        DFA() {};

        // Create DFA with set of initial nodes
        void setNodes(std::vector<Node> qNodes) {
            nodes = qNodes;
            
            // Head will be set to the first node within the nodes list
            this->head = &nodes.at(0);
        }

        // Reset the DFA so the head node is back in its starting state
        void reset() {
            this->head = &nodes.at(0);
        }

        // Get a list of every node within the DFA
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

        // Run through the DFA given input
        bool next(std::string input) {
            char currentCharacter;
            std::cout << "Start q1" << std::endl;

            // Loop through the entire input string and iterate the DFA transition state
            for (int i = 0; i < input.size(); i++) {
                // Get a single character to test
                currentCharacter = input[i];
                std::cout << "State q" << head->getID() << ": " << currentCharacter << std::endl;

                // Get the unique id of the node that should be transitioned to
                int ticket = head->next(std::string(1, currentCharacter));

                // Head now becomes the transitioned node
                head = getNode(ticket);
            }

            // Accept or reject the input string based on the DFA characteristics
            std::cout << "State q" << head->getID() << std::endl;
            std::cout << "Final q" << head->getID() << ": " << (head->getState() ? "accept" : "reject") << std::endl;

            return head->getState();
        }
};

/** Sets required for each DFA to work */
// Γ = set of all lowercase roman letters
// Δ = set of .
// Φ = set of @
// Σ = Γ U Δ U Φ

/** Strings that make up the rules for each DFA */
// S1 = ΓΓ*
// S2 = ΔΓΓ*
// S3 = {.org}

// DFA : Responsible for analyzing strings against L = L1 U L2, where L1 = S1ΦS1S3 and L2 = S1S2*ΦS1S2*S3
DFA dfa;

// Print the required opening text
void printOpening();

// Create the nodes and set up the required transitions for the DFA to work
void createDFA();

// Analyze a given string on both DFAs L1 and L2
// A string only needs to pass one of the DFAs to be accepted
void start(std::string input);

int main(int argc, char* argv[]) {
    // Concatenate the sets together
    concat();

    // Print the opening, has to be the first printed statements
    printOpening();

    // Set up the DFA
    createDFA();

    // Ask user if they want to enter a string and continue on with the program; otherwise terminate
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);
    std::cout << user_input << std::endl;

    // Once DFA is finished loop back until the user terminates the program
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
                // While mroe lines can be read, start both DFAs
                while (!file.eof()) {
                    getline(file, input);
                    start(input);

                    // Need to reset the DFA's head node in order to be run again
                    dfa.reset();
                }
                // Close the file being read from
                file.close();
            }
            else {
                // File could not be read, must be string input
                start(input);

                // Need to reset the DFA's head node in order to be run again
                dfa.reset();
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
    bool test = dfa.next(input);

    std::cout << "Final Result: " << input << ((test) ? " is accepted" : " is rejected") << std::endl;
    std::cout << std::endl;
}

// Print the custom opening section required by project instructions
void printOpening() {
    std::cout << "Project 1 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

// Create the nodes and set up the required transitions for the DFA to work
void createDFA() {
    // Create each node
    Node q1(dfa.getTicket()), q2(dfa.getTicket()), q3(dfa.getTicket());
    Node q4(dfa.getTicket()), q5(dfa.getTicket()), q6(dfa.getTicket());
    Node q7(dfa.getTicket()), q8(dfa.getTicket(), true), q9(dfa.getTicket());

    // Add transitions between the nodes
    q1.addTransition("G",   q2.getID());
    q2.addTransition("G",   q2.getID());
    q2.addTransition(".",   q1.getID());
    q2.addTransition("@",   q3.getID());
    q3.addTransition("G",   q4.getID());
    q4.addTransition("G",   q4.getID());
    q4.addTransition(".",   q5.getID());
    q5.addTransition("o",   q6.getID());
    q5.addTransition("G-o", q4.getID());
    q6.addTransition("r",   q7.getID());
    q6.addTransition("G-r", q4.getID());
    q6.addTransition(".",   q5.getID());
    q7.addTransition("g",   q8.getID());
    q7.addTransition("G-g", q4.getID());
    q7.addTransition(".",   q5.getID());
    q8.addTransition("G",   q4.getID());
    q8.addTransition(".",   q5.getID());

    // Each node needs a final transition added to be able to reach the trap node (q9)
    // Trap node transition is only used if the DFA cannot continue properly
    std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7, q8, q9};
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).addTransition("X", q9.getID());
    }
    // Put the nodes into the DFA
    dfa.setNodes(nodes);
}
