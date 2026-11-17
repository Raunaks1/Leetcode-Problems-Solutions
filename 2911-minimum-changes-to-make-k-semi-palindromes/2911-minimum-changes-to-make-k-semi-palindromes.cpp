class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length(), inf = 1e3;
        vector<vector<int>> cost(n, vector<int> (n, inf));
        for (int l = 0; l < n - 1; ++l) {
            for (int r = l + 1; r < n; ++r) {
                int len = r - l + 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d != 0) {
                        continue;
                    }
                    vector<string> groups(d);
                    for (int i = 0; i < d; ++i) {
                        for (int j = i; j < len; j += d) {
                            groups[i] += s[l + j];
                        }
                    }
                    int cur = 0;
                    for (string& g : groups) {
                        int L = 0, R = g.length() - 1;
                        while (L < R) {
                            cur += (g[L++] != g[R--]);
                        }    
                    }
                    cost[l][r] = min(cost[l][r], cur);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, inf));
        dp[n][0] = 0;
        for (int i = n - 1; ~i; --i) {
            for (int j = 1; j <= k; ++j) {
                for (int len = 2; i + len <= n; ++len) {
                    int rem = n - i - len;
                    if (rem < 2 * (j - 1)) {
                        break;
                    }
                    dp[i][j] = min(dp[i][j], cost[i][i + len - 1] + dp[i + len][j - 1]);
                }
            }
        }
        return dp[0][k];
    }
};