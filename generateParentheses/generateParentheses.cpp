

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


void generator(vector<string>& result, int left, int right, string s);
vector<string> generateParenthesis(int n) {
    
    vector<string> result;
    string s;
    generator(result, n, n, s);
    return result;
}

void generator(vector<string>& result, int left, int right, string s){
    if (left==0 && right==0){
        result.push_back(s);
        return;
    }
    if (left>0){
        generator(result, left-1, right, s+'(');
    }
    if (right>0 && right>left){
        generator(result, left, right-1, s+')');
    }
}
    
void printResult(vector<string>& result)
{
    for(int i=0; i<result.size(); i++){
        cout << result[i] <<endl;
    }
}

int main(int argc, char** argv) 
{
    int n=3;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector<string> r = generateParenthesis(n);
    printResult(r);
    return 0;
}
