//https://leetcode.com/problems/longest-consecutive-sequence/submissions/937314181/
class Solution {
    
public:
int longestConsecutive(vector<int>& num) {
		//O(n)
        //iterate over the numbers and keep a hashmap of totals of the sequence.
        //as you update, update the leftmost and rightmost totals in the hashmap
        //to have the latest total.
        unordered_map<int, int> m;
        int r = 0;
        for (int i : num) {
            if (m[i]) continue;
            //get the new total length and adjust the max, the current value, the leftmost edge, and the rightmost edge
            //                rightmost edge    leftmost edge       new total length
            r = max(r, m[i] = m[i + m[i + 1]]   = m[i - m[i - 1]]   = m[i + 1] + m[i - 1] + 1);
        }
        return r;
    }
    
};