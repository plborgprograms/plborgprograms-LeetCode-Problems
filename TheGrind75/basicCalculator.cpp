// https://leetcode.com/problems/basic-calculator/submissions/
class Solution {
public:

int calculate(string s) {
	//O(N)
	
    int n = s.size();
    int res = 0, num = 0;
    stack<int> st;
    st.push(1);

    int sign = 1;

    for (int i = 0; i < n; i++) 
    {
        if (s[i] >= '0' && s[i] <= '9') 
        {    //update the number in progress
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '+' || s[i] == '-') 
        {   //update the total and the current sign
            res += st.top() * sign * num;
            sign = (s[i] == '+') ? 1 : -1;
            num = 0;
        } else if (s[i] == '(') 
        {
            //setup the operator to affect all items in the parenthesis
            st.push(sign * st.top());
            sign = 1;
        } else if (s[i] == ')') 
        {
            //update the total and remove the top sign
            res += st.top() * sign * num;
            st.pop();
            sign = 1;
            num = 0;
        }
    }
    res += sign * num;
    return res;
}

    
};