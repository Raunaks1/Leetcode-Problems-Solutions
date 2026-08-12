class Solution {
public:
    bool checkValid(vector<vector<int>>& a) {
         int n=a.size();


        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=0;j<n;j++){
                st.insert(a[i][j]);
            }
            if(st.size()!=n) return false;
        }

        for(int j=0;j<n;j++){
            unordered_set<int>st;
            for(int i=0;i<n;i++){
                st.insert(a[i][j]);
            }
            if(st.size()!=n) return false;
        }

        return true;
    }
};