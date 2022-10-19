//https://leetcode.com/problems/subtree-of-another-tree/submissions/
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
    
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        else if(root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        
        bool v = (subRoot->val == root->val);
        if(!v)
        {
            return false;
        }
        bool l = isSame(root->left, subRoot->left);
        bool r = isSame(root->right, subRoot->right);
        return (l && r);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)
        {
            return false;
        }
        
        bool s = isSame(root, subRoot);
        if(s)
        {
            return true;
        }
        
        //found in left subtree or found in right subtree
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        return (l || r);
    }
};