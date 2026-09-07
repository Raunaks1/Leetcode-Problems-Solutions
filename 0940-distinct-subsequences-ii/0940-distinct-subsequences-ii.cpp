class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1);
        dp[0] = 1;

        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int ch = s[i-1] - 'a';
            dp[i] = 2 * dp[i-1] % MOD;

            if (last[ch] != -1) {
                dp[i] = dp[i] - dp[last[ch] - 1];
                if (dp[i] < 0)
                    dp[i] += MOD;
            }
            last[ch] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};