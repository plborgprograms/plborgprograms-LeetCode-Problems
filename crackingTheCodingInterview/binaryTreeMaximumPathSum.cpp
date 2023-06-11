//https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int best = INT_MIN;
    int maxPathSum(TreeNode* root) {
		//O(N)
        Inner(root);
        return best;
    }

    int Inner(TreeNode* root) {
        //iterate through the tree finding the highest combination
        //Only options that only use one side can be extended to 
        //the parent.
        if(root == nullptr)
        {
            return 0;
        }
        int left = Inner(root->left);
        int right = Inner(root->right);

        int bestExtendablePossibility = root->val + max({0, left, right});
        best = max({best, left + root->val + right, bestExtendablePossibility});

        return bestExtendablePossibility;
    }
};