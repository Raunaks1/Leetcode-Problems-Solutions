class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        vector<vector<bool>> a(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            a[i][i]=true;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || a[i+1][j-1])) a[i][j]=true;
            }
        }
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++){
            b[i]=b[i-1];
            for(int j=0;j+k<=i;j++){
                if(a[j][i-1]) b[i]=max(b[i],b[j]+1);
            }
        }
        return b[n];
    }
};