//https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //O(N+P+26); this is linear so it is typically simplified to O(N)
        
        //find the total of the chars
        //keep an integer total of the count of different letters that match totals
        //As you iterate, update the number of totals that match. if the 

        if(p.length() > s.length())
        {
            return {};
        }
        
        int totalsThatMatch = 0;
        int totalsThatNeedToMatch = 0;

        int targetTotals[26] = {0};
        
        //get the totals of the target
        for(int i = 0; i < p.length(); i++)
        {
            int newLetterIndex = p[i]-'a';
            targetTotals[newLetterIndex]++;
        }

        //iterate over the alphabet and find the totals that need to match that are not 0
        for(int i = 0; i < 26; i++)
        {
            if(targetTotals[i] > 0)
            {
                totalsThatNeedToMatch++;
            }
        }

        int searchTotals[26] = {0};
        vector<int> result;

         //iterate over the string you're searching and update the totals
         //decrementing the letter that is removed from the slide and
         //incrementing the new letter that is added to the slide

        //shorthand
        for(int i = 0; i < s.length(); i++)
        {
            if(i >= p.size())
            { 
                if(searchTotals[s[i-p.length()]-'a'] == targetTotals[s[i-p.length()]-'a'])
                {
                    totalsThatMatch--;
                }
                searchTotals[s[i-p.length()]-'a']--;
            }

            searchTotals[s[i]-'a']++;
            if(searchTotals[s[i]-'a'] == targetTotals[s[i]-'a'])
            {
                totalsThatMatch++;
            }

            if(totalsThatMatch == totalsThatNeedToMatch)
            {
                result.emplace_back(1+i-p.length()); //start of the string
            }
        }


         //expounded
       /*for(int i = 0; i < s.length(); i++)
        {
            if(i >= p.size())
            {
                int oldLetterIndex = s[i-p.length()]-'a';
                bool wasMatching = searchTotals[oldLetterIndex] == targetTotals[oldLetterIndex];
                searchTotals[oldLetterIndex]--;
                if(wasMatching)
                {
                    totalsThatMatch--;
                }
            }

            int newLetterIndex = s[i]-'a';
            searchTotals[newLetterIndex]++;
            bool isMatching = searchTotals[newLetterIndex] == targetTotals[newLetterIndex];
            if(isMatching)
            {
                totalsThatMatch++;
            }

            if(totalsThatMatch == totalsThatNeedToMatch)
            {
                result.emplace_back(1+i-p.length()); //start of the string
            }
        }*/

        return result;

    }
};