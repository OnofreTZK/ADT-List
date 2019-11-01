# Implemention of Abstract Data Type Vector - Basic Data Structure I
## About the project
We focus on two aspects of the list: the core operations that should be supported, and the two different forms of organizing the data inside a list, using arrays(static or dynamic) or linked list (singly or doubly linked).
In this initial programming project, we begin by introducing basic definition of terms, properties and operations. Next we provide details on implementing a list ADT with dynamic array.

## Compile and run
In project root directory
```bash
$ cmake -S . -Bbuild && cd build/

```
In `build` 
```bash
$ make 

```
To run driver test:
```bash
$ ./vector_drive

```
## Limitations
`iterator insert( iterator pos, const T & value)`: In some cases the method can't insert element correctly. 

## Authorship
[Tiago Onofre Araujo](https://github.com/OnofreTZK)
