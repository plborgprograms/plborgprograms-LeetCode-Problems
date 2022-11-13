//https://leetcode.com/problems/max-points-on-a-line/description/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //iterate over all combinations in a nested for loop finding the slope between each pair
        //if one has more intersections, choose that

        if(points.size() < 2)
        {   //handle empty and one entry cases
            return points.size();
        }
 
        int mostIntersections = 0;
        for(int a = 0; a < points.size(); a++)
        {   
            unordered_map<double, int> intersections;
            for(int b = a+1; b < points.size(); b++)
            {   //get the slope and add it to the map
                double slope = getSlope(points[a], points[b]);

                //if it's negative infinity, make it positive infinity; they're effectively the same
                slope = (slope == -1.0/0.0) ? (1.0/0.0) : slope;

                //start counting at 2 (2 points in an intersection); if the current count is higher than the highest, reset the highest
                intersections[slope] = intersections[slope] ? intersections[slope]+1 : 2;
                mostIntersections = (intersections[slope] > mostIntersections) ? intersections[slope] : mostIntersections;
            }
        }

        return mostIntersections;
    }

    double getSlope(vector<int> point1, vector<int> point2)
    {
        return (double)(point2[1]-point1[1])/(double)(point2[0]-point1[0]);
    }
};