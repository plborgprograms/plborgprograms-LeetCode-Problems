//https://leetcode.com/problems/counting-bits/description/
class Solution {
public:
    vector<int> countBits(int n) {
		//O(n^2)
		//or the number of 1s in every number between 0 and n

        //convert the index into binary
        //count the number of 1s in the index
        vector<int> result;
        for(int i = 0; i <= n; i++)
        {
            result.emplace_back(hammingWeight(i));
        }

        return result;
    }

    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n) //end the loop when all '1's have been dropped
        {
            n &= (n-1); //find the next '1' and subtract 1 there
            result++;
        }
        return result;
    }
};