/**
 * https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    public int SumEvenGrandparent(TreeNode root) {
        sum = 0;
        GetSumIfEvenGrandparent(root, false, false);
        
        return sum;
    }
    int sum;
    public void GetSumIfEvenGrandparent(TreeNode current, bool getSum, bool childrenShouldGetSum)
    {
        if(getSum)
        {
            sum += current.val;
        }
                
        if(current.left != null)
        {
            GetSumIfEvenGrandparent(current.left, childrenShouldGetSum, (current.val%2 == 0) );
        }
        
        if(current.right != null)
        {
            GetSumIfEvenGrandparent(current.right, childrenShouldGetSum, (current.val%2 == 0) );
        }
        
    }
}