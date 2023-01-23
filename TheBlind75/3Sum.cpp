//https://leetcode.com/problems/3sum/
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		//Using 3 for a combination: O(N^2)
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());

        //this is the last index of each unique value
        unordered_map<int, int> hash;
        for(int h = 0; h < nums.size(); h++)
        {
            hash[nums[h]] = h;
        }

        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for(int j = i+1; j < nums.size()-1; j++)
            {
                int k = -1*(nums[i]+nums[j]);
                if(hash.count(k) && hash[k] > j)
                {
                    //cout << "adding result\n";
                    vector<int> result = { nums[i], nums[j], k };
                    results.emplace_back(result);
                }
                j = hash[nums[j]]; //jump j to the next unique number
            }
            i = hash[nums[i]]; //jump i to the next unique number
        }

       
        
        return results;
    }

};