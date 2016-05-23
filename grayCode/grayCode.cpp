

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode01(int n) {
    vector<int> v;
    //n = 1<<n;
    
    int x =0;   
    v.push_back(x); 
    for(int i=0; i<n; i++){
        int len = v.size();
        for (int j=0; j<len; j++){
            x = v[j]<<1;
            if (j%2==0){
                v.push_back(x);
                v.push_back(x+1);
            }else{
                v.push_back(x+1);
                v.push_back(x);
            }
        }
        v.erase(v.begin(), v.begin()+len);
    }
     
    return v;
}

vector<int> grayCode02(int n) {
    vector<int> ret;   
    int size = 1 << n;   
    for(int i = 0; i < size; ++i) {
        ret.push_back((i >> 1)^i);   
    }
    return ret;   
}

vector<int> grayCode(int n) {
    srand(time(0));
    if (rand()%2){
        return grayCode01(n);
    }
    return grayCode02(n);
}

void printBits(int n, int len){
    for(int i=len-1; i>=0; i--) {
        if (n & (1<<i)) {
            printf("1");
        }else{
            printf("0");
        }
    }
}

void printVector(vector<int>& v, int bit_len)
{
    vector<int>::iterator it;

    for(it=v.begin(); it!=v.end(); ++it){
        //bitset<bit_len> bin(*it);
        printBits(*it, bit_len);
        cout <<  " ";
        //cout << *it <<  " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int n = 2;
    if (argc>1){
        n = atoi(argv[1]); 
    }
    vector<int> v = grayCode(n);
    printVector(v, n);
    return 0;
}
