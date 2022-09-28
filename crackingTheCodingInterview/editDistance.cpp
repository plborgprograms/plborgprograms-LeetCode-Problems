//https://leetcode.com/problems/edit-distance/
class Solution {

public:
    int minDistance(string word1, string word2) {
      vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    
      int i = 0, j = 0;
      
      
      for(int c = word2.size(); c >= 0; c--)
      {
          dp[word1.size()][c] = word2.size()-c;
      }
      
      for(int r = word1.size(); r >= 0; r--)
      {
          dp[r][word2.size()] = word1.size()-r;
      }
      
      
      for(int c = word2.size()-1; c >= 0; c--)
      {
          for(int r = word1.size()-1; r >= 0; r--)
          {
              if(word1[r] == word2[c])
              {
                  dp[r][c] = dp[r+1][c+1];
              }
              else
              {
                  int replace = dp[r+1][c+1] + 1; 
                  int del = dp[r+1][c] + 1; 
                  int add = dp[r][c+1] + 1; 
                  
                  dp[r][c] = min(replace, min(del, add));
              }
          }
      }
      
      for(int c = 0; c < word2.size()+1; c++)
      {
          for(int r = 0; r < word1.size()+1; r++)
          {
             cout << dp[r][c] << ",";
          }
          cout << endl;
      }
      
      
      
      return dp[0][0];  
  }
};