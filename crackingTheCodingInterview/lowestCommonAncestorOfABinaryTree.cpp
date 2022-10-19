//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* current, TreeNode* a, TreeNode* b)
    {
        //if a or b is a child of the other, this will return the parent of the two
        if(current == nullptr || current == a || current == b )
        {
            return current;
        }
        
        TreeNode* l = lowestCommonAncestor(current->left, a, b);
        TreeNode* r = lowestCommonAncestor(current->right, a, b);
        
        //if each result is in a separate subtree, return current
        if(l != nullptr && r != nullptr)
        {
            return current;
        }
        
        //return the one that is not null or return null
        //if l is not null return it
        //if r is not null return it or if both are null, 
        //just return r since it will return null anyway.
        return (l != nullptr) ? l : r;
    }
    
};