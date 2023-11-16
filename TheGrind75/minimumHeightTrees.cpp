//https://leetcode.com/problems/minimum-height-trees/submissions/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //O(n) where n= edges.size()
        //iterate over a star graph and destroy external nodes until you reach the center
        vector<vector<int>> graph(n);
        vector<int> connections(n,0);

        vector<int> result;
        if(n==1) 
        {
            result.push_back(0);
            return result;
        }

        //build the graph
        for(int e = 0; e < edges.size(); e++)
        {
            graph[edges[e][0]].push_back(edges[e][1]);
            graph[edges[e][1]].push_back(edges[e][0]);
            connections[edges[e][0]]++;
            connections[edges[e][1]]++;
        }

        queue<int> remainingNodes;

        //start with the leaf nodes (nodes with only one connection)
        for(int i = 0; i < n; i++)
        {
            if(connections[i] == 1)
            {
                remainingNodes.push(i);
                connections[i]--;
            }
        }

        //iterate over the queue decrementing the number of connections for each node
        //only add nodes that are at the new edge with one remaining connection
        //the final one or two nodes will be the result
        while(!remainingNodes.empty())
        {
            int queueSize = remainingNodes.size();
            result.clear();
            for(int i = 0; i < queueSize; i++)
            {
                int current = remainingNodes.front(); remainingNodes.pop();
                result.push_back(current);

                for(int c = 0; c < graph[current].size(); c++)
                {
                    connections[graph[current][c]]--;
                    if(connections[graph[current][c]] == 1)
                    {
                        remainingNodes.push(graph[current][c]);
                    }
                }
                
            }
        }
        return result;

       
    }
};