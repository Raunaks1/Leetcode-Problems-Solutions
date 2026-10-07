
typedef long long ll;

class Solution {
public:
    int minSizeSubarray(vector<int>& v, int target) {
        ll s = accumulate(v.begin(), v.end(), 0LL);
        ll n = v.size(), ans = 0;
        if(target > s) {
            ll q = target / s;
            target -= (s * q);
            ans = q * n;
        }
        ll t = target;
        if(target == 0) return ans;
        ll end = 0, start = 0, cnt = 1e14;
        while(end < 2*n) {
            int i = end % n;
            t -= v[i];
            end += 1;
            while(t < 0) {
                t += v[(start++)%n];
            }
            if(t == 0) cnt = min(cnt, end - start);
        }
        return cnt == 1e14 ? -1 : ans + cnt;
    }
};