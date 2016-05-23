
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int numDistinct1(string S, string T) {
    vector< vector<int> > m(T.size()+1, vector<int>(S.size()+1));
    
    for (int i=0; i<m.size(); i++){
        for (int j=0; j<m[i].size(); j++){

            if (i==0){
                m[i][j] = 1;
                continue;
            }
            if ( i>j ) {
                m[i][j] = 0;
                continue;
            }
            if (S[j-1] == T[i-1]){
                m[i][j] = m[i][j-1] + m[i-1][j-1];
            } else {
                m[i][j] = m[i][j-1] ;
            }
        }
    }
    return m[T.size()][S.size()];
}


int numDistinct2(string S, string T) {

    map< char, vector<int> > pos_map;
    int len = T.size();
    vector<int> numOfSubSeq(len+1);
    numOfSubSeq[0] = 1;

    for (int i=len-1; i>=0; i--){
        pos_map[T[i]].push_back(i);
    }
    
    for (int i=0; i<S.size(); i++){
        char ch = S[i];
        if ( pos_map.find(ch) != pos_map.end() ) {
            for (int j=0; j<pos_map[ch].size(); j++) {
                int pos = pos_map[ch][j];
                numOfSubSeq[pos+1] += numOfSubSeq[pos];
            } 
        }
    }

    return numOfSubSeq[len];
}


int numDistinct(string S, string T) {
    srand(time(0));
    if (rand()%2){
        cout << "-----Dynamic Programming Method One-----" << endl;
        return numDistinct1(S,T);
    }
    cout << "-----Dynamic Programming Method Two-----" << endl;
    return numDistinct2(S,T);
}


int main(int argc, char** argv)
{
    string s = "rabbbit";
    string t = "rabbit";
    if (argc>2){
        s = argv[1];
        t = argv[2];
    }
    cout << "S=\"" << s << "\"  T=\"" << t << "\"" << endl;
    cout << "numDistinct = " << numDistinct(s, t) << endl;
    return 0;
}
