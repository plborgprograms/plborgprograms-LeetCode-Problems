//https://leetcode.com/problems/string-compression/submissions/
class Solution {
public:
    int compress(vector<char>& chars) {
        string input(chars.begin(), chars.end());
        vector<char> result;
        
        int runningTotal = 0;
        for(int x = 0; x < chars.size(); x++)
        {
            runningTotal++;
            //check if this is the end of the streak
            if(x < chars.size()-1 && chars[x+1] != chars[x])
            {
                cout << "line 14\n";
                result.emplace_back(chars[x]);
                if(runningTotal > 1)
                {
                    //result.emplace_back(runningTotal.ToCharArray());
                    //copy(to_string(runningTotal).c_str(), to_string(runningTotal).c_str(), back_inserter(result));
                    //result.push_back(to_string(runningTotal).c_str());
                    cout << "line 21\n";
                    string rt = to_string(runningTotal);
                    const char *str = rt.c_str();
                    for(int s = 0; s < rt.length(); s++)
                    {
                        result.emplace_back(str[s]);
                    }
                    cout << "emplaced " << runningTotal << "\n";
                }
                runningTotal = 0;
            }
            else if (x == chars.size()-1  )
            {
                cout << "line 29\n";
                result.emplace_back(chars[x]);
                if(runningTotal > 1)
                {
                    //copy(to_string(runningTotal).begin(), to_string(runningTotal).end(), back_inserter(result));
                    //result.push_back(to_string(runningTotal).c_str());
                    cout << "line 35\n";
                    //result.insert(result.end(), to_string(runningTotal).c_str(), to_string(runningTotal).c_str() + to_string(runningTotal).size());
                    string rt = to_string(runningTotal);
                    const char *str = rt.c_str();
                    for(int s = 0; s < rt.length(); s++)
                    {
                        result.emplace_back(str[s]);
                    }
                    cout << "emplaced " << runningTotal << "\n";
                }
                runningTotal = 0;
            }
            
        }
        
        cout << "returning result";
        chars = result;
        return result.size();
    }
};