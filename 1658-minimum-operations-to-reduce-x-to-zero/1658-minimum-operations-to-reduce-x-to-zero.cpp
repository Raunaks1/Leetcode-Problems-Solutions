class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int maxi=-1;
        long long total=0;
        for(auto it:nums) total+=it;
        long long target=total-x;
        long long sum=0;
        int l=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>target && l<=r){
              sum-=nums[l];
              l++;
            }
            if(sum==target) maxi=max(maxi,r-l+1);
        }
        return maxi==-1?-1:n-maxi;
    }
};