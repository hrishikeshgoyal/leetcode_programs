

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for std::reverse
using namespace std;

void reverseWords(string &s) {
    
    bool wordStart = false;
    vector<string> v;
    
    const char *pHead =s.c_str();
    const char *pStr, *pBegin, *pEnd;
   
    for (pStr=pHead; *pStr!='\0'; pStr++) {
        if (!isspace(*pStr) && wordStart == false){
            wordStart = true;
            pBegin = pStr;
            continue;
        }
        
        if(isspace(*pStr) && wordStart==true){
            wordStart=false;
            pEnd = pStr;
            v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
        }
        
    }

    if (wordStart==true){
        pEnd = pStr;
        v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
    }
    
    if (v.size()>0){
        s.clear();
        char space=' ';
        vector<string>::iterator it;
        for (it=v.begin(); it!=v.end(); ++it) {
            s = s + *it;
            s.push_back(space);
        }
        s.erase(s.end()-1);
    }else{
            s.clear();
    }
    cout << "[" << s << "]" <<endl;
}

void reverseWords2(string &s) {
    if (s.length() == 0) return;

    string result = "";
    if (s[s.length()-1] == ' ') {
        int last = s.find_last_not_of(' ') + 1;
        s.erase(last, s.length() - last);
    }

    int first = s.find_first_not_of(' ', 0);
    while (first != string::npos) {
        int wend = s.find(' ', first);  // word end
        if (wend == string::npos) wend = s.length();

        string word = s.substr(first, wend - first);
        reverse(word.begin(), word.end());
        result += word;

        first = s.find_first_not_of(' ', wend); // next word
        if (first == string::npos) break;

        result += ' ';
    }
    reverse(result.begin(), result.end());
    s.swap(result);
}


void reverse(char *b, char *e) {
    for (--e; e - b > 0; b++, e--) {
        char t = *b;
        *b = *e;
        *e = t;
    }
}

void reverseWords(char *s) {
    char *p = s, *ws = NULL, *last = s;

    while (*p && *p == ' ') p++; // skip leading space
    ws = p;

    for ( ; *p; p++) {
        while (*p && *p != ' ') p++; // find word end

        reverse(ws, p);
        strncpy(last, ws, p-ws);
        last += (p-ws);

        while (*p && *p == ' ') p++; // for next word
        ws = p;

        if (*p == '\0') break;
        *last++ = ' ';
    }
    reverse(s, last);
    *last = '\0';
}

void test() {
#define TEST(str) do {       \
    char* s = strdup(str);   \
    printf("\"%s\" => ", s); \
    reverseWords(s);         \
    printf("\"%s\"\n\n", s); \
    free(s);                 \
    } while (0)

    TEST("  the    blue   sky  is blue    ");
    TEST("  ");
}


main()
{
   string s;
   reverseWords(s);
   s=" ";
   reverseWords(s);
   s="1 ";
   reverseWords(s);
   s="love";
   reverseWords(s);
   s="i love cpp";
   reverseWords(s);

   test();
}    
