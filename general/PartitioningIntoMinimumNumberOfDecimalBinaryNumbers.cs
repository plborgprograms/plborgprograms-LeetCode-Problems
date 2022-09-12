//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
public class Solution {
    public int MinPartitions(string n) {
        //this seems to just be a question of what is the highest digit in here.
        char[] digits = n.ToCharArray();
        Array.Sort(digits);
        return digits[digits.Length-1] - '0';
    }
}