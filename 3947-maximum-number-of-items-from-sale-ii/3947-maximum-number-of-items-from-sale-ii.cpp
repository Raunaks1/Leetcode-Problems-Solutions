class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int target) {
        int n = items.size();
        vector<int> f(n + 1), g(n + 1);

        for (auto v : items) {
            f[v[0]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (f[i] == 0) continue;
            for (int j = i; j <= n; j += i) {
                if (f[j] > 0) {
                    g[i] += f[j];
                }
            }
        }

        vector<array<int, 3>> b(n);
        int mini = items[0][1];

        for (int i = 0; i < n; i++) {
            b[i] = {items[i][0], items[i][1], g[items[i][0]] - 1};
            mini = min(mini, b[i][1]);
        }

        sort(b.begin(), b.end(), [](auto &u, auto &v) {
            int w = u[1] * (u[2] ? 1 : 2);
            int z = v[1] * (v[2] ? 1 : 2);
            if (w == z) return u[2] > v[2];
            return w < z;
        });

        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if ((b[i][1] > 2 * mini) || (target < b[i][1])) break;
            int y = min(target / b[i][1], b[i][2]);
            target -= y * b[i][1];
            ans += 2 * y;
        }

        ans += target / mini;

        return ans;
    }
};