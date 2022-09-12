//https://leetcode.com/problems/kth-largest-element-in-an-array/

public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        //declare sortedList (heap)
        //add the elements 
        //get the last element
        PriorityQueue<int, int> bestElements = new PriorityQueue<int, int>();
        
        for(int x = 0; x < nums.Length; x++)
        {
            if(bestElements.Count < k )
            {
                bestElements.Enqueue(nums[x], nums[x]);
                Console.WriteLine("adding:" + nums[x]);
            }
            else if(nums[x] > (int)bestElements.Peek())
            {
                Console.WriteLine("adding:" + nums[x] + " and ");
                bestElements.Enqueue(nums[x],nums[x]);
                bestElements.Dequeue();
            }
        }
        
        return (int)bestElements.Peek();
    }
    
    /*
    public int FindKthLargest(int[] nums, int k) {
        //declare sortedList (heap)
        //add the elements 
        //get the last element
        SortedList bestElements = new SortedList();
        
        for(int x = 0; x < nums.Length; x++)
        {
            if(bestElements.Count < k )
            {
                bestElements.Add((Guid)nums[x], nums[x]);
                Console.WriteLine("adding:" + nums[x]);
            }
            else if(nums[x] > (int)bestElements.GetByIndex(0))
            {
                Console.WriteLine("adding:" + nums[x] + " and ");
                bestElements.Add((Guid)nums[x],nums[x]);
                Console.WriteLine("removing:" + (int)bestElements.GetByIndex(0) );
                bestElements.RemoveAt(0);
            }
        }
        
        return (int)bestElements.GetByIndex(0);
    }
    */
}