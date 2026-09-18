class Solution {
public:
    int getend(string s, map<char, vector<int>>& mp, int start)
    {
        int end = mp[s[start]][1];
        for(int i = start; i <= end; i++)
        {
            if(mp[s[i]][0] < start)
                return -1;
            end = max(end, mp[s[i]][1]);
        }
        return end;
    }
    vector<string> maxNumOfSubstrings(string s) {
        map<char, vector<int>> mp;
        for(int i = 0; i < s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                mp[s[i]][1] = i;
            }
            else
                mp[s[i]] = vector<int>{i, i};
        }
        int substringstart = -1;
        vector<string> res;

        for(int i = 0; i < s.length(); i++)
        {
            int start = mp[s[i]][0];
            if(start == i)
            {
                int substringend = getend(s, mp, i);
                if(substringend != -1)
                {
                    if(substringend > substringstart)
                    {
                        res.push_back("");
                    }
                    substringstart = substringend;
                    res[res.size() - 1] = s.substr(i, substringstart - i + 1);
                }
            }
        }
        return res;
    }
};