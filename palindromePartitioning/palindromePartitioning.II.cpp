

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isPalindrome(string &s, int start, int end);
void minCutHelper(string &s, int start, int steps, int& min );
int minCutHelper(string &s, int steps, int& minSteps );
int minCut_DP(string& s); 

int minCut(string s) {
    #define INT_MAX 2147483647
    if(s.size()<=1) return 0;

    int min = INT_MAX;
    
    //minCutHelper(s, 0, 0, min);
    //return min-1;

    //int m =  minCutHelper(s, 0, min);
    //return m-1;

    return minCut_DP(s);
}



int minCut_DP(string& s) {
    //res[] is for minimal cut DP
    vector<int>res(s.size(),0);
    //mp[][] is for palindrome checking DP
    bool mp[s.size()][s.size()];

    //construct the pailndrome checking matrix
    //  1) matrix[i][j] = true;     if (i==j)                   -- only one char
    //  2) matrix[i][j] = true;     if (i==j+1) && s[i]==s[j]   -- only two chars
    //  3) matrix[i][j] = matrix[i+1][j-1];   if s[i]==s[j]     -- more than two chars
    //
    //note:  1) and 2) can be combined together
    for (int i=s.size()-1;i>=0;i--){
        for (int j=i;j<s.size();j++){
            if ((s[i]==s[j]) && (j-i<2 || mp[i+1][j-1])){
                mp[i][j]=true;
            }else{
                mp[i][j]=false;
            }
        }
    }
    //minimal cut dp
    for (int i=0;i<s.size();i++){
        //if s[0..i] is palindrome, then no need to cut
        if (mp[0][i] == true){
            res[i]=0;
        }else{
            // if s[0..i] isn't palindrome 
            // then, for each 0 to i, find a "j" which meets two conditions:
            //    a) s[j+1..i] are palindrome.
            //    b) res[j]+1 is minimal   
            int ms = s.size();
            for (int j=0; j<i; j++){
                if (mp[j+1][i] && ms>res[j]+1 ) {
                    ms=res[j]+1;
                } 
            }
            res[i]=ms;
        }
    }
    return res[s.size()-1];
}

int minCutHelper(string &s, int steps, int& minSteps ) {

    // remove the steps if it's greater than minSteps 
    if (minSteps <= steps) {
        return -2;
    }
    // adding the cache to remove the duplicated calculation
    static map<string, int> cache;
    if ( cache.find(s)!=cache.end() ){
        if (s.size()>0)
            cout << s << ":" << cache[s] << endl;
        return cache[s];
    }
    if (s.size()==0) {
        if (minSteps > steps){
            minSteps = steps;
        }
        cache[s] = 0;
        return 0;
    }


    int min = INT_MAX;
    string subs;
    int m; 
    for( int i=s.size()-1; i>=0; i-- ) {
        //remove the steps which greater than minSteps
        if ( i < s.size()-1 && minSteps - steps <= 1) {
            break;
        }
        if ( isPalindrome(s, 0, i) ){
            //if ( i == s.size()-1 ) {
            //    m = 1;
            //}else{
            subs = s.substr(i+1, s.size()-i-1);
            m = minCutHelper(subs, steps+1, minSteps) + 1;
            //}
            if (m < 0) continue;
            cache[subs] = m-1;
            if (min > m ){
                min = m;
            }
        }
    }
    return min;
}


void minCutHelper(string &s, int start, int steps, int& min ) {

    if (start == s.size()) {
        if (steps < min) {
            min = steps;
            return;
        }
    }

    //GREED: find the biggest palindrome first
    for(int i=s.size()-1; i>=start; i--){
        //cut unnecessary DFS 
        if ( min > steps && isPalindrome(s, start, i)) {
            minCutHelper(s, i+1, steps+1, min );
        }
    }
}

bool isPalindrome(string &s, int start, int end)  {  

    while(start < end)  {  
        if(s[start] != s[end]) { 

            return false;  
        }
        start++; end--;  
    }  

    return true;  
}  


int main(int argc, char** argv)
{
    string s("aab");
    if ( argc > 1 ){
        s = argv[1];
    }

    cout << s << " : " << minCut(s) << endl;

}
