

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#define INT_MAX      2147483647

string minWindow(string S, string T) {
    string win;
    if (S.size()<=0 || T.size()<=0 || T.size() > S.size()) return win;
    const int MAX_CHARS = 256;
    int f[MAX_CHARS], m[MAX_CHARS];
    
    const int NOT_EXISTED   = -1;
    const int NOT_FOUND     =  0;
    memset(m, NOT_EXISTED, sizeof(m));
    memset(f, NOT_EXISTED, sizeof(f));

    for(int i=0; i<T.size(); i++) {
        m[T[i]]==NOT_EXISTED ? m[T[i]]=1 : m[T[i]]++ ; 
        f[T[i]] = NOT_FOUND; 
    }

    int start =-1;
    int winSize = INT_MAX;
    int letterFound = 0;
    int begin = 0;
    for(int i=0; i<S.size(); i++) {
            if (f[ch] <= m[ch]) {
                letterFound++;
            }
            if ( letterFound >= T.size() ) {
                while ( f[S[begin]] == NOT_EXISTED || f[S[begin]] > m[S[begin]] ) { 
                    if ( f[S[begin]] > m[S[begin]] ) {
                        f[S[begin]]--;
                    }   
                    begin++;
                }
