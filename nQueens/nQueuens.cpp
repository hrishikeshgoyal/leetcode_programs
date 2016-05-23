

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector< vector<string> > solveNQueens(int n); 
void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result); 
bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn); 


vector< vector<string> > solveNQueens(int n) {
    vector< vector<string> > result;
    vector<int> solution(n);

    solveNQueensRecursive(n, 0, solution, result);

    return result;    
}

void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result) {
    //if no more row need to do, shape the result
    if (currentRow == n){
        vector<string> s;
        for (int row = 0; row < n; row++) {
            string sRow;
            for (int col = 0; col < n; col++) {
                sRow = sRow + (solution[row] == col ? "Q" :"." );
            }
            s.push_back(sRow);
        }
        result.push_back(s);
        return;
    }

    //for each column
    for (int col = 0; col < n; col++) {
        //if the current column is valid
        if (isValid(col, currentRow, solution) ) {
            //place the Queue
            solution[currentRow] = col;
            //recursively put the Queen in next row
            solveNQueensRecursive(n, currentRow+1, solution, result);
        }
    } 
}

bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn) {

    for(int i=0; i<attemptedRow; i++) {
        if (attemptedColumn == queenInColumn[i]  || 
            abs(attemptedColumn - queenInColumn[i]) == abs(attemptedRow - i)) {
            return false;
        } 
    }
    return true;
}





void printMatrix(vector< vector<string> >& matrix ){
    for (int i = 0; i < matrix.size(); i++) {
        cout << "-----------" << endl;
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << endl;
        }
    }
}


int main(int argc, char** argv)
{
    int n = 8;
    if (argc>1){
        n = atoi(argv[1]);
    }
    
    vector< vector<string> > result = solveNQueens(n);
    printMatrix(result);
    
    return 0;
}

