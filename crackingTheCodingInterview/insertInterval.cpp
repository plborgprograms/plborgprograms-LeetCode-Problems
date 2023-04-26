//https://leetcode.com/problems/insert-interval/submissions/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		//O(log n)
        if(intervals.size() == 0)
        {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        //use binary search to search for high in intervals
        //which is greater than or equal to newInterval.low-1

        //also use binary search to find a low in intervals
        //which is less than or equal to newInterval.high-1

        int lowIter = intervals.size()/2;
        int low = 0;
        int high = intervals.size();

        while(low <= high && lowIter >= 0 && lowIter < intervals.size())
        {
            if( newInterval[0]  <= intervals[lowIter][1]  && newInterval[0] >= intervals[lowIter][0] )
            {
                break;
            }
            else if( newInterval[0]  < intervals[lowIter][0]) 
            {
                //handle the edge case if the endpoint lands between intervals
                if(lowIter == 0 || newInterval[0] > intervals[lowIter-1][1])
                {
                    break;
                }
                else
                {   //otherwise, keep searching
                    high = lowIter-1;
                    lowIter = (high + low)/2;
                }
            }
            else
            {

                low = lowIter+1;
                lowIter = (high + low)/2;
            }
            
        }

        //the second has to be higher than the first so we can eliminate most of them
        int highIter = min((lowIter + intervals.size())/2, intervals.size()-1);
        low = lowIter;
        high = intervals.size();

        while(low <= high && highIter >= 0 && highIter < intervals.size() /* && highIter != low && highIter != low*/)
        {
            if( newInterval[1] >= intervals[highIter][0] && newInterval[1] <= intervals[highIter][1] )
            {
                break;
            }
            else if(newInterval[1] > intervals[highIter][1])   
            {
                //handle the edge case if the endpoint lands between intervals
                if(highIter == intervals.size()-1 || newInterval[1] < intervals[highIter+1][0])
                {
                    break;
                }
                else
                {   //otherwise, keep searching
                    low = highIter+1;
                    highIter = (high + low)/2;
                }
            }
            else
            {
                high = highIter-1;
                highIter = (high + low)/2;
            }
        }

        
        //handle the edge case when not merging or overwriting any intervals
        if(newInterval[1] < intervals[0][0])
        {   
            intervals.insert(intervals.begin()+lowIter, newInterval);
        }
        else if(newInterval[0] > intervals[intervals.size()-1][1])
        {
            intervals.insert(intervals.begin()+intervals.size(), newInterval);
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[lowIter][0]);
            newInterval[1] = max(newInterval[1], intervals[highIter][1]);

            intervals.erase(intervals.begin()+lowIter,intervals.begin()+highIter+1);
            intervals.insert(intervals.begin()+lowIter, newInterval);
        }
        
        
        return intervals;
    }
};