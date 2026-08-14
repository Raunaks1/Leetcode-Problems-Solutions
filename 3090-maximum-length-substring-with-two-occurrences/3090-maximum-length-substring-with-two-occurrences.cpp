class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int max_len=0;
        for(int i=0;i<n-1;i++){
            unordered_map<char,int>mp;
            mp[s[i]]++;
            int len=1;
            for(int j=i+1;j<n;j++){
                mp[s[j]]++;
                if(mp[s[j]]>2)break;
                len++;
                max_len=max(max_len,len);
            }
        }
        return max_len;
    }
};