//https://leetcode.com/problems/linked-list-cycle/submissions/942929274/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //O(N)
        //this is a classic tortoise hare algorithm
        //this problem only asks to detect the presence
        //of a cycle not the location.
        ListNode *tortoise = head;
        ListNode *hare = head;

        do
        {
            if(hare == NULL)
            {
                return false;
            }
            hare = hare->next;
            
            if(hare == NULL)
            {
                return false;
            }
            hare = hare->next;
            
            tortoise = tortoise->next;
        }while(tortoise != hare);

        return true;
    }
};