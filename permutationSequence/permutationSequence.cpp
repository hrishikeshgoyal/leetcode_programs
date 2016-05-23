

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



void nextPermutation(vector<int>& num); 

string getPermutation_0(int n, int k) {
    vector<int> num;
    int total = 1;
    for(int i=1; i<=n; i++){
        num.push_back(i);
        total *= i;
    }

    //invalid k;
    if( total < k ) {
        return "";
    }
    int group = total / n;
    int idx = (k-1) / group;
    int nn = num[idx];
    num.erase(num.begin()+idx);
    num.insert(num.begin(), nn);

    int offset = (k-1) % group;
    for(int i=0; i<offset; i++) {
        nextPermutation(num);
    }

    //string result;
    stringstream ss;
    for(int i=0; i<n; i++){
        ss << num[i];
    }

    return ss.str();
}

