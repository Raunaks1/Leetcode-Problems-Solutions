class Solution {
public:

    int dp[1005][1005][4];
    int MOD = 1000000007;
    map<int,int> mp;
    string s;

    int rec(int l, int r, int c)
    {
        if(l > r)
        {
            return 0;
        }

        if(l == r)
        {
            if(s[l] == mp[c])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if(dp[l][r][c] != -1)
        {
            return dp[l][r][c];
        }

        int ans = 0;

        if (s[l] == s[r] && s[l] == mp[c])
        {
            ans = 2;
            for(int i = 0; i<4; i++)
            {
                ans = (ans + rec(l+1, r-1, i))%MOD;
            }
        }
        else
        {
            ans = (ans + rec(l+1, r, c))%MOD;
            ans = (ans + rec(l, r-1, c))%MOD;
            ans = (ans + MOD - rec(l+1, r-1, c))%MOD;
        }

        return dp[l][r][c] = ans;
    }

    int countPalindromicSubsequences(string s) {
        mp[0] = 'a';
        mp[1] = 'b';
        mp[2] = 'c';
        mp[3] = 'd';
        this->s = s;
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i<4; i++)
        {
            int r = rec(0, n-1, i);
            ans = (ans + r)%MOD;
        }
        
        return ans;
    }
};