//https://leetcode.com/problems/add-binary/submissions/
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        int i;
        int carry = 0;
        for(i = 0; i < a.length() || i < b.length(); i++)
        {
            int c = carry;
            int aIndex = a.length()-i;
            if(aIndex > 0)
            {
                c += a[aIndex-1]-'0';
            }
            int bIndex = b.length()-i;
            if(bIndex > 0)
            {
                c += b[bIndex-1]-'0';
            }

            if(c > 1)
            {
                carry = 1;
                c = c%2;
            }
            else
            {
                carry = 0;
            }

            char r = '0' + c;
            result = r + result; 
        }

        if(carry > 0)
        {
            char r = '0' + carry;
            result = r + result; 
        }


        return result;
    }
};