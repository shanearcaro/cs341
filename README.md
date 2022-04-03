# CS341 - Foundations of Computer Science 2

### Description
This class builds upon material learned in Foundations of Computer Science which was mainly focused on Discrete Math and set theory. This class will use the knowledge of sets and set theory to create Deterministic Finite Automata (DFA) and Non-deterministic Finite Automata (NFA), which are essentialy state machines that either accept or reject a given input. Later lessons include Pushdown Automata (PDA), which is a DFA but with memory, and different types of Turing machines.

### Assignment Notes
The code I used to construct a DFA for Project 1 is very modular and allows for the creation of different DFAs as long as the node structure and transitions are modified. Because a PDA is a DFA but with memory, pretty much all of the DFA code was able to be used to construct the PDA. The only notable differences are the following:
1. The PDA will crash instead of transitioning to a trap state. If the DFA has no valid transition to take, it will transition to the trap state which has no outbound transitions. The DFA will stay in this state until it finishes reading characters and will reject the string. If the PDA does not find any valid transitions it will immediately crash, stop reading input, and reject the string.

2. The PDA uses a stack as memory which allows it to be more powerful than a normal DFA. Even if the PDA finds a valid transition to take, if the stack does not have the required element on top to pop, the transition will be ignored. This allows the PDA to require extra characteristics such as matching parenthesis.

### Grades

Project 1: <b> 100 </b>
Project 2: <b> TBD </b>
