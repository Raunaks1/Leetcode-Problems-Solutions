class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0;

        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(')
                st.push({i, 0});

            else {
                auto a = st.top();
                st.pop();

                int cur = (a.second == 0) ? 1 : 2 * a.second;

                if (!st.empty())
                    st.top().second += cur;
                else
                    ans += cur;
            }
        }

        return ans;
    }
};