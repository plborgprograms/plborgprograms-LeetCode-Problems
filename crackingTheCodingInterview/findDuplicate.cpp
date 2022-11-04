class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        //this question was designed to be a tortoise and hare solution
        //by only allowing results in the range of [1, n]. This is a
        //commonly used algorithm but only works in scenarios such as
        //this.
        int tortoise = nums[0];
        int hare = nums[0];

		//toroise and hare algorithms work by looping until you find a looping
		//caused by having a second number pointing to the same index as a previous
		//one, a duplicate. One iterator traverses an array twice as fast as another
		//and when they intersect, you restart. They both then move at the same 
		//speed. They can't intersect moving at the same speed unless they are both
		//at the duplicate point either from entering the loop or from standing on
		//separate same nodes.
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);

        tortoise = nums[0];
        while(tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};