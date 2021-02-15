/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        int[] maxDiff = new int[1];
        maxDiff[0] = 0;
        nodesNum(root, maxDiff);
        if(maxDiff[0]>1){
            return false;
        }
        return true;
    }
    
    public int nodesNum(TreeNode root, int[] maxDiff) {
        if (root == null) {
            return 0;
        }
        int l = nodesNum(root.left, maxDiff);
        int r = nodesNum(root.right, maxDiff);
        maxDiff[0] = Math.max(Math.abs(l-r), maxDiff[0]);
        return Math.max(l, r) + 1;
    }
}