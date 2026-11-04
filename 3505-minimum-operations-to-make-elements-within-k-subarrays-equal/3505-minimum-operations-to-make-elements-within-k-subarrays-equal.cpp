class Solution {
    public:
        long long minOperations(vector<int>& nums, int x, int k) {
           auto multiLeftSet = multiset<int>();
           auto multiRightSet = multiset<int>();
            
            auto dp = vector<vector<long long>>(nums.size() + 1, vector<long long>(k + 1, 0x7ffffffffff));
            dp[0][0] = 0;
            long long leftSum = 0, rightSum = 0;
            
            for (int i = 0; i < nums.size(); ++i) {
                if (i >= x) {
                    auto iter = multiLeftSet.find(nums[i - x]);
                    if (iter != multiLeftSet.end()) {
                        leftSum -= nums[i - x];
                        multiLeftSet.erase(iter);   
                    } else {
                        rightSum -= nums[i - x];
                        multiRightSet.erase(multiRightSet.find(nums[i - x]));
                    }
                }

                if (multiRightSet.size() && nums[i] >= *multiRightSet.begin()) {
                    rightSum += nums[i];
                    multiRightSet.insert(nums[i]);
                } else {
                    leftSum += nums[i];
                    multiLeftSet.insert(nums[i]);
                }


                while (!(multiLeftSet.size() - 1 == multiRightSet.size() || multiLeftSet.size() == multiRightSet.size())) {
                    if (multiLeftSet.size() > multiRightSet.size()) {
                        auto iter = --multiLeftSet.end();
                        auto maxValue = *iter;
                        
                        multiLeftSet.erase(iter);
                        leftSum -= maxValue;
                        
                        multiRightSet.insert(maxValue);
                        rightSum += maxValue;
                    } else {
                        auto iter = multiRightSet.begin();
                        auto minValue = *iter;
                        multiRightSet.erase(iter);
                        rightSum -= minValue;
                        
                        multiLeftSet.insert(minValue);
                        leftSum += minValue;
                    }
                }

                long long median = *(--multiLeftSet.end());
                if ((multiLeftSet.size() + multiRightSet.size()) % 2 == 0) {
                    median = *(--multiLeftSet.end());
                }

                long long minSum = median * multiLeftSet.size() - leftSum + rightSum - median * multiRightSet.size();
                for (int j = 0; j <= k; ++j) {
                    dp[i + 1][j] = dp[i][j];
                    if (j != 0 && i >= x - 1) {
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1 - x][j - 1] + minSum);
                    }
                }
            }

            return dp[nums.size()][k];
        }
};
