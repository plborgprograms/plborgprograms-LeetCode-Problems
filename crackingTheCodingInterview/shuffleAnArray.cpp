//https://leetcode.com/problems/shuffle-an-array/submissions/
class Solution {
public:
    vector<int> data;
    //the names requested here are not really accurate
    //these don't actually modify the internal data but
    //rather return either the original or a shuffled 
    //copy of the data.
    //I would rename these to getData() and getShuffledSetOfData()

    Solution(vector<int>& nums) {
        data = nums;
    }
    
    vector<int> reset() {
        return data;
    }
    
	//O(n)
    vector<int> shuffle() {
        vector<int> result(data);
        for(int i = 0; i < result.size(); i++)
        {
            int destination = i + ( rand() % (result.size()-i) );
            swap(result[i], result[destination]);
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */