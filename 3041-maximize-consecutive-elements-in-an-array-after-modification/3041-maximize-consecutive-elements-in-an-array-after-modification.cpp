class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        sort(nums.begin(), nums.end());
        int maxl = 1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]+1){
                dp[i][0] = 1 + dp[i-1][0];
                dp[i][1] = 1 + dp[i-1][1];
            }else if(nums[i]==nums[i-1]+2){
                dp[i][0] = 1 + dp[i-1][1];
            }else if(nums[i]==nums[i-1]){
                dp[i][1] = 1 + dp[i-1][0];
                dp[i][0] = dp[i-1][0];
            }
            maxl = max(maxl, max(dp[i][0], dp[i][1]));
        }
        return maxl;
    }
};