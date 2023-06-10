//https://leetcode.com/problems/invert-binary-tree/submissions/968394399/
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
    TreeNode* invertTree(TreeNode* root) {
        //O(N)
        if(root == nullptr)
        {
            return nullptr;
        }
        TreeNode* t = root->left; root->left = root->right; root->right = t;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};