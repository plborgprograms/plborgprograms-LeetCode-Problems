//https://leetcode.com/problems/balanced-binary-tree/submissions/
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
    
    int getHeightOfSubTree(TreeNode* currentNode)
    {
        //end of the current is null
        if(currentNode == nullptr)
        {
            return 0;
        }
        
        //get the height of each subtree
        int l = getHeightOfSubTree(currentNode->left);
        int r = getHeightOfSubTree(currentNode->right);
        
        //use -1 to note if there is already an imbalance found
        //check for imbalance using abs(l-r) >= 2
        if(l == -1 || r == -1 || abs(l-r) >= 2)
        {
            return -1;
        }
        
        return max(l,r)+1;
        
    }
    
    
    bool isBalanced(TreeNode* root) {
        return getHeightOfSubTree(root) != -1;
    }
};