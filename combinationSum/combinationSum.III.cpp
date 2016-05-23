
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int start, int num, int target, 
                          vector<int>& solution, vector< vector<int> >& results) {
    if (target < 0|| solution.size() > num){
        return;
    }
    if (target == 0 && solution.size()==num){
        results.push_back(solution);
        return;
    }
    for (int i=start; i<candidates.size(); i++){
        solution.push_back(candidates[i]);
        combinationSumHelper(candidates, i+1, num, target-candidates[i], solution, results);
        solution.pop_back();
    }
    
}

vector< vector<int> > combinationSum3(int k, int n) {
    vector<int> v;
    for (int i=1; i<=9; i++){
        v.push_back(i);
    }

    vector< vector<int> > result;
    vector<int> solution;

    combinationSumHelper(v, 0, k, n, solution, result);    

    return result;

}

void PrintResults(int k, int n, vector< vector<int> >& results) {
    cout << "k=" << k << ", n=" << n << "\t";
    for (int i=0; i<results.size(); i++){
        cout << "[";
        for (int j=0; j<results[i].size(); j++){
            cout << results[i][j] << (j!=results[i].size()-1 ? ",":"]") ;
        }
        cout << ( i!=results.size()-1 ? ", " : "" );
    } 
    cout << endl;
}

int main(int argc, char** argv) 
{
    int k = 3, n =9;
    if (argc > 2){
        k = atoi(argv[1]);
        n = atoi(argv[2]);
    } 

    vector< vector<int> > results;
    results = combinationSum3(k, n);

    PrintResults(k,n, results);
    return 0;
}
