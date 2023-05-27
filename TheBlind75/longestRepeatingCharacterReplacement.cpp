//https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
class Solution {
public:
    int characterReplacement(string s, int k) {
        //O(N)
        //iterate over whole array and keep track of letters that match the current character
        //in a queue. Use k to determine which characters could still be reached.
        //if all characters in the related

        if(s.length() < 2)
        {
            return s.length();
        }

        int longestSequence = 1; //assumes size of 2 or more
        
        unordered_map<char, vector<int>> charCoordinates;
        charCoordinates[ s[0] ].emplace_back(0);

        for(int endOfSeries = 1; endOfSeries < s.length(); endOfSeries++)
        {
            charCoordinates[ s[endOfSeries] ].emplace_back(endOfSeries);

			//For explanation:
            //int startOfSeries = charCoordinates[ s[endOfSeries] ][0];
            //int spotsThatNeedToBeReplaced = (endOfSeries - startOfSeries) + 1 - charCoordinates[ s[endOfSeries] ].size();
			
            if(((endOfSeries - charCoordinates[ s[endOfSeries] ][0]) + 1 - charCoordinates[ s[endOfSeries] ].size()) > k)
            {
                while(charCoordinates[ s[endOfSeries] ].size() > 0 && 
                charCoordinates[ s[endOfSeries] ][0]+k < endOfSeries + 1 - charCoordinates[ s[endOfSeries] ].size())
                {
                    charCoordinates[ s[endOfSeries] ].erase(charCoordinates[ s[endOfSeries] ].begin()); //or pop_front
                }
            }

            longestSequence = max(longestSequence, min((int)charCoordinates[ s[endOfSeries] ].size()+k, (int)s.length()));
        }
        
        return longestSequence;
    }
};