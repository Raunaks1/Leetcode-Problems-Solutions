class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) 
    {
        unordered_map<string, string> hm;
        int n = knowledge.size();
        for(int i =0; i<n; i++)
        {
            hm[knowledge[i][0]] = knowledge[i][1];
        }

        int si = -1, ei=-1;
        string ans="";
        int l = s.length();
        bool brack = false;

        for(int i=0; i<l; i++)
        {
            if (s[i]=='(')
            {
                si = i;
                brack=true;
            }
            else if (s[i]==')')
                ei = i;
            else if (brack==false)
            {
                ans+=s[i];
            }
            if (si!=-1 && ei !=-1)
            {
                int k = ei-si-1;
                if (hm.count(s.substr(si+1, k)))
                    ans+=hm[s.substr(si+1, k)];
                else
                    ans+="?";
                ei=-1;
                si=-1;
                brack = false;
            }
        }
        return ans;   
    }
};