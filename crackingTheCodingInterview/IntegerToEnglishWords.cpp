//https://leetcode.com/problems/integer-to-english-words/submissions/
class Solution {
public:

    //data for strings
    string ones[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string Tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string Hundreds[10] = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};
    string Teens[10] ={"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string largeNumbers[10] = {"Thousand", "Million", "Billion", "Trillion", "Quadrillion"}; //this can be extended as needed

    string numberToWords(int num) {
        string result = "";
        if(num == 0)
        {
            return "Zero";
        }
        int loopNumber = num;
        int numberLength = 0;

        do
        {
            //use largeNumberCounter for thousands, millions, billions,
            numberLength++;
            string* arrayToUse;
            int numberIndex = loopNumber % 10;
            
            if(numberLength % 3 == 1 && loopNumber < num && (loopNumber) % 1000 != 0 )
            {   //print thousand (only if there is a one, ten, or hundred other than 0 in the next 3 digits)
                result = " " + largeNumbers[(numberLength/3)-1] + result;
            }

            arrayToUse = determineArrayToUse(numberLength, loopNumber);
            if(arrayToUse[numberIndex] != "")
            {   //print if there's something to print
                result = " " + arrayToUse[numberIndex] + result;
            }

            loopNumber = loopNumber /10;
            if(arrayToUse == Teens)
            {   //skip over the next one since it's already covered as a teen
                loopNumber = loopNumber /10;
                numberLength++;
            }
        }while(loopNumber > 0); 

        return result.substr(1); //remove the leading space and return it
    }

    string* determineArrayToUse(int numberLength, int loopNumber)
    {
        if(numberLength % 3 == 1)
        {
            //check the next number and determine if you should use teens or ones for this array
            return ((loopNumber/10) % 10) == 1 ? Teens : ones;
        }
        else if(numberLength % 3 == 2)
        {
            return Tens;
        }
        else
        {
            return Hundreds;
        }
    }
};