//using System.Collections.Generic;
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

public class Solution {
    
    //example: abcbd
    public int LengthOfLongestSubstring(string s) {
        
        //Create a data structure that can be used here.
        //use a hashmap
        
        int longestSequence = 0;
        
        //one for the char, the other for the index of where it was last encountered
        Dictionary<char, int> chars = new Dictionary<char, int>();
        
        int startOfCurrentSequence = 0;
        for(int i = 0; i < s.Length; i++)
        {            
            //if the current character is already in the hash keep the char length the same and move the start to the next time that char was encountered
            int searchResult = -1;
            //if( chars.ContainsKey(s[i]) )
            if( chars.TryGetValue(s[i], out searchResult) )
            {
                //if the last time this was found was in the current sequence, move the current sequence to right after that
                if(searchResult+1 > startOfCurrentSequence)
                {
                    //move the start of the sequence forward 1 from where the previous instance of that char is
                    startOfCurrentSequence = searchResult+1;
                }
            }
            
            //iterate over the whole solution and add to a hash.
            //chars.Add(s[i], i);
            chars[ s[i] ] = i;
            
            int lengthOfCurrentSequence = 1 + i - startOfCurrentSequence;
            if( lengthOfCurrentSequence > longestSequence)
            {
                longestSequence = lengthOfCurrentSequence;
            }
        }
        
        return longestSequence;
    }
}