

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isScramble_recursion(string s1, string s2) {

    if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2){
        return true;
    } 
    string ss1 = s1;
    string ss2 = s2;
    sort(ss1.begin(), ss1.end()); 
    sort(ss2.begin(), ss2.end()); 
    if (ss1 != ss2 ) {
        return false;
    }

    for (int i=1; i<s1.size(); i++) {
        if ( isScramble_recursion(s1.substr(0,i), s2.substr(0,i)) && 
             isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)) ) {
            return true;
        }
        if ( isScramble_recursion(s1.substr(0,i), s2.substr(s2.size()-i, i)) && 
             isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)) ) {
            return true;
        }
    }

    return false;
    
}

bool isScramble_dp(string s1, string s2) {

    if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2){
        return true;
    }

    const int len = s1.size();    
    
    // dp[len+1][len][len]
    vector< vector< vector<bool> > > dp(len+1, vector< vector<bool> >(len, vector<bool>(len) ) );
   
    // ignor the k=0, just for readable code.

    // initialization k=1
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++) {
            dp[1][i][j] = (s1[i] == s2[j]);
        }
    } 
    // start from k=2 to len, O(n^4) loop. 
    for (int k=2; k<=len; k++){
        for (int i=0; i<len-k+1; i++){
            for (int j=0; j<len-k+1; j++){
                dp[k][i][j] = false;
                for (int divk = 1; divk < k && dp[k][i][j]==false; divk++){
                    dp[k][i][j] = ( dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ) ||
                                  ( dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j] );
                }
            }
        }
    }
    
    return dp[len][0][0];
}

bool isScramble(string s1, string s2) {

    srand(time(0));

    if (random()%2) {
        cout << "---- recursion ---" << endl;
        return isScramble_recursion(s1, s2);
    }
    cout << "---- dynamic programming ---" << endl;
    return isScramble_dp(s1, s2);
}

int main(int argc, char** argv)
{
    string s1="great", s2="rgtae";
    if (argc>2){
        s1 = argv[1];
        s2 = argv[2];
    }
    cout << s1 << ", " << s2 << endl;
    cout << isScramble(s1, s2) << endl;
    return 0;
}
