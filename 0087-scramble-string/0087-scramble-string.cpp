class Solution {
public:
    bool solve(string s1, string s2, unordered_map<string, bool>& t) {
        int n = s1.size();
        if (s1 == s2)
            return true;

        if (s1.size() != s2.size()) {
            return false;
        }

        string key = s1 + "_" + s2;
        if (t.find(key) != t.end()) {
            return t[key];
        }

        bool flag = false;
        for (int i = 1; i < n; i++) {
            bool not_swapped =
                solve(s1.substr(0, i), s2.substr(0, i), t) 
                &&
                solve(s1.substr(i, n - i), s2.substr(i, n - i), t);

            bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i), t) 
                            &&
                           solve(s1.substr(i, n - i), s2.substr(0, n - i), t);

            if (swapped || not_swapped) {
                flag = true;
                break;
            }
        }

        return t[key] = flag;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> t;

        return solve(s1, s2, t);
    }
};