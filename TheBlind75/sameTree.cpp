//https://leetcode.com/problems/same-tree/submissions/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //O(N)
        if(p == nullptr && q == nullptr)
        {
            return true;
        }
        if(p == nullptr || q == nullptr)
        {
            return false;
        }

        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};