

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool wordBreak(string s, set<string> &dict) {

    //using an array to mark subarray from 0 to i can be broken or not
    vector<bool> v(s.size(),false);

    for(int i=0; i<s.size(); i++){
        //check the substring from 0 to i is int dict or not
        string w = s.substr(0,i+1);
        v[i] = (dict.find(w)!=dict.end());

        //if it is, then use greedy algorithm
        if (v[i]) continue;

        //if it is not, then break it to check
        for(int j=0; j<i; j++){
            //if the substring from 0 to j can be borken, then check the substring from j to i
            if (v[j]==true){
                w = s.substr(j+1, i-j);
                v[i] = (dict.find(w)!=dict.end());
                if (v[i]) break;
            }
        }
    }
    return v.size() ? v[v.size()-1] : false;
}


int main()
{
    string s; 
    set<string> dict;

    s = "a";
    dict.insert("a");
    cout << wordBreak(s, dict) << endl;
    
    dict.clear();
    s = "dogs";
    string d[]={"dog","s","gs"};
    dict.insert(d, d+3);
    cout << wordBreak(s, dict) << endl;

    return 0;
}
