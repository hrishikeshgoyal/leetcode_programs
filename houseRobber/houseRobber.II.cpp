


class Solution {
public:
    int orginal_rob(vector<int> &money, int start, int end) {
        int n2=0; 
        int n1=0; 
        
        for (int i=start; i<end; i++){
            int current = max(n1, n2 + money[i]);
            n2 = n1;
            n1 = current;
        }
        return n1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        switch (n) {
            case 0:
                return 0;
            case 1:
                return nums[0];
            case 2:
                return max(nums[0], nums[1]);
            default:
                int m1 = orginal_rob(nums, 0, n-1);
                int m2 = orginal_rob(nums, 1, n);
                
                return max(m1, m2);
        }
    }
};
