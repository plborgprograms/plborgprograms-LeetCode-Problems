//https://leetcode.com/problems/decode-ways/solutions/?orderBy=most_votes
class Solution {
public:
    int numDecodings(string s) {
        //O(n)
        string intsTogether = s;

        //cache the last two numbers and see how many combinations you can get in the end       
        bool previousDidntWorkAsStandalone = false;
        int previousTotal = 1;
        int previousTotal2 = 1;

        for(int a = intsTogether.length()-1; a >= 0; a--)
        {
            int currentOptions = 0;
            if( previousDidntWorkAsStandalone || a < intsTogether.length()-1)
            {
                if( stoi(intsTogether.substr(a,2)) <= 26 && stoi(intsTogether.substr(a,2) ) >= 1 && intsTogether[a] != '0')
                {
                    currentOptions+= previousTotal2;
                }
            }

            //try the current number standalone or with others
            bool worksAsStandalone = stoi(intsTogether.substr(a,1)) > 0 && stoi(intsTogether.substr(a,1)) < 10;
            if(worksAsStandalone)
            {
                currentOptions += previousTotal;
            }

            previousTotal2 = previousTotal;
            previousTotal = currentOptions;
            previousDidntWorkAsStandalone = !worksAsStandalone;
        }

        return previousTotal;
    }
};