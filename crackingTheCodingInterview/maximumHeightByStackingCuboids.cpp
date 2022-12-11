//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        //sort each cube so that alignment is quick
        for (auto& cube : cuboids)
        {
            sort(begin(cube), end(cube));
        }
        cuboids.push_back({0, 0, 0});

        //sort the cubes to reduce loop complexity
        sort(begin(cuboids), end(cuboids));

        int n = cuboids.size(), res = 0;
        vector<int> dp(n);
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]) {
                    //if cube fits, update the running size and the max
                    dp[j] = max(dp[j], dp[i] + cuboids[j][2]);
                    res = max(res, dp[j]);
                }
            }
        }

        return res;
    }

};