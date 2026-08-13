class Solution {
    struct Node {
        char leftChar, rightChar;

        int len;
        int prefix;
        int suffix;
        int best;

        Node() {
            leftChar = rightChar = '#';
            len = prefix = suffix = best = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node left, Node right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;

        res.len = left.len + right.len;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.best = max(left.best, right.best);
        res.prefix = left.prefix;

        if (left.prefix == left.len && left.rightChar == right.leftChar) res.prefix = left.len + right.prefix;

        res.suffix = right.suffix;

        if (right.suffix == right.len && left.rightChar == right.leftChar) res.suffix = right.len + left.suffix;
        if (left.rightChar == right.leftChar) res.best = max(res.best, left.suffix + right.prefix);

        return res;
    }

    void build(int node, int start, int end, string& s) {
        if (start == end) {
            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = start + (end - start) / 2;

        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int index, char ch) {
        if (start == end) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) update(node * 2, start, mid, index, ch);
        else update(node * 2 + 1, mid + 1, end, index, ch);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, index, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};