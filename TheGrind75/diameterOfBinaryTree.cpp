//https://leetcode.com/problems/diameter-of-binary-tree/submissions/
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
    int longest = 0;
    int diameterOfBinaryTree(TreeNode* root) {
		//O(N)
        //create a variable to store the longest diameter
        //in each of these, return the longer of the two branches
        //and use that for larger scale diameters.
        longest = 0;
        longestOfSubtree(root);
        return longest;
    }

    int longestOfSubtree(TreeNode* root)
    {
        if(root == nullptr)
        {
            return -1;
        }
        int lengthOfLeft = longestOfSubtree(root->left)+1;
        int lengthOfRight = longestOfSubtree(root->right)+1;

        longest = max(longest, lengthOfLeft+lengthOfRight);

        return max(lengthOfLeft, lengthOfRight);
    }
};