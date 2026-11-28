class Solution {
public:
    
    int climbStairsRecursive(int n, vector<int> &dp) {
        if (n<=1) return 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = climbStairsRecursive(n-1, dp) + climbStairsRecursive(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int answer = climbStairsRecursive(n,dp);
        return answer;
    }
};