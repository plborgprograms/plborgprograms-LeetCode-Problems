//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public int PairSum(ListNode head) {
        ListNode current = head;
        
        List<int> listvalues = new List<int>();
        while(current != null)
        {
            listvalues.Add(current.val);
            current = current.next;
        }
        
        int highestSum = -1000000000;
        
        for(int x = 0; x < listvalues.Count/2; x++)
        {
            if(listvalues[x] + listvalues[listvalues.Count-1-x] > highestSum)
            {
                highestSum = listvalues[x] + listvalues[listvalues.Count-1-x];
            }
        }
        
        return highestSum;
    }
}