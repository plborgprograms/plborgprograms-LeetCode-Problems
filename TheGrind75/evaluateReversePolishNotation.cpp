//https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/
class Solution {
public:

    bool isOperator(string a)
    {
        return a == "*" || a == "/" || a == "+" || a == "-"; 
    }

    int evalRPN(vector<string>& tokens) {
        
        //convert to stack
        //O(N)
        stack<int> valueStack;
        int total = 0;
        //iterate over the vector
        for(int t = 0; t < tokens.size(); t++)
        {

            if(isOperator(tokens[t]))
            {
                //work with the two just to the left of it
                int b = valueStack.top();
                valueStack.pop();
                int a = valueStack.top();
                valueStack.pop();
                int result = 0;
                //cout << "a:" << a << tokens[t] << "b:" << b << endl;
                if(tokens[t] == "*")
                {
                    result = a * b;
                }
                else if(tokens[t] == "/")
                {
                     result = a / b;
               }
                else if(tokens[t] == "+")
                {
                    result = a + b;
                }
                else//(tokens[t] == "-")
                {
                    result = a - b;
                }
                valueStack.push(result);

            }
            else
            {
                valueStack.push(stoi(tokens[t]));
            }
        }

        return valueStack.top();
    }
    /*int evalRPN(vector<string>& tokens) {
        //slower due to removals from the string but the distance to the end is constantly progressing
        //iterate over the vector
        for(int t = 2; t < tokens.size(); t++)
        {
            
            cout << "t:" << t;
            if(t >= 2)
            {
                cout << ", tokens[t-2]:" << tokens[t-2];
            }
            if(t >= 1)
            {
                cout << ", tokens[t-1]" << tokens[t-1];
            }
            cout << ", tokens[t]" << tokens[t] << endl;
            

            if(t >= 2 && !isOperator(tokens[t-2]) && !isOperator(tokens[t-1]) && isOperator(tokens[t]))
            {
                //work with the two just to the left of it
                if(tokens[t] == "*")
                {
                    tokens[t-2] = to_string(stoi(tokens[t-2]) * stoi(tokens[t-1]));
                    tokens.erase(tokens.begin()+t-1);
                    tokens.erase(tokens.begin()+t-1);
                    t-=2;
                }
                else if(tokens[t] == "/")
                {
                    tokens[t-2] = to_string(stoi(tokens[t-2]) / stoi(tokens[t-1]));
                    tokens.erase(tokens.begin()+t-1);
                    tokens.erase(tokens.begin()+t-1);
                    t-=2;
                }
                else if(tokens[t] == "+")
                {
                    tokens[t-2] = to_string(stoi(tokens[t-2]) + stoi(tokens[t-1]));
                    tokens.erase(tokens.begin()+t-1);
                    tokens.erase(tokens.begin()+t-1);
                    t-=2;
                }
                else if(tokens[t] == "-")
                {
                    tokens[t-2] = to_string(stoi(tokens[t-2]) - stoi(tokens[t-1]));
                    tokens.erase(tokens.begin()+t-1);
                    tokens.erase(tokens.begin()+t-1);
                    t-=2;
                }
            }
        }

        return stoi(tokens[0]);
    }*/
};