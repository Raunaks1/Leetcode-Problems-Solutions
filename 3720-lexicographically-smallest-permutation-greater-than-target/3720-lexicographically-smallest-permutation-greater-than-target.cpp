class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp = freq;
            bool ok = true;

            for (int j = 0; j < i; j++) {
                if (temp[target[j] - 'a'] == 0) {
                    ok = false;
                    break;
                }
                temp[target[j] - 'a']--;
            }

            if (!ok) continue;

            int chosen = -1;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    chosen = c;
                    break;
                }
            }

            if (chosen == -1) continue;

            temp[chosen]--;
            string suffix = "";
            for (int c = 0; c < 26; c++) {
                suffix += string(temp[c], 'a' + c);
            }

            return target.substr(0, i) + char('a' + chosen) + suffix;
        }

        return "";
    }
};