class SegmentTree {
public:

    struct Node {
        vector<int> pre=vector<int>(6,0);
        int mul = 1;
    };

    int n, k, size;
    vector<Node> tree;

    SegmentTree(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;

        size = 1;
        while (size < n)
            size *= 2;

        tree.resize(2 * size);

        build(nums);
    }

    Node merge(const Node& a, const Node& b) {
        Node res;

        for (int x = 0; x < k; x++)
            res.pre[x] = a.pre[x];

        for (int x = 0; x < k; x++)
            res.pre[(a.mul * x) % k] += b.pre[x];

        res.mul = (a.mul * b.mul) % k;

        return res;
    }

    void build(vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            int x = nums[i] % k;

            tree[size + i].pre[x] = 1;
            tree[size + i].mul = x;
        }

        for (int i = size - 1; i >= 1; i--)
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }

    void update(int pos, int val) {
        pos += size;

        tree[pos].pre.assign(6,0);

        int x = val % k;

        tree[pos].pre[x] = 1;
        tree[pos].mul = x;

        pos /= 2;

        while (pos) {
            tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    Node query(int l, int r) {
        l += size;
        r += size;

        Node left, right;

        while (l <= r) {
            if (l & 1)
                left = merge(left, tree[l++]);

            if (!(r & 1))
                right = merge(tree[r--], right);

            l /= 2;
            r /= 2;
        }

        return merge(left, right);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        SegmentTree seg(nums, k);

        vector<int> ans;

        for (auto &q : queries) {
            seg.update(q[0], q[1]);

            auto res = seg.query(q[2], nums.size() - 1);

            ans.push_back(res.pre[q[3]]);
        }

        return ans;
    }
};