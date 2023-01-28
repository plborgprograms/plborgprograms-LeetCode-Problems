//https://leetcode.com/problems/climbing-stairs/submissions/
class Solution {
public:
    int climbStairs(int n) {
		//O(n)
		
        //this is effectively a fibonacci sequence.
        //Caching with a vector could also work effectively for reuse
		//with the way leetcode runs, I don't believe it would be reused
		//for following test cases.
        
        if(n <= 0)
        { 
            return 0;
        }
        if(n == 1)
        {
            return 1;
        } 
        if(n == 2)
        {
            return 2;
        } 
        
        int oneStepBack = 2;
        int twoStepsBack = 1;
        int ways = 0;
        
        for(int x=2; x<n; x++){
            ways = oneStepBack + twoStepsBack;
            twoStepsBack = oneStepBack;
            oneStepBack = ways;
        }
        return ways;

        //in typical dynamic programming style
        /*
        int* ways = new int[n+1];

        ways[0] = 1;
        ways[1] = 1;
        for(int x = 2; x <= n; x++)
        {
            ways[x] = ways[x-1] + ways[x-2];
        }

        return ways[n];
        */
    }
};