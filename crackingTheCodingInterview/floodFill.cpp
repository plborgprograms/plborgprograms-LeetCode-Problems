//https://leetcode.com/problems/flood-fill/solution/
class Solution {
public:
    
    
    //switched to depth first search because it eliminates the possibility of adding a node that is 
    //already in the queue (or having to check that each loop)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,val,newColor);
        dfs(image,i+1,j,val,newColor);
        dfs(image,i,j-1,val,newColor);
        dfs(image,i,j+1,val,newColor);
    }
    
    /*
	
	vector<pair<int,int>> floodQueue;
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int targetColor) {
        //implementing a breadth first search iteratively
        //disadvantage: this could have multiple nodes add the same pair to the queue and then
        //find it's already done.
        if(image[sr][sc] == targetColor)
        {   //if the sourceColor equals the targetColor, just end it
            return image;
        }
        floodQueue.emplace_back(make_pair(sr, sc));
        
        int sourceColor = image[sr][sc];
        while(floodQueue.size() > 0)
        {
            pair<int, int> currentPair = floodQueue[0];
            spreadFlood(image, currentPair.first, currentPair.second, sourceColor, targetColor);
            floodQueue.erase(floodQueue.begin());
        }
        return image;
    }
    
    void spreadFlood(vector<vector<int>>& image, int row, int col, int sourceColor, int targetColor)
    {
        if(image[row][col] == sourceColor)
        {
            image[row][col] = targetColor;
            
            //up down left right
            if(row > 0 && image[row-1][col] == sourceColor)
            {
                floodQueue.emplace_back(make_pair(row-1, col));
            }
            if(row < image.size()-1 && image[row+1][col] == sourceColor)
            {
                floodQueue.emplace_back(make_pair(row+1, col));
            }
            if(col > 0 && image[row][col-1] == sourceColor)
            {
                floodQueue.emplace_back(make_pair(row, col-1));
            }
            if(col < image[0].size()-1 && image[row][col+1] == sourceColor)
            {
                floodQueue.emplace_back(make_pair(row, col+1));
            }
        }
    }*/
};