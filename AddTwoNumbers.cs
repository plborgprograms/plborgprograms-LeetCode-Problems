using System;
/** https://leetcode.com/problems/add-two-numbers/
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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        //ListNode result = new ListNode();
        //ListNode result = null;
        //ListNode resultCurrent = result;
        ListNode resultCurrent = null;
        ListNode result = null;

        ListNode l1Current = l1;
        ListNode l2Current = l2;
        int remainderFromPrevious = 0;
        while(l1Current != null || l2Current != null)
        {
            //get the total
            int total =  remainderFromPrevious;
            if(l1Current != null)
            {
                total += l1Current.val;
            }
            
            if(l2Current != null)
            {
                total += l2Current.val;
            }
            
            
            if(result == null) //starting the list
            {
            
                //make a new node
                resultCurrent = new ListNode();

                //break the total into the next value and the current value            
                //store the current value
                resultCurrent.val = (int)total%10;
                
                result = resultCurrent;
                
                //resultCurrent = resultCurrent.next;
            }
            else
            {
                resultCurrent.next = new ListNode();
                resultCurrent = resultCurrent.next;

                //break the total into the next value and the current value            
                //store the current value
                resultCurrent.val = (int)total%10;
                                
                //resultCurrent = resultCurrent.next;
            }
            
            //pass on the remainder            
            remainderFromPrevious = (int)Math.Floor( (double)(total/10) );
            Console.WriteLine("remainderFromPrevious is now " + remainderFromPrevious);
            
            if(l1Current != null)
            {
                l1Current = l1Current.next;
            }
            if(l2Current != null)
            {
                l2Current = l2Current.next;
            }
        }
        
        if(remainderFromPrevious > 0)
        {
            //if there's a leftover remainder, add a digit for that.
            resultCurrent.next = new ListNode();
            resultCurrent = resultCurrent.next;
            resultCurrent.val = remainderFromPrevious;
        }
        
        return result;
    }
}