//https://leetcode.com/problems/first-bad-version/submissions/
class Solution {
public:
    int firstBadVersion(int n) 
    {
        //O(log2n)
        //This is effectively a binary search problem

        long lastGoodVersion = 1;    //aka low
        long mid = n/2;
        long firstBadVersion = n;       //aka high
        do
        {
            if(isBadVersion(mid))
            {
                firstBadVersion = mid-1;
                mid = (firstBadVersion + lastGoodVersion) /2;
            }
            else
            {
                lastGoodVersion = mid+1;
                mid = (firstBadVersion + lastGoodVersion) /2;
            }
        }while(lastGoodVersion <= firstBadVersion);

        return firstBadVersion+1;
    }
};