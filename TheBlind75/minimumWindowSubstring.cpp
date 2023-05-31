//https://leetcode.com/problems/minimum-window-substring/submissions/
class Solution {
public:
    string minWindow(string s, string t) {
        //O(N)
        //iterate over this and keep a hashmap
        //of coordinates of the latest found.
        //Keep it like a circular queue and dequeue
        //the earliest entry as it becomes unnecessary

        unordered_map<char, int> target;
        for(int i = 0; i < t.length(); i++)
        {
            target[t[i]]++;
        }
        unordered_map<char, int> remaining(target);

        unordered_map<char, vector<int>> letters;

        vector<bool> includedInResult(s.length(), false);
        //vector
        int startOfSeries = 0;
        int bestSeriesStart = -1;
        int bestSeriesFinish = INT_MAX;

        bool foundSomeCriteria = false;

        for(int i = 0; i < s.length(); i++)
        {
            if(target[s[i]] > 0)
            {
                foundSomeCriteria = true;
                letters[s[i]].emplace_back(i);
                includedInResult[i] = true;

                if(letters[s[i]].size() > (int)target[s[i]])
                {
                    //update start of series
                    includedInResult[letters[s[i]][0]] = false;
                    while(!includedInResult[startOfSeries])
                    {
                        startOfSeries++;
                    }

                    //update relevant information
                    letters[s[i]].erase( letters[s[i]].begin() );
                }
                else
                {
                    remaining[s[i]]--;
                    if(remaining[s[i]] <= 0)
                    {
                        remaining.erase(s[i]);
                    }
                }

                if(remaining.size() <= 0)
                {
                    if(bestSeriesStart < 0)
                    {
                        bestSeriesFinish = i;
                        bestSeriesStart = startOfSeries;
                    }
                    else if(i - startOfSeries < bestSeriesFinish - bestSeriesStart)
                    {
                        bestSeriesFinish = i;
                        bestSeriesStart = startOfSeries;
                    }
                }

            }
            else if(!foundSomeCriteria)
            {
                startOfSeries++;
            }
        }

        //for the result, keep the min coordinate and
        //max coordinate within the hashmap

        //when returning, return substring(s, minimumcoordinate, maximumcoordinate);
        string result = "";
        if(bestSeriesFinish > -1 && bestSeriesStart > -1)
        {
            result = s.substr(bestSeriesStart, bestSeriesFinish - bestSeriesStart+1);
        }

        return result;
    }

};