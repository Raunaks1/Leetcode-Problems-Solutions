/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        return preOrder(root,targetSum);
    }
    int preOrder(TreeNode root,int targetSum){
        if(root==null)
        return 0;
        int count=0;
        count=calcSum(root,0,targetSum);
        count=count+ preOrder(root.left,targetSum)+
        preOrder(root.right, targetSum);
        return count;
    }

    int calcSum(TreeNode root, long sum, int targetSum){
        if(root==null)
        return 0;
        int count=0;
        sum=sum+root.val;
        if(sum== targetSum)
        count++;
        count=count+ calcSum(root.left,sum,targetSum)+
        calcSum(root.right,sum,targetSum);
        return count;
    }
}