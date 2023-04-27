//https://leetcode.com/problems/merge-intervals/submissions/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //O(n log n) due to quick sort. Loop is only O(n)

        //iterate over the vector, merging adjacent intervals if they overlap

        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size()-1; i++)
        {
            if(intervals[i][1] >= intervals[i+1][0])
            {
                //merge intervals
                intervals[i][1] = max(intervals[i][1],intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);

                //roll iterator back one to compare current interval to following item
                i--;
            }
        }

        return intervals;
    }
};