/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }s
 */
class Solution {
    public int kthLargest(TreeNode root, int k) {
        int[] no = new int[1];
        no[0] = 0;
        TreeNode res = inorder(root, k, no);
        return res.val;
    }
    
    public TreeNode inorder(TreeNode root, int k, int[] no) {
        if (root == null) {
            return null;
        }
        TreeNode right = inorder(root.right, k, no);
        if(right != null) {
            return right;
        }
        if (++no[0] == k) {
            return root;
        }
        return inorder(root.left, k, no);
    }
}