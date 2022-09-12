/**
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode BstToGst(TreeNode root) {
        TotalToTheRight = 0;
        UpdateTotals(root);
        
        return root;
    }
    
    int TotalToTheRight = 0;
    public void UpdateTotals(TreeNode current) {
        if(current.right != null)
        {
            UpdateTotals(current.right);
        }
        current.val += TotalToTheRight;
        TotalToTheRight = current.val;
        
        if(current.left != null)
        {
            UpdateTotals(current.left);
        }
        
        
    }
}