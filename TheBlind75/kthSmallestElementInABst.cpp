//https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
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
//return negative if it still needs to be found
    int ItemsChecked = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
        {
            return -1;
        }
        int result = kthSmallest(root->left, k);
        if(result >= 0)
        {
            return result;
        }
        ItemsChecked++;
        if(k == ItemsChecked)
        {
            return root->val;
        }

        result = kthSmallest(root->right, k);
        return result;
    }
};