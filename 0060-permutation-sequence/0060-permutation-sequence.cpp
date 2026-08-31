class Solution {
public:
    string kth_permutation(string s, int k, vector<int>& fact) {
        int n = s.size();

        if (n == 1) {
            return s;
        }

        int block_size = fact[n - 1];
        int i = k / block_size;
        char ch = s[i];
        s.erase(s.begin() + i);


        return ch + kth_permutation(s, k % block_size, fact);
    }

    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s += to_string(i + 1);
        }

        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++) {
            fact[i] = i * fact[i - 1];
        }

        return kth_permutation(s, k - 1, fact); 
    }
};