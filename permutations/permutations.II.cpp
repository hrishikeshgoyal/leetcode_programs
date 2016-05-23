

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > permute(vector<int> &num) {

    vector<vector<int> > vv;
    vv.push_back(num);

    if (num.size() <2){
        return vv;
    }
        
    int pos=0;
    while(pos<num.size()-1){
        int size = vv.size();
        for(int i=0; i<size; i++){
            //sort the array, so that the same number will be together
            sort(vv[i].begin()+pos, vv[i].end());
            //take each number to the first
            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
                //skip the same number 
                if (j>0 && v[j]==v[j-1]){
                    continue;
                }
                int t = v[j]; 
                v[j] = v[pos];
                v[pos] = t;
                vv.push_back(v);
            }
        }
        pos++;
    }
    return vv;
}

void printVector( vector<int>&  pt)
{
    cout << "{ ";
    for(int j=0; j<pt.size(); j++){
        cout << pt[j] << " ";
    }
    cout << "} " << endl;
}


int main(int argc, char** argv)
{
    int n = 3;
    if (argc>1){
       n = atoi(argv[1]); 
    }

    srand(time(NULL));
    vector<int> v;
    for (int i=0; i<n; i++) {
        v.push_back(random()%n+1);
    }

    printVector(v); 
    cout << "-----------------" << endl;


    vector<vector<int> > vv;
    vv = permute(v);
    
    for(int i=0; i<vv.size(); i++) {
        printVector(vv[i]);
    }

    return 0;
}
