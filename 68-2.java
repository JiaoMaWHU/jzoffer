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
    TreeNode res;
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        res = null;
        findAncestor(root, p, q);
        return res;
    }
    
    public TreeNode findAncestor(TreeNode root, TreeNode p, TreeNode q){
        if(res != null) {
            return null;
        }
        if(root == null) {
            return null;
        }
        TreeNode nl = findAncestor(root.left, p, q);
        TreeNode nr = findAncestor(root.right, p, q);
        TreeNode pn = null, qn = null;

        if(nl != null) {
            if(nl.val == p.val)
                pn = nl;
            else if(nl.val == q.val)
                qn = nl;
        }
        
        if(nr != null) {
            if(nr.val == p.val)
                pn = nr;
            else if(nr.val == q.val)
                qn = nr;
        }
        
        if(root.val == p.val)
            pn = root;
        else if(root.val == q.val)
            qn = root;
        
        if(qn != null && pn != null && res == null) {
            res = root;
        }else if(pn!=null) {
            return pn;
        }else if(qn!=null) {
            return qn;
        }
        return null;
    }
}