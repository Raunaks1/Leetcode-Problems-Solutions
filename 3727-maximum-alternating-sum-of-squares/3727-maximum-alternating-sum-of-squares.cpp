class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int &x : nums) x = abs(x);
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(i * 2 < n) ans += nums[i] * nums[i];
            else ans -= nums[i] * nums[i];
        }
        return ans;
    }
};