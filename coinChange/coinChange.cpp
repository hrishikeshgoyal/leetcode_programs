
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int sol[amount + 1];
        sol[0] = 0;
        for(int i = 1; i <= amount; i++)
            sol[i] = amount + 1;
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
                sol[j] = min(sol[j], sol[j - coins[i]] + 1);
        }
        if(sol[amount] != amount + 1)
            return sol[amount];
        else
            return -1;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = amount +1;
        vector<int> dp(amount+1, MAX);
        dp[0]=0;
        
        for(int i=1; i<=amount; i++) {
            for (int j=0; j<coins.size(); j++){
                if (i >= coins[j]) {
                    dp[i] = min( dp[i], dp[i-coins[j]] + 1 );
                }
            }
        }

        return dp[amount]==MAX ? -1 : dp[amount];
    }
};
