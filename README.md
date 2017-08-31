# Tetris Solver

## Overview
The problem being solved is a packing problem- specifically fitting tetris pieces into as small a space as possible.

The compuations necessary to solve this problem increase exponentially as the number of pieces increases, but it performs the calculations in human time for nearly 30 pieces. This is thanks to the aggressive optimization of the algorithm done by my partner and I

## The Algorithm
This project is an implementation of a recursive backtracking algorithm

The gist of the program is as follows:
- tetris_solver will declare a "map" on which it will attempt to place pieces
- tetris_solver will then parse the given input file, and place all read pieces into a hashmap	
- tetris_solver will then attempt to place pieces on the map, one at a time.
	- if it encounters a piece that cannot be placed anywhere on the map, the placing function returns, the previously placed piece is then moved to the next acceptable place for it, and the program continues checking
	- if all possible locations of all pieces have been checked and a valid map has not been made, the map is then expanded, and the process begins anew.
	- once all pieces have been placed on a map, the problem has been solved, and the map information is passed to the printing function
	
## The Optimization

The algorithm is aggressively optimized by storing all map information in a series of bytes, and by storing all piece information in a hashmap for quick searching

The "map" is represented as 16 unsigned shorts (each of which has 16 bits). Each bit represents the state of one square on the resulting board.
When the map is declared, all bits except the upper-left most 4 are set to "1", as shown here:
> 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
> 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
This sets up the program with a working map of the smallest possible size. As the program runs, the map will be expanded as necessary.
All pieces are stored as unsigned longs. In the case of a vertical straight line, the piece is represented on the board as
> 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
> 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
> 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
> 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
If you represent this quantity in a single line of binary, it can be treated as a single value. This makes the time necessary for attempts at checking whether a placement for a piece on the board is valid, placing a piece on the board, removing a piece from the board, and everything in-between as simple as a single xor operation.
By taking advantage of the speed of bit-wise operations my partner and I were able to out-perform the overwhelming majority of solutions to this problem.
