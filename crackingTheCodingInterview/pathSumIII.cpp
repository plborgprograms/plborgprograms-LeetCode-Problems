//https://leetcode.com/problems/path-sum-iii/submissions/
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
    
    int totalSums = 0;
    int target = 0;
    
    int GetSubTreeTotal(TreeNode* current, long runningTotal)
    {
        if(current == nullptr)
        {
            return 0;
        }
        
        runningTotal += current->val;
        //cout << "runningTotal:" << runningTotal << endl;
        if(runningTotal == target)
        {
            totalSums++;
        }
        GetSubTreeTotal(current->left, runningTotal);
        GetSubTreeTotal(current->right, runningTotal);
        return 0;
    }
    
    void Traverse(TreeNode* current)
    {
        if(current == nullptr)
        {
            return;
        }
        
        GetSubTreeTotal(current, 0);
        
        Traverse(current->left);
        Traverse(current->right);
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        totalSums = 0;
        target = targetSum;
        Traverse(root);
        return totalSums;
    }
};