class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if(arr[n-1] & 1) dp[n-1][1] = 1;
        else dp[n-1][0] = 1;
        for(int i=n-2; i>=0; i--) {
            arr[i] %= 2;
            if(arr[i]) {
                dp[i][1] = (dp[i+1][0] + 1) % mod;
                dp[i][0] = dp[i+1][1];
            } else {
                dp[i][0] = (1 + dp[i+1][0]) % mod;
                dp[i][1] = dp[i+1][1];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = (ans + dp[i][1] % mod) % mod;
        }
        return ans;
    }
};