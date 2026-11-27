class Solution {
public:
int mini, n;
vector<int>free;
int dp[1001][1501];

int solve(int i, int budget, vector<vector<int>>& items){

    if(i >= items.size()){
        return budget/mini; 
        
    }

    if(dp[i][budget] != -1) return dp[i][budget];

    int take = 0;
    if(budget >= items[i][1]) 
       take = free[i] + solve(i+1, budget - items[i][1], items);

    int skip = solve(i+1, budget, items);

    return dp[i][budget] = max(take, skip);
}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        mini = INT_MAX, n = items.size();
        free.resize(n, 0);
        memset(dp, -1, sizeof(dp));

        for(int i=0;i<n;i++){
            mini = min(mini, items[i][1]);

            for(int j=0;j<n;j++){
                if(items[j][0] % items[i][0] == 0) free[i]++;
            }
        }

        return solve(0, budget, items);
    }
};