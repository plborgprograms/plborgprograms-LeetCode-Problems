//https://leetcode.com/problems/max-increase-to-keep-city-skyline/
public class Solution {
    public int MaxIncreaseKeepingSkyline(int[][] grid) {
        
        int[] columnHighest = new int[grid.Length];
        int[] rowHighest = new int[grid.Length];
        int result = 0;

        
        for(int x = 0; x < grid.Length; x++)
        {
            for(int y = 0; y < grid[x].Length; y++)
            {
                if(grid[x][y] > columnHighest[x])
                {
                    columnHighest[x] = grid[x][y];
                }
                if(grid[x][y] > rowHighest[y])
                {
                    rowHighest[y] = grid[x][y];
                }
            }
        }
        
        //string log = "";
        for(int x = 0; x < grid.Length; x++)
        {
            
            for(int y = 0; y < grid[x].Length; y++)
            {
                /*if(rowHighest[y] < columnHighest[x])
                {
                    result += rowHighest[y] - grid[x][y];
                }
                else
                {
                    result += columnHighest[x] - grid[x][y];
                }*/
                result += Math.Min( rowHighest[y], columnHighest[x]) - grid[x][y];
            }
        }
        
        
        return result;
    }
}