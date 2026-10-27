class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i = 0; i< m; i++) {
            string row = "";
            for(int j = 0; j< n; j++) {
                row += "#";
            }
            ans.push_back(row);
        }

        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                if(i == 0 || j == n-1) {
                    ans[i][j] = '.';
                }
            }
        }
        return ans;
    }
};