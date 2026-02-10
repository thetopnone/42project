*This project has been created as part of the 42 curriculum by akonstan*

## Description

A solution to the dinning philosophers problem introduced by Edsger Dijkstra in 1965. X amount of philosophers are sitting in a round table and each has a fork and a plate full with spaghetti pasta in front of them. In order to eat the pasta in front of him, each philosopher needs to hold two forks in his hand. The goal is to sustain those philosophers for as long as possible, while cycling through these states:

	Thinking, Eating and Sleeping 

Without dying from starvation.

This solution is based on multithreading, mutexes and thread syncronization. Every philosopher is represented with a thread. Every fork is a mutex.

To handle data racing, philosopher death and end of program conditons, an additional monitoring thread was introduced. It oversees in very frequent time cycles if any of the philosophers has died or if they are all full, subsequently ending the program in each case.

Also, to handle data races, extra mutexes have been added for every resource that is shared with all (or some) threads (the output stream, death flags, eating status, etc.)

## Instructions

To compile the program, run the command **_make_** inside the project folder and then run the program by executing a command in this format:

**./philo Number_of_Philosophers Time_to_Die Time_to_eat Time_to_sleep Amount_of_times_each_Philosopher_should_eat**

*The amount of times each philosopher should eat is an optional parameter and the program will also run without it*

**IMPORTANT!!! DO NOT RUN WITH AN AMOUNT OF PHILOSOPHERS HIGHER THAN 200**

## Resources

[About the Dining Philosophers problem :](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
[About Multithreadding in C](https://www.geeksforgeeks.org/c/multithreading-in-c/)
[About Mutexes](https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/)
[About Data Races](https://www.geeksforgeeks.org/cpp/data-races-in-cpp/)

*AI was recruited to assist with deciphering the valgrind and helgrind terminal outputs for debugging*
*AI assisted with understanding why certain data races were taking place*
