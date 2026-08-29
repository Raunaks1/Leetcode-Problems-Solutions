class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<pair<int,int>> a; 
        int n = nums.size();

        for(int i = 0; i < n ; i++) a.push_back({nums[i] , i});
        
        sort(a.begin(),a.end());

        vector<vector<int>> val, indx ;

        val.push_back({a[0].first});
        indx.push_back({a[0].second});

        int j = 0;
        int prev = a[0].first ;

        for(int i = 1; i < n; i++) {

            int val1 = a[i].first ;
            if(abs(val1-prev) <= limit) {

                val[j].push_back(val1);
                indx[j].push_back(a[i].second);

            }
            else {

                j++;
                val.push_back({val1});
                indx.push_back({a[i].second});

            }

            prev = a[i].first;
        }

        for(auto &it: indx) {
            sort(it.begin(),it.end());
        }

        vector<int> ans(n,0);

        for(int i = 0; i < val.size(); i++) {
            for(int j = 0; j < val[i].size(); j++) {

                ans[indx[i][j]] = val[i][j];

            }
        }

        return ans; 

    }
};