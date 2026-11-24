class Solution {
public:
    int maxLength(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int res = 2;
        int tim = 1;
        while (start < n && end < n) {
            if (tim == 1) {
                tim *= nums[end];
                end++;
                res = max(res, end - start);
            } else {
                if (gcd(tim, nums[end]) == 1) {
                    tim *= nums[end];
                    end++;
                    res = max(res, end - start);
                } else {
                    tim /= nums[start];
                    start++;
                }
            }
        }
        return res;
    }
};