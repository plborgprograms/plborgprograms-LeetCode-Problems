//https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/
cclass Solution {
public:
    
    /// main logic or trick for this problem : bahar se andar ki taraf jao
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //iterate over the 2d array from each side
        //if an adjacent cell is higher than the current cell
        //and hasn't been visited, recur and mark it as flowing
        //to that ocean

        vector<vector<int>>ans;
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            //check the top and bottom cells
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);
        }
        
        for (int j = 0; j < n; j++) {
            //check the left most and rightmost cells
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m-1, j);
        }

        //find cells where both are true
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (pacific[i][j] && atlantic[i][j]) // agar uss particular point se dono oceans mai jaa paa rahe hai
                    ans.push_back({i,j});           // toh answer push kardo
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {
        
        int m = h.size();
        int n = h[0].size();

        //mark that this cells flows to the ocean
        vis[i][j] = true;

        //check adjacent cells if they are 
        // in domain, and not visted        and they're height is greater than this one's
        //up
        if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
            dfs(h, vis, i-1, j);
        //down
        if (i+1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
            dfs(h, vis, i+1, j);
        //left
        if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
            dfs(h, vis, i, j-1);
        //right
        if (j+1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
            dfs(h, vis, i, j+1);

    }
};