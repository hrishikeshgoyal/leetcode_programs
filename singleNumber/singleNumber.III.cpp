



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allxor = 0;
        for (int n : nums) {
            allxor ^= n;
        }
        int mask = 1;
        while ( (mask & allxor) == 0 ) {
            mask <<= 1;
        }

        int zero = 0;
        int one = 0;
        for (int n : nums) {
            if (n & mask ){
                one ^= n;
            }else {
                zero ^= n;
            }
        }
        
        vector<int> result;
        result.push_back(zero);
        result.push_back(one);
        return result;
    }
};
