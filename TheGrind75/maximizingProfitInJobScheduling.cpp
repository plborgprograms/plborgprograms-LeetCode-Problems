//https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/
class Solution {

    class entry
    {
        public:
        int start = 0;
        int end = 0;
        int profit = 0;

        entry(int s, int e, int p)
        {
            start = s;
            end = e;
            profit = p;
        }
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //O(N) or O(N^2) if counting sorting algorithms
        //DP
        //sort the entries, use dynamic programming to find the optimal use of the set
        
        //because these are unsorted, a helper class is created to sort them together,
        //valueToIndex is used to find the appropriate index,

        //because there can be gaps in the millions, the dynamic programming vector
        //will only go over values found in the startTime and endTime vectors 
        //using a vector called foundValues.

        //the edge cases  really changed the solution to this problem.
        //I may use a recursive solution with dp/memoization in the future

        vector<entry*> entries;

        unordered_map<int,bool> encountered;

        vector<int> foundValues;
        foundValues.emplace_back(0);

        //O(N)
        for(int i = 0; i < startTime.size(); i ++)
        {
            entries.emplace_back(new entry(startTime[i], endTime[i], profit[i]));

            if(encountered.find(startTime[i]) == encountered.end() )
            {
                encountered[startTime[i]] = true;
                foundValues.emplace_back(startTime[i]);
            }
            if(encountered.find(endTime[i]) == encountered.end() )
            {
                encountered[endTime[i]] = true;
                foundValues.emplace_back(endTime[i]);
            }
        }

        //O(N^2) or O(N logN); some interviewers have simplified this to O(N^2)
        sort(foundValues.begin(), foundValues.end());
        unordered_map<int,int> valueToIndex;
        for(int f = 0; f < foundValues.size(); f++)
        {
            valueToIndex[foundValues[f]] = f;
        }

        sort(entries.begin(), entries.end(), [](const entry* lhs, const entry* rhs){return lhs->start < rhs->start;});

        //set a vector's maximum size to the endpoint of the vector
        vector<int> dp(foundValues.size(), 0);

        int maxEndedValue = 0;
        int e = 0;
        //iterate over the vector using dp to find the totals as you go
        //O(2N) aka startTimes.size() + endTimes.size()
        for(int f = 0; f < dp.size(); f++)
        {
            int i = foundValues[f];
            maxEndedValue = max(maxEndedValue, dp[f]);
            dp[f] = maxEndedValue;
            //O(N) over all iterations 
            while( e < entries.size() &&  entries[e]->start == i )
            {
                int currentEntryStart = entries[e]->start, currentEntryEnd = entries[e]->end, currentProfit = entries[e]->profit;
                int maxWithEntry = currentProfit + maxEndedValue;
                dp[valueToIndex[currentEntryEnd]] = max(dp[valueToIndex[currentEntryEnd]], maxWithEntry);
                e++;
            }
        }

        return dp[dp.size()-1];
    }
};