//https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
class Solution 
{
public:
    int search(vector<int>& A, int target) 
    {
        int offset=0,hi=A.size()-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(offset<hi)
        {
            int mid=(offset+hi)/2;
            if(A[mid]>A[hi]) 
            {
                offset=mid+1;
            }
            else
            {
                 hi=mid;
            }
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int lo=0;hi=A.size()-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            int realmid=(mid+offset)%A.size();
            if(A[realmid]==target)
            {
                return realmid;
            }
            if(A[realmid]<target)
            {
                lo=mid+1;
            }
            else
            {
                 hi=mid-1;
            }
        }
        return -1;
    }
};