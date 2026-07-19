class Solution {
public:
    string smallestSubsequence(string s) {

        stack<char> st;

        map<char, int> last;
        map<char, bool> seen;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            last[s[i]] = i;
        }

        for(int i = 0; i < n; i++) {

            char ch = s[i];
            if(seen[ch]) continue;
            while(!st.empty() &&
                  st.top() > ch &&
                  last[st.top()] > i) {

                seen[st.top()] = false;
                st.pop();
            }

            st.push(ch);
            seen[ch] = true;
        }
        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};