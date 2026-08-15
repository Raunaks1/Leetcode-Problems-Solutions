class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xOr=0,c=0,c2=0;
        for(int i=0;i<nums.size() ;i++) 
        {
            if(nums[i] != 0)
            {
                xOr^=nums[i];
                c2++;
            }
            else
            c++;
        }
        if(c2 == 0)
        {
            return 0;
        }
        if(xOr == 0)
        {
            return c2+c-1;
        }
        return c2+c;
    }
};