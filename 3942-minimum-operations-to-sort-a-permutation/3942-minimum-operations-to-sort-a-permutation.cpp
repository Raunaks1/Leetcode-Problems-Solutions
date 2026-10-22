class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int diff = -1;
        for(int i = 1; i < n; ++i){
            if(nums[i] - nums[i - 1] != 1){
                if(diff != -1){
                    diff = -2;
                    break;
                }
                diff = i;
            }
        }
        if(diff == -1) return 0;
        if(diff != -2) return min(diff , n - diff + 2);
        diff = -1;
        reverse(nums.begin() , nums.end());
        for(int i = 1; i < n; ++i){
            if(nums[i] - nums[i - 1] != 1){
                if(diff != -1) return -1;
                diff = i;
            }
        }
        if(diff == -1) return 1;
        return 1 + min(diff, n - diff);
    }
};