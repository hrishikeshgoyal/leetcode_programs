

#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;


void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}
void reverse(string &s, int begin, int end) {
    while(begin < end) {
        swap(s[begin++], s[end--]);
    }
}
void reverseWords(string &s) {

    if (s.size()<=1) return;

    // reverse the whole string
    reverse(s, 0, s.size()-1);

    // reverse the each word
    for ( int begin=0, i=0; i<=s.size(); i++ ) {
        if ( isblank(s[i]) || s[i] == '\0') {
            reverse(s, begin, i-1);
            begin = i+1;
        }
    }
}


int main(int argc, char** argv)
{
    string s = "the sky is blue";
    if ( argc > 1 ) {
        s = argv[1];
    }
    
    cout << s << endl;
    reverseWords(s);
    cout << s << endl;
    
}
