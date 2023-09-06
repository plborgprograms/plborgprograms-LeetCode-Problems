//https://leetcode.com/problems/ransom-note/submissions/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //O(n)
        //make an array and run through what's available and ensure that you have enough
        //of each letter.

        long arrayLettersAvailable[26];
        long lettersNeededForNote[26];
        for(int x = 0; x < 26; x++)
        {
            arrayLettersAvailable[x] = 0;
            lettersNeededForNote[x] = 0;
        }

        for(int m = 0; m < magazine.length(); m++)
        {
            arrayLettersAvailable[magazine[m]-'a']++;
        }

        for(int r = 0; r < ransomNote.length(); r++)
        {
            lettersNeededForNote[ransomNote[r]-'a']++;
        }

        for(int x = 0; x < 26; x++)
        {
            if(lettersNeededForNote[x] > arrayLettersAvailable[x] )
            {
                return false;
            }
        }        

        return true;
    }
};