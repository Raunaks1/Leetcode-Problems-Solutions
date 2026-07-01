class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, int n, vector<vector<int>> &vis){
        return x >= 0 && y >= 0 && x < n &&  y < n && !vis[x][y];
    }

    vector<vector<int>> preCompute(vector<vector<int>> &grid){
        int n = grid.size();

        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(isValid(newX, newY, n, vis)){
                    ans[newX][newY] = ans[x][y] + 1;
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
        return ans;
    }

    bool isPossible(int d, vector<vector<int>> &grid){
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if(grid[0][0] < d || grid[n-1][n-1] < d){
            return false;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            if(x == n-1 && y == n-1){
                return true;
            }
            
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(isValid(newX, newY, n, vis) && grid[newX][newY] >= d){
                    q.push({newX, newY});
                    vis[newX][newY] = 1;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeDist = preCompute(grid);

        int low = 0, high = 400;
        int res = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(mid, safeDist)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};