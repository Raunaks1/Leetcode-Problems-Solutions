class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<long long>> nCr;
    
    long long dfs(vector<int>& nums) {
        if (nums.size() <= 2) return 1;
        
        int root = nums[0];
        vector<int> left, right;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        
        long long leftWays = dfs(left);
        long long rightWays = dfs(right);
        int L = left.size(), R = right.size();
        
        return (((nCr[L+R][L] * leftWays) % MOD) * rightWays) % MOD;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        nCr.assign(n+1, vector<long long>(n+1, 0));
        for (int i = 0; i <= n; i++) {
            nCr[i][0] = nCr[i][i] = 1;
            for (int j = 1; j < i; j++) {
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
            }
        }
        
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};