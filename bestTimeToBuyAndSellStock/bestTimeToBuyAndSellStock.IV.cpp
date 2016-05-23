

class Solution {
public:

    int maxProfit(int k, vector<int> &prices) {
        int ndays = prices.size();
        
        // error case
        if (ndays<=1) return 0;
        
        // Edge case
        // ---------
        // if the number of transactions is too many, it means we can make 
        // as many transactions as we can, that brings us the problem back to 
        // Best-Time-To-Buy-And-Sell-Stock-II which can be simply solve in O(n) 
        // by using a greedy approach.
        if(k > ndays/2){
            int sum = 0;
            for (int i=1; i<ndays; i++) {
                sum += max(prices[i] - prices[i-1], 0);
            }
            return sum;
        }
        
        //DP solution - O(kn) complexity 
        vector< vector<int> > dp (k+1, vector<int>( ndays+1, 0));
        
        for(int i=1; i<=k; i++) {
            int t = dp[i-1][0] - prices[0];
            for (int j=1; j <= ndays; j++) {
                dp[i][j] = max(dp[i][j-1], t + prices[j-1]);
                if ( j < ndays ) {
                    t = max(t, dp[i-1][j] - prices[j]);
                }
            }
        }
        
        return dp[k][ndays];
        
    }
};
