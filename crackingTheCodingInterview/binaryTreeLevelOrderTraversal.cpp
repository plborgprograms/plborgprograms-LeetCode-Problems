//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/
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
    //used a pass by reference vector for the results
	
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;    
        innerLevelOrder(result, 0, root);
        
        return result;
    }
    
    void innerLevelOrder(vector<vector<int>> &nodes, int level, TreeNode* current)
    {
        if(current == nullptr)
        {
            return;
        }
        
        if(level >= nodes.size())
        {
            nodes.emplace_back(vector<int>());
        }
        nodes[level].emplace_back(current->val);
        
        innerLevelOrder(nodes, level+1, current->left);
        innerLevelOrder(nodes, level+1, current->right);
    }
};