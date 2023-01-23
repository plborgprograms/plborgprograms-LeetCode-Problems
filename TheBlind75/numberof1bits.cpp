//https://leetcode.com/problems/number-of-1-bits/submissions/
class Solution {
public:
    int hammingWeight(uint32_t n) {
		//O(n)
        int result = 0;
        while(n) //end the loop when all '1's have been dropped
        {
            n &= (n-1); //find the next '1' and subtract 1 there
            result++;
        }
        return result;
    }
};