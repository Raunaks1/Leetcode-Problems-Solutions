class Solution {
    int dp[101];
    int solve(string s, int i){
        int n=s.length();
        if(i==n) return 1;
        if(i==n+1) return 0;
        if(s[i]=='0') return 0; 
        
        if(dp[i]!=-1) return dp[i];

        int a=solve(s,i+1); 
        int b=0;
        if(i+1<n){ 
            string t="";
            t+=s[i];
            t+=s[i+1];
            if(stoi(t)<=26 && stoi(t)>=1) b=solve(s,i+2); 
        }
        return dp[i]=a+b;
    }
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};