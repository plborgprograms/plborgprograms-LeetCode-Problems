//https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) 
    {
        if(startPos.size() != 2)
        {
            return vector<int>();
        }
        int row = startPos[0];
        int column = startPos[1];
        
        if(row >= n || column >= n ||
          row < 0 || column < 0)
        {
            return vector<int>();
        }
        
        vector<int> result;
        
        for(int c = 0; c < s.length(); c++)
        {
            row = startPos[0];
            column = startPos[1];
            
            int totalMoves = s.length()-c;
            for(int p = c; p < s.length(); p++)
            {
                switch(s[p])
                {
                    case 'D' :
                        row++;
                        break;
                    case 'U' :
                        row--;
                        break;
                    case 'R' :
                        column++;
                        break;
                    case 'L' :
                        column--;
                        break;
                    Default:
                        //error
                        break;
                }
                if(row >= n || row < 0 ||
                  column >= n || column < 0)
                {
                    totalMoves = (p-c);
                    break;
                }
            }
            //result[c] = totalMoves;
            result.push_back(totalMoves);
        }
        
        return result;
    }
};