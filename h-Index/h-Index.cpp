



#include <algorithm>
class Solution {
public:
    int hIndex(vector<int>& citations) {
        return hIndex02(citations);
        return hIndex01(citations);
    }
    int hIndex01(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for(int i = citations.size() - 1; i >= 0; i--)
            if(citations[i] >= citations.size() - i && (i - 1 < 0 || citations[i - 1] <= citations.size() - i))
                h_index = citations.size() - i;
        return h_index;
    }

    // same solution but a bit different implemtation
    int hIndex02(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i=0; i<n; i++){
            if (citations[i] >= n-i){
                return n-i;
            }
        }
        return 0;
    }

};
