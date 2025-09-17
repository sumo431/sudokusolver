//Authoe: Sumomo Okada
//Date: December 8 2024
//Sudoku Solver Algorithm

//g++ sudoku_solver.cpp -o storename
//./storename
#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidInitial(const vector<vector<int>>& board) {
    //Check for duplicates in rows and columns
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != 0) {
                int num = board[i][j];
                // When there are duplicate numbers in rows and columns
                for (int k = 0; k < 9; ++k) {
                    if ((k != j && board[i][k] == num) || (k != i && board[k][j] == num)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


// Function to check if a given number is valid within its row, column, or 3x3 box
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) {
            return false;
        }
    }

    //check column
    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // check 3x3 boxes
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

//Back tracking algorithm
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // find empty(0) cell
            if (board[row][col] == 0) {
                // try to put 1 to 9
                for (int num = 1; num <= 9; ++num) {
                    // check the number is vailed
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;//set the number if it is vaild
                        
                        // if it solve sudoku return true
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // Backtracking: Reset the numbers
                        board[row][col] = 0;
                    }
                }
                return false;  // if it doesn't have a way to solve
            }
        }
    }
    return true;  // if all sells are filled
}

int main(){
// 0 is empty cell
/*Steps to Run the Program:
1. Save the Code to a File
Copy the provided C++ code into a text editor 
and save it as sudoku_solver.cpp.

2. Compile the C++ Code
Open a terminal or command prompt 
and navigate to the directory where the code is saved.
Run the following command to compile the code:
g++ sudoku_solver.cpp -o sudoku_solver
This will create an executable file named sudoku_solver.

3. Run the Program
If the compilation is successful, 
run the program using the following command:
./sudoku_solver
The program will attempt to solve 
the Sudoku puzzles and display the solutions. If it cannot solve a particular puzzle, 
it will display a message indicating that it cannot solve it.*/

    vector<vector<int>> board_1 = {
        {0, 0, 6, 7, 4, 5, 1, 2, 0},
        {0, 8, 0, 1, 9, 0, 0, 7, 0},
        {0, 0, 0, 0, 3, 2, 0, 4, 6},
        {6, 0, 0, 0, 8, 4, 0, 0, 0},
        {8, 3, 1, 0, 0, 0, 4, 0, 0},
        {0, 4, 9, 6, 0, 3, 2, 0, 7},
        {0, 0, 5, 0, 7, 8, 0, 9, 0},
        {9, 2, 0, 0, 0, 1, 0, 0, 0},
        {7, 0, 3, 0, 0, 0, 8, 0, 5}
    };

    vector<vector<int>> board_2 = {
        {6, 8, 0, 0, 0, 0, 3, 4, 0},
        {0, 5, 0, 0, 0, 0, 0, 9, 0},
        {0, 0, 0, 4, 2, 0, 0, 0, 8},
        {0, 7, 9, 0, 0, 0, 0, 8, 0},
        {0, 3, 0, 0, 0, 0, 2, 0, 0},
        {0, 6, 2, 5, 9, 8, 0, 0, 0},
        {0, 9, 1, 2, 0, 6, 4, 0, 0},
        {0, 4, 5, 8, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 9, 0, 5, 0}        
    };

    vector<vector<int>> board_3 = {
        {0, 8, 0, 2, 0, 0, 0, 1, 0},
        {0, 6, 0, 0, 0, 3, 0, 0, 0},
        {3, 0, 1, 0, 7, 0, 9, 0, 0},
        {4, 0, 2, 0, 0, 8, 0, 9, 0},
        {0, 0, 0, 5, 0, 0, 7, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 3, 0, 0, 4, 0, 2, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 4},
        {6, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    vector<vector<int>> board_4 = {
        {7, 0, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 5, 0, 0, 9, 2, 0, 1},
        {0, 9, 0, 4, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 4, 9, 0, 5},
        {6, 0, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 1, 0, 3, 0},
        {2, 0, 0, 6, 0, 0, 1, 0, 8},
        {0, 0, 8, 0, 0, 0, 0, 4, 0}
    };

 vector<vector<int>> board_5 = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0}
    };

 vector<vector<int>> board_6 = {
        {9, 9, 9, 9, 9, 9, 9, 9, 9},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}        
    };
 vector<vector<int>> board_7 = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
 

    // solve sudoku
    if (isValidInitial(board_1) && solveSudoku(board_1)) {
        cout << "find the solve about board_1" << endl;
        printBoard(board_1);  // show the result
    } else {
        cout << "It cannot solve about board_1" << endl;
    }
    
    if (isValidInitial(board_2) && solveSudoku(board_2)) {
        cout << "find the solve about board_2" << endl;
        printBoard(board_2);  // show the result
    } else {
        cout << "It cannot solve about board_2" << endl;
    }

    if (isValidInitial(board_3) && solveSudoku(board_3)) {
        cout << "find the solve about board_3" << endl;
        printBoard(board_3);  // show the result
    } else {
        cout << "It cannot solve about board_3" << endl;
    }
    
    if (isValidInitial(board_4) && solveSudoku(board_4)) {
        cout << "find the solve about board_4" << endl;
        printBoard(board_4);  // show the result
    } else {
        cout << "It cannot solve about board_4" << endl;
    }

    if (isValidInitial(board_5) && solveSudoku(board_5)) {
        cout << "find the solve about board_5" << endl;
        printBoard(board_5);  // show the result
    } else {
        cout << "It cannot solve about board_5" << endl;
    }
    
    if (isValidInitial(board_6) && solveSudoku(board_6)) {
        cout << "find the solve about board_6" << endl;
        printBoard(board_6);  // show the result
    } else {
        cout << "It cannot solve about board_6" << endl;
    }

    if (isValidInitial(board_7) && solveSudoku(board_7)) {
        cout << "find the solve about board_7" << endl;
        printBoard(board_7);  // show the result
    } else {
        cout << "It cannot solve about board_7" << endl;
    }

    return 0;
}