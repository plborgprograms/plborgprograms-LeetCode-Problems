//https://leetcode.com/problems/basic-calculator-ii/solutions/?orderBy=most_votes
class Solution {
public:
    int calculate(string s) {
        vector<char> operations;
        vector<int> numbers;
        //remove spaces
        for(int c = 0; c < s.size(); c++)
        {
            if(s[c] == '*' || s[c] == '/' || s[c] == '+' || s[c] == '-' )
            {
                operations.emplace_back(s[c]);
            }
            else if( s[c] >= '0' && s[c] <= '9')
            {
                int start = s[c];
                int length = 0;
                while(s[c+length] >= '0' && s[c+length] <= '9')
                {
                    length++;
                }
                //cout << "parsing:" << s.substr(c, length) << endl;
                int newnum = stoi( s.substr(c, length) );
                numbers.emplace_back(newnum);

                c+=length-1;
            }
        }
        /*
        cout << "operations:";
        for(int a = 0; a < operations.size(); a++)
        {
            cout << operations[a] << ",";
        }

        cout << "\nnumbers:";
        for(int a = 0; a < numbers.size(); a++)
        {
            cout << numbers[a] << ",";
        }*/

        //parse

        //do multiplication
        //do divisions
        for(int o = 0; o < operations.size(); o++)
        {
            if(operations[o] == '*')
            {
                numbers[o] = numbers[o] * numbers[o+1];
                operations.erase(operations.begin()+o); 
                numbers.erase(numbers.begin()+o+1);
                o--;
            }
            else if(operations[o] == '/')
            {
                numbers[o] = numbers[o] / numbers[o+1];
                operations.erase(operations.begin()+o); 
                numbers.erase(numbers.begin()+o+1);
                o--;
            }
        }

        //do additions
        //do subtractions
        for(int o = 0; o < operations.size(); o++)
        {
            if(operations[o] == '+')
            {
                numbers[o] = numbers[o] + numbers[o+1];
                operations.erase(operations.begin()+o); 
                numbers.erase(numbers.begin()+o+1);
                o--;
            }
            else if(operations[o] == '-')
            {
                numbers[o] = numbers[o] - numbers[o+1];
                operations.erase(operations.begin()+o); 
                numbers.erase(numbers.begin()+o+1);
                o--;
            }
        }
        //return 0;
        return numbers[0];
    }
};