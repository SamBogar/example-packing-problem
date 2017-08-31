# Tetris Solver

## Overview
The problem being solved is a packing problem- specifically fitting tetris pieces into as small a space as possible.

The compuations necessary to solve this problem increase exponentially as the number of pieces increases, but it performs the calculations in human time for nearly 30 pieces. This is thanks to the aggressive optimization of the algorithm done by my partner and I

## The Algorithm
This project is an implementation of a recursive backtracking algorithm

The gist of the program is as follows:

	-tetris_solver will declare a "map" on which it will attempt to place pieces
	-tetris_solver will then parse the given input file, and place all read pieces into a hashmap	
	-tetris_solver will then attempt to place pieces on the map, one at a time.
		-if it encounters a piece that cannot be placed anywhere on the map, the placing function returns, the previously placed piece is then moved to the next acceptable place for it, and the program continues checking
		-if all possible locations of all pieces have been checked and a valid map has not been made, the map is then expanded, and the process begins anew.
		-once all pieces have been placed on a map, the problem has been solved, and the map information is passed to the printing function
	
## The Optimization

The algorithm is aggressively optimized by storing all map information in a series of bytes, and by storing all piece information in a hashmap for quick searching
