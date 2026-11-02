class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());
        if(n==1){
            return 0;
        }
        if(n == 2){
            return abs(nums[0]-nums[1]);
        }
        int median = 0;
        if(n%2 == 0){
            median = (vec[n/2]+vec[n/2-1])/2;
        }
        else{
            median = vec[n/2];
        }
        int ans = 0;
        for(int elem:nums){
            ans += abs(elem-median);
        }
        return ans;
    }
};