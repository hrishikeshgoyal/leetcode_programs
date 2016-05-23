


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size()) return false;
        
        const int MAXCHAR = 256;
        char maps[MAXCHAR]={0}, mapt[MAXCHAR]={0};
        //memset(maps, 0, sizeof(maps));
        //memset(mapt, 0, sizeof(mapt));
        
        for(int i=0; i<s.size(); i++){
            if(maps[s[i]] == 0 && mapt[t[i]] == 0){
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
                continue;
            }
            if(maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};
