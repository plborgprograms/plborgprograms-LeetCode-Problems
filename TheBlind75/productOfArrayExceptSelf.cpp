//https://leetcode.com/problems/product-of-array-except-self/submissions/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //O(n)
        //get the product of all numbers to the left and
        //product of all numbers to the right multiply left and
        // right and return the result

        //Note: if the data is not pre-allocated in the vectors,
        //the algorithm will fail for TLE. emplace_back() is
        // that expensive.

        vector<int> leftProduct(nums);

        int runningTotal = 1;
        for(int l = 0; l < nums.size(); l++)
        {
            leftProduct[l] = runningTotal;
            runningTotal = runningTotal * nums[l];
        }

        vector<int> rightProduct(nums);

        runningTotal = 1;
        for(int r = nums.size()-1; r >= 0; r--)
        {
            rightProduct[r] = runningTotal;
            runningTotal = runningTotal * nums[r];
        }

        vector<int> results(nums);

        for(int i = 0; i < nums.size(); i++)
        {
            results[i] = (leftProduct[i] * rightProduct[i]);
        }

        return results;
    }

    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        //O(n)
        //occam's razor solution
		//(Question calls for no division so this isn't allowed)
        long long totalProduct = 1;
        vector<int> result;
        bool areZeroes = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                totalProduct = totalProduct * nums[i];
            }
            else
            {
                if(areZeroes)
                {   
                    //return array of zeroes
                    return vector<int>(size(nums));
                }
                areZeroes = true;
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(areZeroes)
            {
                if(nums[i] == 0)
                {
                    result.emplace_back(totalProduct);
                }
                else
                {
                    result.emplace_back(0);
                }
            }
            else
            {
                result.emplace_back(totalProduct/nums[i]);
            }
        }

        return result;
    }
    */
};