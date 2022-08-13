//https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int currentRowSecurityDevicesCount = 0;
        int previousRowSecurityDevicesCount = 0;
        int total = 0;
        for(int m = 0; m < bank.size(); m++)
        {
            for(int n = 0; n < bank[m].length(); n++)
            {
                if(bank[m].at(n) == '1')
                {
                    currentRowSecurityDevicesCount++;
                }
            }
            if(currentRowSecurityDevicesCount > 0)
            {
                total += currentRowSecurityDevicesCount * previousRowSecurityDevicesCount;
                previousRowSecurityDevicesCount = currentRowSecurityDevicesCount;
            }
            currentRowSecurityDevicesCount = 0;
        }
        
        return total;
    }
};