class Solution {
    struct Pair {
        long long sum;
        vector<int> ids;

        Pair(long long sum = 0, vector<int> ids = {}) {
            this->sum = sum;
            this->ids = ids;
        }
    };

    vector<vector<Pair>> dp;
    vector<int> next;

    Pair better(Pair a, Pair b) {
        if (a.sum != b.sum)
            return a.sum > b.sum ? a : b;

        sort(a.ids.begin(), a.ids.end());
        sort(b.ids.begin(), b.ids.end());

        for (int i = 0; i < min(a.ids.size(), b.ids.size()); i++) {
            if (a.ids[i] != b.ids[i])
                return a.ids[i] < b.ids[i] ? a : b;
        }

        return a.ids.size() <= b.ids.size() ? a : b;
    }

    int lowerBound(vector<vector<int>>& in, vector<int>& order, int target) {
        int l = 0, r = order.size();

        while (l < r) {
            int m = l + (r - l) / 2;

            if (in[order[m]][0] >= target)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    Pair solve(vector<vector<int>>& in, vector<int>& order,
               int pos, int count) {

        if (pos == order.size() || count == 4)
            return Pair();

        if (dp[pos][count].sum != -1)
            return dp[pos][count];

        Pair skip = solve(in, order, pos + 1, count);

        int id = order[pos];

        Pair take = solve(
            in,
            order,
            next[pos],
            count + 1
        );

        take.sum += in[id][2];
        take.ids.push_back(id);

        dp[pos][count] = better(skip, take);

        return dp[pos][count];
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> order(n);

        for (int i = 0; i < n; i++)
            order[i] = i;

        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][0] < intervals[b][0];
        });

        next.resize(n);

        for (int i = 0; i < n; i++) {
            int id = order[i];

            next[i] = lowerBound(
                intervals,
                order,
                intervals[id][1] + 1
            );
        }

        dp.assign(n, vector<Pair>(4, Pair(-1, {})));

        vector<int> ans = solve(intervals, order, 0, 0).ids;

        sort(ans.begin(), ans.end());

        return ans;
    }
};