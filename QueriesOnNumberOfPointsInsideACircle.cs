//https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
public class Solution {
    public int[] CountPoints(int[][] points, int[][] queries) {
        //points exist on the edge of one of the circles
        //queries are the nucleusX, nucleusY, and radius
        
        //for each circle, compute how many points are inside it.
        int[] results = new int[queries.Length];
        for(int c = 0; c < queries.Length; c++)
        {
            results[c] = 0;
            for(int p = 0; p < points.Length; p++)
            {
                /*float xDifference = points[p][0]-queries[c][0];
                float yDifference = points[p][1]-queries[c][1];
                double distance = Math.Sqrt(Math.Pow(xDifference,2) + Math.Pow(yDifference,2));*/
                //return (distance <= cradius);
                //if( WithinCircle(points[p][0], points[p][1], queries[c][0], queries[c][1], queries[c][2]) )
                
                //float xDifference = points[p][0]-queries[c][0];
                //float yDifference = points[p][1]-queries[c][1];
                //double distance = Math.Sqrt(Math.Pow(points[p][0]-queries[c][0],2) + Math.Pow(points[p][1]-queries[c][1],2));
                if(Math.Sqrt(Math.Pow(points[p][0]-queries[c][0],2) + Math.Pow(points[p][1]-queries[c][1],2)) <= queries[c][2])
                {
                    results[c]= results[c]+1;
                }
            }
        }
        
        return results;
    }
    
}