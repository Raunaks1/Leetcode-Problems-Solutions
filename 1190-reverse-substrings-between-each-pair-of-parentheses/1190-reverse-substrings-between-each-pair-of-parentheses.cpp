class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push_back(i);
            }
            else if(s[i] == ')') {
                int l = st.back();
                st.pop_back();
                reverse(s.begin() + l + 1, s.begin() + i);
            }
        }

        string v;

        for(char c : s) {
            if(c != '(' && c != ')') {
                v.push_back(c);
            }
        }

        return v;
    }
};