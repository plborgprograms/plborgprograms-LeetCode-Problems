// https://leetcode.com/problems/word-pattern/submissions/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //break the 's' into individual words
        //iterate over whole list matching the char in pattern
        //to the whole word. If there's a mismatch, return false.
        //Otherwise return true

        vector<string> words = splitStringIntoWords(s);
        
        /*
        cout << "Words:";
        for(int i = 0; i < words.size(); i++)
        {
            cout << words[i] << ",";
        }
        cout << endl;
        */

        //if the lengths have mismatched, the results won't match
        if(words.size() != pattern.length())
        {
            return false;
        }

        //look up word from char. the charDictionary is necessary because both a and b can't 
        //point to the same word
        unordered_map<char, string> wordDictionary; 
        unordered_map<string, char> charDictionary;

        for(int i = 0; i < pattern.length(); i++)
        {
            char current = pattern.at(i);
            if(wordDictionary.find(current) != wordDictionary.end())
            {
                if(wordDictionary[current] != words[i] || charDictionary[words[i]] != current)
                {   //if the letter doesn't match the word or vice versa, return false
                    return false;
                }
            }
            else if(charDictionary.find(words[i]) != charDictionary.end())
            {   //if not found in words dictionary but found in the char dictionary, return false
                return false;
            }
            else
            {
                wordDictionary[current] = words[i];
                charDictionary[words[i]] = current;
            }
        }

        return true;
    }

    //utilities
    vector<string> splitStringIntoWords(string input)
    {
        stringstream iss(input);
        vector<string> output;
        string word;
        while(iss >> word)
        {
            output.push_back(word);
        }

        return output;
    }
    
};