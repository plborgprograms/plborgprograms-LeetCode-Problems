//https://leetcode.com/problems/word-break/submissions/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        //O(s^2)
        //Make an unordered_map (hashmap) of all words in wordDict
        //iterate over the whole word and find if the substring of i to j
        //can be a word
        //check if there's a complete string from the previous character
        //to here. if so, set it to true
        //ensure that every character gets used and start and endpoints
        //go from the start to finish
        //if start-1 is true, then set the end to be true
        vector<bool> dp(s.length());

        unordered_map<string, bool> wordHashmap;
        for(int w = 0; w < wordDict.size(); w++)
        {
            wordHashmap[wordDict[w]] = true;
        }

        
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j < s.length(); j++)
            {
                //cout << "checking:" << s.substr(i,1+j-i) << endl;
                if( wordHashmap.find(s.substr(i,1+j-i)) != wordHashmap.end() &&
                (i == 0 || dp[i-1]))
                {
                    dp[j] = true;
                }
            }
        }

        /*for(int i = 0; i < s.length(); i++)
        {
            cout << dp[i] << ",";
        }
        cout << endl;*/

        return dp[s.length()-1];
    }
};