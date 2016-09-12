# (Some) School Projects

In this repository, you will find some projects I have done for my classes at UBA (University of Buenos Aires) and NTNU (Norwegian University of Science and Technology).

---


#### [Cartas Enlazadas] (Algorithms and Data Structures II/Cartas Enlazadas)

"Cartas Enlazadas" (*linked cards*) was a one person project I had for "Algorithms and Data Structures II" at UBA. The goal was to model a ficticious game of the same name. In order to do that, we had to implement a generic doubly linked list in C++. We also had to make sure it didn't have any kind of memory leak using Valgrind. To run the test cases and check for memory leaks run the following commands in a Linux terminal:

`g++ -g tests.cpp -o tests`

`valgrind --leak-check=full -v ./tests` 

---


#### [Fire Alarm System] (TTM4115 - Engineering Distributed Real-time Systems)

This was a term assignmet for the class "Engineering Distributed Real-time Systems" at NTNU. We worked in groups of 3, and the task was to build a distributed system that solved a specific problem, document the system and its development, and finally implement it using several Raspberry Pi as nodes. In our case, we decided to model a fire alarm system, using the Raspberry Pis as sensors. 

In the first part of the project we had to make the specification and documentation using UML structure diagrams, sequence diagrams, activity diagrams and state machines of all the different parts of the system.

---



