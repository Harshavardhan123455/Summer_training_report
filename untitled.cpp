#include <bits/stdc++.h>
using namespace std;

#define N 9


bool isPossible(int grid[][N], int row, int col, int num){
    //Safe in row
    for (int i = 0; i < N; i++){
        if (grid[row][i] == num){
            return false;
        }
    }

    //Safe in column
    for (int i = 0; i < N; i++){
        if (grid[i][col] == num){
            return false;
        }
    }

    //Safe in block
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + rowFactor][j + colFactor] == num){
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuHelper(int grid[][N], int row, int col){
	if (row == N){
        return true;
    }
    
    if (col == N){
        return solveSudokuHelper(grid, row + 1, 0);
    }
    
    if (grid[row][col] != 0){
        return solveSudokuHelper(grid, row, col + 1);
    }
    
    for (int i = 1; i <= 9; i++){
        if (isPossible(grid, row, col, i)){
            grid[row][col] = i;
            if (solveSudokuHelper(grid, row, col + 1)){
                return true;
            }
        }
        grid[row][col] = 0;
    }
    return false;
}

bool solveSudoku(int grid[][N]){
    return solveSudokuHelper(grid, 0, 0);
}

int main(){
    int grid[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    if(solveSudoku(grid)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    

    return 0;
}