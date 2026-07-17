class Solution {
public:
    using ll = long long;

    vector<int> gcdValues(vector<int>& nums, vector<ll>& quries) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());

        vector<ll> freq(maxx + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 1; i <= maxx; i++) {
            for (int j = i * 2; j <= maxx; j += i) {
                freq[i] += freq[j];
            }
        }

        for (int i = 1; i <= maxx; i++) {
            freq[i] = freq[i] * (freq[i] - 1) / 2;
        }

        for (int i = maxx; i >= 1; i--) {
            for (int j = i * 2; j <= maxx; j += i) {
                freq[i] -= freq[j];
            }
        }

        for (int i = 1; i <= maxx; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans;

        for (ll x : quries) {
            ll val = lower_bound(freq.begin(), freq.end(), x+1) - freq.begin();
            ans.push_back(val);
        }

        return ans;
    }
};