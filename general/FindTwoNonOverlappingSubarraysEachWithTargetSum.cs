//https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
public class Solution {
    int shortestLength = 2147483647;
    int secondShortestLength = 2147483647;
    
    public struct result
    {
        public int l;
        public int r;
        public int length;
        public result(int left, int right)
        {
            l = left;
            r = right;
            length = (r - l) +1;
        }
        
        public static int Compare( result resulta, result resultb)
        {
            return resulta.length.CompareTo(resultb.length);
        }
    }
    
    public List<result> allResults;
    
    public int MinSumOfLengths(int[] arr, int target) {
        //iterate over the array and keep the running total that's under or equal to the target number
        
        //subtract the leftmost element from the current total so you don't have to run through it repeatedly
        //example 1,2,3,3         6     => -1
        //example 1,2,3,3,3       6     => 5
        //example 1,2,3,3,0,4,3,3 6     => 4
        //example 1,2,3,3,2,1     6     => 6
        //try reprioritizing to remove the most recent case
        //I need to have a series of cases that I can choose one over the other
        //I need a find a way to choose one over another without eliminating any options
        //find the two results with the lowest total combination and then find if they overlap
        //if they overlap, try switching the larger one and then the smaller one to see which has the smallest total
        int l = 0;
        int currentTotal = 0;// = arr[l];
        allResults = new List<result>();
        
        shortestLength = 2147483647;
        secondShortestLength = 2147483647;
        
        for(int r = 0; r < arr.Length; r++)
        {
            currentTotal += arr[r];
            while(currentTotal > target && l <= r)
            {
                currentTotal -= arr[l];
                l++;
            }
            
            if(currentTotal == target)
            {       
                AddResultToList(l,r);
                
            }
            
        }
        
        
        if(allResults.Count < 2)
        {   ////if there aren't even two valid results, return -1;
            return -1;
        }
        //if there's more than two working
        //iterate over all the results
        //and find the two that give the lowest total
        int lowestTotalLength = 2147483647;
        int tl = 0, tr = allResults.Count-1;
        //while(tl < tr)
        while(tl < allResults.Count && 
              tr >= 0)
        {
            if( (allResults[tl].length + allResults[tr].length ) < lowestTotalLength &&
              !resultsOverLap(allResults[tl], allResults[tr])     )
            {
                lowestTotalLength = allResults[tl].length + allResults[tr].length;
                
            }
            
            if(allResults[tl].length > allResults[tr].length)
            {
                tl++;
                if(tl == tr)
                {
                    tl++;
                }
            }
            else
            {
                tr--;
                 if(tl == tr)
                {
                    tr--;
                }
            }
        }
        
        if(lowestTotalLength == 2147483647)
        {   //if no valid result was found, return -1;
            return -1;
        }
        
        return lowestTotalLength;
    }
    
    private void UpdateLongestLengths(int currentLength, int l, int r)
    {
        //Console.WriteLine("Found a match");
        //int currentLength = (r-l)+1;
        
        
        if( currentLength <= shortestLength)
        {
            secondShortestLength = shortestLength;
            shortestLength = currentLength;
        }
        else if( currentLength <= secondShortestLength)
        {
            secondShortestLength = currentLength;
        }
    }
    
    private void AddResultToList(int l, int r)
    {
        Console.WriteLine("adding entry from " + l + " to " + r);
        allResults.Add(new result(l,r));
    }
    
    private bool resultsOverLap(result resulta, result resultb)
    {
        if( (resulta.l <= resultb.l && resultb.l <= resulta.r) ||
          (resulta.l <= resultb.r && resultb.r <= resulta.r) )
        {
            return true;
        }
        return false;
    }
    
}