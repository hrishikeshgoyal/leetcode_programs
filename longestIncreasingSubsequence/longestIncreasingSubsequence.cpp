



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        int maxLen = 0;
        vector<int> dp(len, 1);
        
        for (int i=0; i<len; i++) {
            for(int j=0; j<i; j++) {
                if ( nums[j] < nums[i] ) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};


class Solution {
public:
    
    vector <int> longest_LIS;
    int lengthOfLIS(vector<int>& nums) {
        int answer = 0;
        if(nums.size())
        {   
            longest_LIS.push_back(1);
            answer = 1;
            for(int i = 1; i < nums.size(); i++)
            {
                int maximum = 1;
                for(int j = 0; j < longest_LIS.size(); j++)
                    if(nums[i] > nums[j])
                        maximum = max(maximum, longest_LIS[j] + 1);
                longest_LIS.push_back(maximum);
                answer = max(maximum, answer);
            }
        }
        return answer;
    }
    vector <int> longest_subsequence; // the LIS
    vector <int> nums;
    int binary_search(int number)
    {
        int start = 0, end = longest_subsequence.size() - 1;
        if(start == end)
        {
            if(number > longest_subsequence[start])
                return start + 1;
            else
                return start;
        }
        while(start < end)
        {
            if(start == end - 1)
            {
                if(number > longest_subsequence[start] && number <= longest_subsequence[end])
                    return end;
                else if(number <= longest_subsequence[start])
                    return start;
                else
                    return end + 1;
            }
            int middle = (start + end + 1) / 2;
            if(longest_subsequence[middle] < number)
                start = middle;
            else
                end = middle;
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int answer = 0;
        if(nums.size())
        {   
            answer = 1;
            longest_subsequence.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++)
            {
                int position = binary_search(nums[i]);
                if(position == longest_subsequence.size())
                    longest_subsequence.push_back(nums[i]);
                else
                    longest_subsequence[position] = nums[i];
                answer = max(answer, position + 1);
            }
        }
        return answer;
    }
};
