class Solution {
public:
    int helper(vector<int>& s,int i)
    {
        if(i==s.size())return 0;
        int c[2]={1,2};
        int ans=INT_MIN;
        int sum=s[i];
        
        ans=max(ans,sum-helper(s,i+1));
        
        for(auto &j:c)
        {
            if(i+j<s.size())
            {
                sum+=s[i+j];
                ans=max(ans,sum-helper(s,i+j+1));
            }
            
        }
        return ans;
    }

    int helperTDP(vector<int>& s,int i,vector<int> &dp)
    {
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int c[2]={1,2};
        int ans=INT_MIN;
        int sum=s[i];
        ans=max(ans,sum-helperTDP(s,i+1,dp));
        
        for(auto &j:c)
        {
            if(i+j<s.size())
            {
                sum+=s[i+j];
                ans=max(ans,sum-helperTDP(s,i+j+1,dp));
            }
            
        }
        return dp[i]=ans;
    }
    int helperBDP(vector<int>& s)
    {
        vector<int> dp(s.size()+1,0);
        for(int i=s.size()-1;i>=0;i--)
        {
            int ans=INT_MIN;
            ans=max(ans,s[i]-dp[i+1]);
            if(i+1<s.size())
            {
                ans=max(ans,s[i]+s[i+1]-dp[i+2]);
            }
            if(i+2<s.size())
            {
                ans=max(ans,s[i]+s[i+1]+s[i+2]-dp[i+3]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
    int helperSOP(vector<int>& s)
    {
        int first=0,second=0,third=0,cur=0;

        for(int i=s.size()-1;i>=0;i--)
        {
            int ans=INT_MIN;
            ans=max(ans,s[i]-first);
            if(i+1<s.size())
            {
                ans=max(ans,s[i]+s[i+1]-second);
            }
            if(i+2<s.size())
            {
                ans=max(ans,s[i]+s[i+1]+s[i+2]-third);
            }
            cur=ans;
            third=second;
            second=first;
            first=cur;
        }
        return cur;
    }
    string stoneGameIII(vector<int>& s) {
        int x=helperSOP(s);
        if(x>0)return  "Alice";
        if(x<0)return "Bob";
        return "Tie";
    }
};