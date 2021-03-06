

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;



bool isOneEditDistance(string s, string t) {
    int len_s = s.size();
    int len_t = t.size();
    if (len_s==0) return len_t==1;
    if (len_t==0) return len_s==1;


    switch (abs(len_s-len_t)) {
        case 0:
            {
                //if these two strings have same length.
                //it means - we cannot use `add` or `delete` edit methods, just use the `replace` method
                //So, just simply count the different char(s).
                int cnt=0;
                for (int i=0; i<len_s; i++){
                    if(s[i]!=t[i]){
                        cnt++;
                        if(cnt>1) return false;
                    }
                }
                return cnt==1;
            }

        case 1:
            {
                //if these two strings' length just have ONE difference.
                //it means - we only can use `delete` edit method to delete one char in longer string.
                //So, just remove one char in longer string, and check it whether equal to shorter string.
                string& ss = (len_s > len_t)? s : t;
                string& tt = (len_s < len_t)? s : t;
                for(int i=0; i<ss.size(); i++){
                    string tmp = ss;
                    if (ss.erase(i,1) == tt) {
                        return true;
                    }
                }
                return false;

            }

        default:
            return false;
    }

    return false;
}

int main(int argc, char** argv)
{
    string s="ab", t="acb";
    if(argc>2){
        s = argv[1];
        t = argv[2];
    }
    cout << "s = \"" << s << "\"  t = \"" << t << "\"  : " << (isOneEditDistance(s,t) ? "true" : "false") << endl;
    return 0;
}
