class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> a(m,vector<int>(n,0));

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=grid[i][j];
        }
      }
     

for(int c=0;c<k;c++){
      int prev = a[m-1][n-1];
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int temp = a[i][j];
            a[i][j] = prev;
            prev = temp;
        }
      } 
} 
      return a;
    }
};