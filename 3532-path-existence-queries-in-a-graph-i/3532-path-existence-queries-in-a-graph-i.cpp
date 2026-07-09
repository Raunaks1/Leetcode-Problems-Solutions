class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<bool> ans(queries.size(), false);
         vector<int> idx(nums.size(),0);
        int id = 0;
        for(int i=1;i<nums.size();i++){
            if((nums[i]-nums[i-1])>maxDiff)id++;
            idx[i]=id;
        }
        for(int i =0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(idx[x]==idx[y])ans[i]=true;
        }
        return ans;
    }
};