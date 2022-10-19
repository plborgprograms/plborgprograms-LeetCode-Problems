//https://leetcode.com/problems/validate-binary-search-tree/submissions/
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
    
    //set the bounds that each node has to be between
    //if it breaks the bounds, return false
    bool innerIsValidBST(TreeNode* current, long min, long max)
    {
        if( current->val <= min || current->val >= max)
        {
            return false;
        }
        
        if(current->left != nullptr && !innerIsValidBST(current->left, min, current->val))
        {
            return false;
        }
        
        if(current->right != nullptr && !innerIsValidBST(current->right, current->val, max))
        {
            return false;
        }
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return innerIsValidBST(root, LONG_MIN, LONG_MAX);
    }
};