//https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    vector<int> previousResults {0, 1, 1};
    int tribonacci(int n) {
        if(n < previousResults.size())
        {
            return previousResults[n];
        }
        int result = (tribonacci(n-1) + 
               tribonacci(n-2) +
               tribonacci(n-3));
        
        previousResults.emplace_back(result);
        return result;
    }
};