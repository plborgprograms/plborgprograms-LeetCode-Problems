// https://leetcode.com/problems/accounts-merge/submissions/
class Solution {
public:

    //unordered_map<long, vector<string> database; //the first element of each vector will be the first name

    vector<int> parent;
    vector<vector<string>> database;
    unordered_map<string, long> emailLookup;

    unordered_map<long, vector<string>> accountMap;

    int getOriginParent(int index)
    {
        //cout << "searching for:" << index << " while size is:" << parent.size() << endl;
        int i = index;
        while(i != parent[i])
        {
            i = parent[i];
        }

        return i;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //O(n^2) due to getOriginParent 
        //make a hashmap of accounts and add them together

        //iterate over the list and add each email to the hashmap
        //find if any of the emails are already taken. If so, add them
        //to that hashmap

        for(int a = 0; a < accounts.size(); a++)
        {
            string firstName = accounts[a][0];

            parent.emplace_back(a);
            //find any matching keys
            for(int e = 1; e < accounts[a].size(); e++)
            {
               if(emailLookup.find(accounts[a][e]) != emailLookup.end())
                {
                    //get the minimum of the two and set them both to that
                    int j = getOriginParent(emailLookup[accounts[a][e]]);
                    int k = getOriginParent(parent[parent.size()-1]);
                    parent[max(j,k)] = min(j,k);
                    emailLookup[accounts[a][e]] = min(j,k);
                }
                else
                {
                    emailLookup[accounts[a][e]] = parent[parent.size()-1];
                }
             }

        }

        unordered_map<string, bool> added;
        vector<vector<string>> results;
        for(int d = 0; d < parent.size(); d++)
        {
            int origin = getOriginParent(d);
            
            if(accountMap.find(origin) == accountMap.end())
            {
                accountMap[origin] = vector<string>();
                accountMap[origin].emplace_back(accounts[d][0]);
            }
            for(int i = 1; i < accounts[d].size(); i++)
            {
                if(added.find(accounts[d][i]) == added.end())
                {
                    accountMap[origin].emplace_back(accounts[d][i]);
                }
                added[accounts[d][i]] = true;
            }

        }
    
        for ( unordered_map<long, vector<string>>::const_iterator it = accountMap.begin(); it != accountMap.end(); ++it)
        {
            if(it->second.size() > 0)
            {
                results.emplace_back(it->second);
                sort(results[results.size()-1].begin()+1, results[results.size()-1].end());
            }
        }

        return results;


    }
};