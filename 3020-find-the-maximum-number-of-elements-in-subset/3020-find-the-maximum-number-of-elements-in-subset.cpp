class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        int ans = 1;
        if(mp.count(1)){
            if(mp[1] % 2){
                ans = max(ans, mp[1]);
            }
            else{
                ans = max(ans, mp[1] - 1);
            }
        }

        int cnt = 1;
        for(auto &i : mp){

            if(i.first == 1) continue;

            if(i.second < 2) continue;

            long long curr = i.first;
            cnt = 2;

            while(true){

                if(curr > LLONG_MAX / curr)
                    break;

                curr = curr * curr;

                if(!mp.count(curr))
                    break;

                if(mp[curr] == 1){
                    cnt++;
                    break;
                }
                cnt += 2;
            }

            ans = max(ans, cnt);
        }
        return ans % 2 == 0 ? ans - 1 : ans;
    }
};