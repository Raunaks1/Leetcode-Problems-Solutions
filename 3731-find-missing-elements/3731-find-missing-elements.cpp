class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])==1){
                continue;
            }
            else{
                int curr=nums[i-1]+1;
                while(curr!=nums[i]){
                    ans.push_back(curr++);
                }
            }
        }
        return ans;
    }
};