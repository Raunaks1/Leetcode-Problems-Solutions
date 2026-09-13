class Solution {
public:
    int solve(vector<vector<int>>& img1, vector<vector<int>>& img2, int x, int y){
        int n = img1.size(),m = img1[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int nx = i - x;
                int ny = j - y;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(img1[nx][ny] + img2[i][j] == 2) cnt++;
            }
        }

        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), m = img1[0].size();

        int count = 0;
        for(int i = -n+1;i<n;i++){
            for(int j = -m+1;j<m;j++){
                count = max(count,solve(img1, img2, i, j));
            }
        }

        return count;
    }
};