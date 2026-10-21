
class Solution {
public:
    int minOperations(string s) {

        if (is_sorted(s.begin(), s.end()))
            return 0;

        int n = s.length();

        char minChar = 'z';
        char maxChar = 'a';

        int minCount = 0;
        int maxCount = 0;


        for (int i = 0; i < n; i++) {

            if (s[i] < minChar) {
                minChar = s[i];
                minCount = 0;
            }

            if (s[i] > maxChar) {
                maxChar = s[i];
                maxCount = 0;
            }

            if (s[i] == minChar)
                minCount++;

            if (s[i] == maxChar)
                maxCount++;
        }


        if (n == 2)
            return -1;


        if (s[0] == minChar || s[n - 1] == maxChar)
            return 1;

        if (s[0] == maxChar && maxCount == 1 &&
            s[n - 1] == minChar && minCount == 1)
            return 3;

        return 2;
    }
};