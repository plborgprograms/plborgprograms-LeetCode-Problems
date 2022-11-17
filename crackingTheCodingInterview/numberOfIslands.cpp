//https://leetcode.com/problems/number-of-islands/submissions/
//O(N^2)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //find each island and mark all connected
		//spaces using BFS

        int islandsFound = 0;
        //at the end, get the number of islands marked
        //
        for(int row = 0; row < grid[0].size(); row++)
        {
            for(int col = 0; col < grid.size(); col++)
            {
                if(grid[col][row] != '0')
                {
                    islandsFound++;
                    vector<pair<int,int>> nodeQueue;
                    nodeQueue.emplace_back(make_pair(col,row));
                    while(nodeQueue.size() > 0)
                    {
                        pair<int,int> current = nodeQueue[0];
                        cout << current.first << "," << current.second << endl;
                        if( grid[current.first][current.second] != '0')
                        {
                            grid[current.first][current.second] = '0';
                            if(current.first > 0)
                            {
                                nodeQueue.push_back(make_pair(current.first-1, current.second));
                            }
                            if(current.second > 0)
                            {
                                nodeQueue.push_back(make_pair(current.first, current.second-1));
                            }
                            if(current.second < grid[0].size()-1)
                            {
                                nodeQueue.push_back(make_pair(current.first, current.second+1));
                            }
                            if(current.first < grid.size()-1)
                            {
                                nodeQueue.push_back(make_pair(current.first+1, current.second));
                            }
                        }
                        nodeQueue.erase(nodeQueue.begin());
                    }
                }

            }
        }

        return islandsFound;
    }
};