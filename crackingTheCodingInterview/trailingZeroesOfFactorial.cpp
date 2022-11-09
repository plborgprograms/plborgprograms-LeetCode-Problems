//https://leetcode.com/problems/factorial-trailing-zeroes/solutions/?orderBy=most_votes
class Solution {
public:
    int trailingZeroes(int n) {
		//this algorithm works by counting the number of 10s in the product
		//since 2s come up much more frequently than 5s (every 2 vs every 5)
		//this just counts the 5s.
        if (n == 0)
        {
            return 0;
        }
        else
        {
			//return the number of 0s in the current product
			//plus the number of 0s in all following products
            return n/5 + trailingZeroes(n / 5);
        } 
    }
};