//https://leetcode.com/problems/generate-parentheses/submissions/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //all sets should be well formed as long as the counts of left and right are equal
        //and there are never more closing paranthesies than opening while forming this
        innerFunction(0, 0, "", n);
        return results;
    }
    
    vector<string> results;
    
    void innerFunction(int leftCount, int rightCount, string currentString, int n)
    {
        if(leftCount == n  && rightCount == n)
        {
            results.emplace_back(currentString);
        }
        
        bool okToAddRightParen = (leftCount > rightCount);
        
        if(leftCount < n)
        {
            innerFunction(leftCount+1, rightCount, currentString+"(", n);
        }
        
        if(rightCount < n && okToAddRightParen)
        {
            innerFunction(leftCount, rightCount+1, currentString+")", n);
        }
        
    }
    
};