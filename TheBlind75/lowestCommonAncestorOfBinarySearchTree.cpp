//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
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

    TreeNode* result = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//O(N)
        lca(root, p,q);
        return result;
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        TreeNode* leftResult = lca(root->left, p, q);
        TreeNode* rightResult = lca(root->right, p, q);
        bool pf = (p == root || p == leftResult || p == rightResult);
        bool qf = (q == root || q == leftResult || q == rightResult);
        if(pf && qf)
        {
            result = root;
            return nullptr;
        }
        else if(leftResult)
        {
            return leftResult;
        }
        else if(rightResult)
        {
            return rightResult;
        }
        else if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        
        return nullptr;
    }
};