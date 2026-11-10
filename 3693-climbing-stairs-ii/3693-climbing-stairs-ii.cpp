class Solution {
 private:
  static constexpr int min_delta = 1;
  static constexpr int max_delta = 4;

 public:
  int climbStairs(const int n, const vector<int> &costs) {
    unsigned int dp[max_delta];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int d = min_delta; d < max_delta; ++d) {
        if (i + d < n + 1) {
          dp[to_index(i + d)] = min(dp[to_index(i + d)], dp[to_index(i)] + costs[i + d - 1] + d * d);
        }
      }
      dp[to_index(i)] = -1;
    }
    return static_cast<int>(dp[to_index(n)]);
  }

 private:
  int to_index(const int i) {
    return i % max_delta;
  }
};