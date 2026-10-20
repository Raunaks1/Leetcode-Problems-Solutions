class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool possible = true;
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int mn = sortedNums[start];
                int mx = sortedNums[end];

                for (int j = start; j <= end; j++) {
                    if (nums[j] < mn || nums[j] > mx) {
                        possible = false;
                        break;
                    }
                }

                if (!possible)
                    break;
            }

            if (!possible)
                continue;

            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int drops = 0;

                for (int j = start; j < end; j++) {
                    if (nums[j] > nums[j + 1])
                        drops++;
                }
                if (nums[end] > nums[start])
                    drops++;

                if (drops > 1) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans += k;
        }

        return ans;
    }
};