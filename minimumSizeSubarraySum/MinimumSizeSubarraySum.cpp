


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min = nums.size();
        int begin=0, end=0;
        int sum = 0;
        bool has = false;
        
        for (int i=0; i<nums.size(); i++, end++){
            
            sum += nums[i];
            
            while (sum >= s && begin <= end) {
                //the 1 is minial length, just return
                if (begin == end) return 1;
                
                if (end-begin+1 < min) {
                    min = end - begin + 1;
                    has = true;
                }
                //move the begin
                sum -= nums[begin++];
            }
 
        }
        
        return has ? min : 0; 
    }
};
