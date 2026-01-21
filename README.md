# Sudoku Solver (C++)

## Overview
This project is a Sudoku Solver implemented in C++ using a classic backtracking algorithm.
The program takes predefined 9×9 Sudoku boards, validates their initial state, and attempts to solve them.
If a solution exists, the completed board is printed to the console. Otherwise, the program reports that the puzzle cannot be solved.

### This project demonstrates:
Recursive backtracking
Constraint checking (row, column, 3×3 box)
Use of vector<vector<int>> for 2D board representation
Basic input validation

## Features
Solves standard 9×9 Sudoku puzzles
Detects invalid initial boards (duplicate numbers in rows or columns)
Uses 0 to represent empty cells
Handles multiple test boards in a single execution
Clearly reports whether each board is solvable

## Algorithm
### The solver uses a backtracking approach:
1. Find the next empty cell (value 0)
2. Try numbers from 1 to 9
3. Check if the number is valid:
・　Not already in the same row
・　Not already in the same column
・  Not already in the corresponding 3×3 subgrid
4. Recursively attempt to solve the rest of the board
5. If a conflict occurs, reset the cell and backtrack
