//https://leetcode.com/problems/implement-rand10-using-rand7/description/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
		//My initial impression was to run rand7() 10 times and get the sum
		//divided by 10 but that did not result in the same answers in all
		//test cases so this is another solution.
		//0-39 is uniform. If it's more than that, reroll the dice.
		
		
        int result = 40;
        while (result >= 40) 
        {
            result = 7 * (rand7() - 1) + (rand7() - 1);
        }
        return result % 10 + 1;
    }
};