# (Some) School Projects

In this repository, you will find some projects I have done for my classes at UBA (University of Buenos Aires) and NTNU (Norwegian University of Science and Technology).


#### [Cartas Enlazadas] (Algorithms and Data Structures II/Cartas Enlazadas)

"Cartas Enlazadas" (*linked cards*) was a one person project I had for "Algorithms and Data Structures II" at UBA. The goal was to model a ficticious game of the same name. In order to do that, we had to implement a generic doubly linked list in C++. We also had to make sure it didn't have any kind of memory leak using Valgrind. To run the test cases and check for memory leaks run the following commands in a Linux terminal:

`g++ -g tests.cpp -o tests`

`valgrind --leak-check=full -v ./tests` 
