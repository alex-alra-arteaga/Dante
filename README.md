# Maze-Generator-Solver
The goal of this project is to generate mazes (in a reasonable amount of time), solve them (in a reasonable amount of time), and print the solution.

The actual algorithm I figured out is a mix of DPS (Depth-First-Search), Growing Tree and Recursive Backtracking Algorithm.
I use a Li-Fo stack which stores the correct path, cell by cell.
My solution approaches a O(n * log(n)) time complexity.

![image](https://user-images.githubusercontent.com/108436798/226178743-c393e0e5-0b1a-43ad-bad7-f9a803ebe140.png)

![image](https://user-images.githubusercontent.com/108436798/226178756-092af0ec-2de4-4c13-a6c3-105962b58196.png)


<h2>Compilation and binary execution</h2>

'Make re' at root

Generator:
For a perfect generator, specify it with the word. Ignore the third argument, or put 'imperfect' for an imperfect generation.

![image](https://user-images.githubusercontent.com/108436798/226178518-4994e02e-285a-4d17-9264-f615d3ed5bda.png)

Solver:

![image](https://user-images.githubusercontent.com/108436798/226178473-19b57aaa-4a4d-4289-8950-53f07439aa28.png)

Hint: Remember to access the folder/generator folder to execute the binary.
