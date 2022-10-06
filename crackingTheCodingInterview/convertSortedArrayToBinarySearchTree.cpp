// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
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
    
    TreeNode* GetTreeOfSet(vector<int>& input, int bottomOfRange, int topOfRange)
    {
        int middleOfRange = ceil( (bottomOfRange+topOfRange)/2 );
        TreeNode* currentNode = new TreeNode(input[middleOfRange]);
        
        if(middleOfRange > bottomOfRange)
        {
            currentNode->left = GetTreeOfSet(input, bottomOfRange,  middleOfRange-1);
        }
        if(middleOfRange < topOfRange)
        {
            currentNode->right = GetTreeOfSet(input, middleOfRange+1, topOfRange);
        }
        
        return currentNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
       //start with the middle and fan out 
        
        return GetTreeOfSet(nums, 0, nums.size()-1);
    }
};