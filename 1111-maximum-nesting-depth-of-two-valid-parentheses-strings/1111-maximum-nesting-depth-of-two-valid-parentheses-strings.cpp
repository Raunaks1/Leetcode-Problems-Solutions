class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
         vector<int> ans(seq.size());
        int d = 0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                ans[i] = d%2;
                d++;
            }else{
                d--;
                ans[i] = d%2;
            }
        }
        return ans;
    }
};