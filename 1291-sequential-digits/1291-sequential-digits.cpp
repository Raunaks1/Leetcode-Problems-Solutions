class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
         string s1=to_string(low);
        string s2=to_string(high);
        vector<int>ans;
        int len=s1.size();
        int mxlen=s2.size();
        for(int i=len;i<=mxlen;i++){
            for(int j=1;j<=(9-i+1);j++){
                string temp="";
                for(int k=0;k<i;k++){
                    temp.push_back((char)('0'+j+k));
                }
                long long num=stoll(temp);
                if(num<low || num>high) continue;
                ans.push_back(num);
            }
        }
        return ans;
        
    }
};