//https://leetcode.com/problems/clone-graph/submissions/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //where n is the number of links, O(n)
        if(node == nullptr)
        {
            return nullptr;
        }

        Node* result = new Node();

        //set up a queue of nodes to visit for copy. setup a hashmap so that they don't get visited more than once
        queue<Node*> visitQueue;
        queue<Node*> copiedQueue;
        unordered_map<int, Node*> enqueued;

        visitQueue.push(node);
        copiedQueue.push(result);

        enqueued[visitQueue.front()->val] = copiedQueue.front();

        while(visitQueue.size() > 0)
        {
            Node* copyFrom = visitQueue.front(); visitQueue.pop();
            Node* copyTo = copiedQueue.front(); copiedQueue.pop();
            copyTo->val = copyFrom->val;
            for(int n = 0; n < copyFrom->neighbors.size(); n++)
            {
                //if the node hasn't been put in the queue, add it to the queue
                //if the node hasn't been created, declare a new node, otherwise,
                //point to the node that was already made there.
                if(enqueued.find(copyFrom->neighbors[n]->val) == enqueued.end())
                {
                    //add the link to this node
                    copyTo->neighbors.emplace_back(new Node());

                    //enqueue that node to visit
                    visitQueue.push(copyFrom->neighbors[n]);
                    copiedQueue.push(copyTo->neighbors[n]);

                    //mark that this node has been worked on
                    enqueued[copyFrom->neighbors[n]->val] = copyTo->neighbors[n];
                }
                else
                {
                    //add the link to this node
                    copyTo->neighbors.emplace_back(enqueued[copyFrom->neighbors[n]->val]);
                }
                
            }

        }


        return result;
    }
};