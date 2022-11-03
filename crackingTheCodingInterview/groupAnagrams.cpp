//https://leetcode.com/problems/group-anagrams/submissions/
class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        //build a hashmap using the sorted string as a key
        std::unordered_map<string, vector<string>> AnagramsThatMatch;
        
        for(int x = 0; x < strs.size(); x++)
        {
            //sort the string so that each word which is an anagram
            //of another will end up in the same vector
            string sortedString = strs[x];
            sort(sortedString.begin(), sortedString.end());
            
            AnagramsThatMatch[sortedString].emplace_back(strs[x]);
        }
        
        vector<vector<string>> results;
        for (auto it = AnagramsThatMatch.begin(); it != AnagramsThatMatch.end(); ++it)
        {
            results.emplace_back(it->second);
        }
        return results;
    }
};