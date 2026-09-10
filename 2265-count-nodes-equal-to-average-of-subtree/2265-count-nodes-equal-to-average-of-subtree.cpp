/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct P {
        int s{}, c{};
        inline void add(P x) {
            s += x.s;
            c += x.c;
        }
    };
    int averageOfSubtree(TreeNode* x) {
        int r = 0;
        [&r](this auto&& f, TreeNode* x) -> P {
            P p{};
            if (x) {
                p.add(P{x->val, 1});
                p.add(f(x->left));
                p.add(f(x->right));
                r += ((p.s / p.c) == x->val);
            }
            return p;
        }(x);
        return r;
    }
};