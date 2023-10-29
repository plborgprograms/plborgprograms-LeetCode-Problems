//https://leetcode.com/problems/string-to-integer-atoi/submissions/
class Solution {
public:
    int myAtoi(string s) {
        //O(N)

        int startPoint = -1;
        int endPoint = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ')
            {
                 startPoint = i;
                 break;
            }
        }
        if(startPoint < 0)
        {
            return 0;
        }
        bool positive = s[startPoint] == '+';
        bool negative = s[startPoint] == '-';
        (positive || negative )== true ? startPoint++ : startPoint;
        int j = startPoint;
        double result = 0;
        while(j < s.length() && s[j] >= '0' && s[j] <= '9'){
            result = result*10 + (s[j]-'0');
            j++;
        }
        result = negative ? -result : result;

        result = (result > INT_MAX) ? INT_MAX : result;
        result = (result < INT_MIN) ? INT_MIN : result;

        return int(result);
    }
};