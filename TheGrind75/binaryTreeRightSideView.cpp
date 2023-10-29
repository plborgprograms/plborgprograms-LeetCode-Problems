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
//https://leetcode.com/problems/binary-tree-right-side-view/submissions/
class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
        //O(N)
        //iterate from top to bottom
        vector<int> result;
        innerFunction(root, 0, result);
        return result;
    }

    void innerFunction(TreeNode* root, int level,  vector<int> &result)
    {
        //result passed as parameter instead of member variable to reduce runtime
        if(root == nullptr)
        {
            return;
        }
        if(result.size() == level)
        {
            result.emplace_back(root->val);
        }
        innerFunction(root->right, level+1, result);
        innerFunction(root->left,  level+1, result);
    }
};