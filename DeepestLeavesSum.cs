/**
 * https://leetcode.com/problems/deepest-leaves-sum/
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
    
    int deepestDepth = 0;
    int total = 0;
    public int DeepestLeavesSum(TreeNode root) {
        deepestDepth = -1;
        total = 0;
        //if this is a leaf, check if it's just as deep or deeper than the currently recorded deepest leaf
        //and add to the total
        GetSumIfDeepest(root, 0);
        return total;
    }
    
    public void GetSumIfDeepest(TreeNode current, int depth)
    {
        if(current.left != null || current.right != null)
        {
            if(current.left != null)
            {
                GetSumIfDeepest(current.left, depth+1);
            }
            
            if(current.right != null)
            {
                GetSumIfDeepest(current.right, depth+1);
            }
        }
        else
        {
            if(depth > deepestDepth )
            {
                deepestDepth = depth;
                total = current.val;
            }
            else if(depth == deepestDepth)
            {
                total += current.val;
            }
        }
        
    }
}