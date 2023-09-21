//https://leetcode.com/problems/k-closest-points-to-origin/submissions/
class Solution {
public:
    struct point
    {
        public:
        vector<int> points;
        double distance = 0;
        point(vector<int> p)
        {
            points = p;
            distance = sqrt(pow(points[0],2)+pow(points[1],2));
        }
    };
    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
		//O(N)
        //make a heap of objects
        vector<point> pointsHeap;
        auto keepLowestDistance = [](point lhs, point rhs) { return lhs.distance < rhs.distance; };
        make_heap(pointsHeap.begin(), pointsHeap.end(),keepLowestDistance);

        //iterate over the whole vector and cache the distance
        for(int p = 0; p < points.size(); p++)
        {
            point newPoint(points[p]);
            pointsHeap.push_back(newPoint);
            push_heap(pointsHeap.begin(), pointsHeap.end(),keepLowestDistance);
            if(pointsHeap.size() > k)
            {
                pop_heap(pointsHeap.begin(), pointsHeap.end(),keepLowestDistance);
                pointsHeap.pop_back();
            }

        //update the heap as you go
        }

        //extract the results for the return type
        vector<vector<int>> results;
        for(int r = 0; r < pointsHeap.size(); r++)
        {
            results.push_back(pointsHeap[r].points);
        }

        return results;
    }
};