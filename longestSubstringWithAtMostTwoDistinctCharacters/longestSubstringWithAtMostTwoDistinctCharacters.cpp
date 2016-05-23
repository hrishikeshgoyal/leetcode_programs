



#include <iostream>
#include <string>
using namespace std;


int lengthOfLongestSubstringTwoDistinct(string s) {
    int maxLen = 0;
    int charMap[256] = {0};
    int wordCnt = 0;
    int start = 0;

    for(int i=0; i<s.size(); i++){
        if ( charMap[s[i]]++ == 0 ){
            wordCnt++;
        }
        while (wordCnt>2){
            charMap[s[start]]--;
            if (charMap[s[start]]==0){
                wordCnt--;
            }
            start++;
        }
        maxLen = max(maxLen, i - start + 1);
    }

    return maxLen;
}


int main(int argc, char** argv)
{
    string s = "eceba";
    if (argc>1){
        s = argv[1];
    }
    cout << s << " : " << lengthOfLongestSubstringTwoDistinct(s) << endl;

    return 0;
}
