//https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
class Solution {
public:
    vector<string> mapping = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length() == 0) 
            return result;
        
        util(digits, result, "",0);
        return result;
    }

    void util(string& digits, vector<string>& res, string currentString, int digitsIter)
    {
        //isFullPermutation (base case)
        if(digitsIter == digits.size())
        {
            res.push_back(currentString);
            return;
        }

        //iterate over results adding each possible char
        for(int i = 0;i<mapping[digits[digitsIter]-'0'].length();i++)
        {
            //get the char from the target string
            /*int stringIndex = digits[digitsIter]-'0';
            string numberString = mapping[stringIndex];
            char currentChar = numberString[i];
            util(digits, res, curRes+ currentChar, digitsIter+1); */ 
            util(digits, res, currentString+ mapping[digits[digitsIter]-'0'][i], digitsIter+1);  
        }
    }

};