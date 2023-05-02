//https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //O(M*N)
        
        vector<vector<int>> result;

        vector<vector<int>> canFlowToPacific(heights.size(), vector<int>(heights[0].size(), false) );
        vector<vector<int>> canFlowToAtlantic(heights.size(), vector<int>(heights[0].size(), false) );

        queue<tuple<int,int>> pacificFlowQueue;
        queue<tuple<int,int>> atlanticFlowQueue;
        vector<vector<int>> addedToqueue(heights.size(), vector<int>(heights[0].size(), false) );

        for(int col = 0; col < heights.size(); col++)
        {
            tuple<int,int> coordinate = make_tuple(col,0);
            canFlowToPacific[col][0] = true;
            addedToqueue[col][0] = true;
            pacificFlowQueue.push(coordinate);

        }
        for(int row = 1; row < heights[0].size(); row++)
        {
            tuple<int,int> coordinate = make_tuple(0,row);
            canFlowToPacific[0][row] = true;
            addedToqueue[0][row] = true;
            pacificFlowQueue.push(coordinate);
        }
        
        //iterate over matrix marking each coordinate that will flow to the atlantic using breadth first search
        //if an adjacent flows to the atlantic and this is higher, mark that this one also flows to the pacific
        while(pacificFlowQueue.size() > 0)
        {
            tuple<int,int> current = pacificFlowQueue.front(); pacificFlowQueue.pop();
            int col = get<0>(current); int row = get<1>(current);
            int currentHeight = heights[col][row];
            AddBasedOnFlow(col-1, row, currentHeight, heights, addedToqueue, canFlowToPacific, pacificFlowQueue);
            AddBasedOnFlow(col+1, row, currentHeight, heights, addedToqueue, canFlowToPacific, pacificFlowQueue);
            AddBasedOnFlow(col, row-1, currentHeight, heights, addedToqueue, canFlowToPacific, pacificFlowQueue);
            AddBasedOnFlow(col, row+1, currentHeight, heights, addedToqueue, canFlowToPacific, pacificFlowQueue);
        }

        vector<vector<int>> addedToAtlanticQueue(heights.size(), vector<int>(heights[0].size(), false) );

        for(int col = 0; col < heights.size(); col++)
        {
            tuple<int,int> coordinate = make_tuple(col,heights[0].size()-1);
            canFlowToAtlantic[col][heights[0].size()-1] = true;
            addedToAtlanticQueue[col][heights[0].size()-1] = true;
            atlanticFlowQueue.push(coordinate);
        }
        for(int row = 0; row < heights[0].size()-1; row++)
        {
            tuple<int,int> coordinate = make_tuple(heights.size()-1,row);
            canFlowToAtlantic[heights.size()-1][row] = true;
            addedToAtlanticQueue[heights.size()-1][row] = true;
            atlanticFlowQueue.push(coordinate);
        }

        while(atlanticFlowQueue.size() > 0)
        {
            tuple<int,int> current = atlanticFlowQueue.front(); atlanticFlowQueue.pop();
            int col = get<0>(current); int row = get<1>(current);
            int currentHeight = heights[col][row];
            AddBasedOnFlow(col-1, row, currentHeight, heights, addedToAtlanticQueue, canFlowToAtlantic, atlanticFlowQueue);
            AddBasedOnFlow(col+1, row, currentHeight, heights, addedToAtlanticQueue, canFlowToAtlantic, atlanticFlowQueue);
            AddBasedOnFlow(col, row-1, currentHeight, heights, addedToAtlanticQueue, canFlowToAtlantic, atlanticFlowQueue);
            AddBasedOnFlow(col, row+1, currentHeight, heights, addedToAtlanticQueue, canFlowToAtlantic, atlanticFlowQueue);
            if(canFlowToPacific[col][row])
            {
                vector<int> newEntry = {col,row};
                result.emplace_back(newEntry);
            }
        }
        //sort(result.begin(), result.end());
        return result;
    }

        void AddBasedOnFlow(int col, int row, int currentHeight, vector<vector<int>> heights, 
        vector<vector<int>> &addedToqueue, vector<vector<int>>& canFlow, queue<tuple<int,int>>& flowQueue)
    {
        if(col >= 0 && row >= 0 && col < heights.size() && row < heights[0].size())
        {
            if(!addedToqueue[col][row] && currentHeight <= heights[col][row] )
            {
                addedToqueue[col][row] = true;
                canFlow[col][row] = true;
                flowQueue.push(make_tuple(col,row));
            }
        }
    }
};