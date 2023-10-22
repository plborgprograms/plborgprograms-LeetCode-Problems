//https://leetcode.com/problems/combination-sum/submissions/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //O(N^2) brute force solution
        vector<vector<int>> results;
        vector<int> subset;

        GetResultsFromSubset(candidates,results,subset, 0, target);
        return results;
    }

    void GetResultsFromSubset(vector<int>& candidates, vector<vector<int>>& results, vector<int>& subset, int continuationPoint, int target)
    {
        if(target == 0)
        {
            results.push_back(subset);
        }

        for(int i = continuationPoint; i < candidates.size(); i++)
        {
            if(target-candidates[i] >= 0 )
            {
                subset.push_back(candidates[i]);
                GetResultsFromSubset(candidates,results, subset, i, target-candidates[i] );
                subset.pop_back();
            }
        }
    }
};