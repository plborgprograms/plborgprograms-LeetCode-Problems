//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
        {
            return "[]";
        }
        //O(N)
        //take each node in a queue and add
        //each of its children to the queue
        //add the current node to the result
        //if the node is null, just add null.

        string result = "[";
        //make a queue and queue/dequeue from it
        queue<TreeNode*> nodesToAdd;
        nodesToAdd.push(root);
        while(nodesToAdd.size() > 0)
        {
            TreeNode* nextNode = nodesToAdd.front();
            if(nextNode == nullptr)
            {
                result += "null,";
            }
            else
            {
                result += to_string(nextNode->val) + ",";
                nodesToAdd.push(nextNode->left);
                nodesToAdd.push(nextNode->right);
            }
            nodesToAdd.pop();
        }
        //change the last char from a comma to a ']'
        result[result.length()-1] = ']';

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> values = stringToVector(data);
        if(values.size() == 0)
        {
            return nullptr;
        }

        //O(N)
        //break up the string and verify that it's not
        //empty. Take nodes in pairs and assign the
        //parent node to those values to connect them

        queue<TreeNode*> newTargets;
        TreeNode* result = new TreeNode(values[0]);
        newTargets.push( result );

        int v = 1;
        while(newTargets.size() > 0 && v < values.size() )
        {
            if(values[v] == nullValue)
            {
                newTargets.front()->left = nullptr;
            }
            else
            {
                newTargets.front()->left = new TreeNode(values[v]);
                newTargets.push(newTargets.front()->left);
            }
            v++;

            if(values[v] == nullValue)
            {
                newTargets.front()->right = nullptr;
            }
            else
            {
                newTargets.front()->right = new TreeNode(values[v]);
                newTargets.push(newTargets.front()->right);
            }
            v++;

            newTargets.pop();
        }

        while(newTargets.size() > 0 )
        {
            newTargets.front()->left = nullptr;
            newTargets.front()->right = nullptr;
            newTargets.pop();
        }

        return result;
    }

    int nullValue = -10000;
    vector<int> stringToVector(string str) {
        vector<int> result;
        stringstream ss(str.substr(1, str.size() - 2));
        string token;
        while (getline(ss, token, ',')) {
            if (token == "null") {
                result.push_back(nullValue);
            } else {
                result.push_back(stoi(token));
            }
        }
    return result;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));