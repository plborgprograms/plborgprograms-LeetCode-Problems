// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
        {
            return nullptr;
        }
        //run through the preorder tree, adding to the tree in that order
        //use the node's index to determine if it's on the left or right of a node
        //create an array of the added nodes
        //create a list of node with child openings and determine which it should be attached to.


        //inorder added nodes
        vector<TreeNode*> addedNodes(preorder.size(), nullptr);

        //O(n)
        unordered_map<int, int> indexOfValueInInorderVector;
        for(int i = 0; i < inorder.size(); i++)
        {
            indexOfValueInInorderVector[ inorder[i] ] = i;
        }

        //O(n)
        vector<int> PreOrderToinorderIndex;
        for(int p = 0; p < preorder.size(); p++)
        {
            //explanation:
            //int thisCellsValue = preorder[p];
            //int indexOfThisValueInInorder = indexOfValueInInorderVector[ thisCellsValue ];
            //PreOrderToinorderIndex.emplace_back( indexOfThisValueInInorder );

            PreOrderToinorderIndex.emplace_back( indexOfValueInInorderVector[ preorder[p] ]);
        }

        queue<TreeNode*> destinations;
        //insert from preorder
        TreeNode* root = new TreeNode(preorder[0]);
        addedNodes[ PreOrderToinorderIndex[0] ] = root;

        //O(N*ln(N))
        for(int p = 1; p < preorder.size(); p++)
        {
            TreeNode* newNode = new TreeNode(preorder[p]);
            TreeNode* nodeToTheLeft = getNodeToTheLeft(PreOrderToinorderIndex[p], addedNodes);
            if(nodeToTheLeft != nullptr && nodeToTheLeft->right == nullptr) 
            {
                nodeToTheLeft->right = newNode;

                //update addedNodes
                addedNodes[ PreOrderToinorderIndex[p] ] = newNode;
            }
            else
            {
                TreeNode* nodeToTheRight = getNodeToTheRight(PreOrderToinorderIndex[p], addedNodes);
                nodeToTheRight->left = newNode;
                //update addedNodes
                addedNodes[ PreOrderToinorderIndex[p] ] = newNode;
            }

            //printNodes(addedNodes);

        }

        return root;        
    }

    TreeNode* getNodeToTheLeft(int startpoint, vector<TreeNode*> addedNodes)
    {
        for(int l = startpoint-1; l >= 0; l--)
        {
            if(addedNodes[l] != nullptr)
            {
                return addedNodes[l];
            }
        }

        return nullptr;
    }

    TreeNode* getNodeToTheRight(int startpoint, vector<TreeNode*> addedNodes)
    {
        for(int r = startpoint+1; r < addedNodes.size(); r++)
        {
            if(addedNodes[r] != nullptr)
            {
                return addedNodes[r];
            }
        }

        return nullptr;
    }


};