


class Solution {
public:

    int numSquares(int n) {
        return numSquares_dp_opt(n); //12ms
        return numSquares_dp(n); //232ms
    }
    
    int numSquares_dp(int n) {
        if ( n <=0 ) return 0;
        
        int *dp = new int[n+1];
        dp[0] = 0;
        
        for (int i=1; i<=n; i++ ) {
            int m = n;
            for (int j=1; i-j*j >= 0; j++) {
                m = min (m, dp[i-j*j] + 1);
            }
            dp[i] = m;
        }
    
        return dp[n];
        delete [] dp;
    }
    
    //using cache to optimize the dp algorithm
    int numSquares_dp_opt(int n) {
        if ( n <=0 ) return 0;
        
        static vector<int> dp(1, 0);
        if (dp.size() >= (n+1) ) return dp[n];
        
        for (int i=dp.size(); i<=n; i++ ) {
            int m = n;
            for (int j=1; i-j*j >= 0; j++) {
                m = min (m, dp[i-j*j] + 1);
            }
            dp.push_back(m);
        }
    
        return dp[n];
    }
};

