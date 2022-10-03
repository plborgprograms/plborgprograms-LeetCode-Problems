//https://leetcode.com/problems/linked-list-cycle-ii/submissions/
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
    ListNode *detectCycle(ListNode *head) {
        //do a tortoise and hare algorithm
        //let fast move 2 while slow moves 1, if they meet, there's a loop
        //then start the slow at the beginning and you'll find the loop 
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        
        if(fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
        
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};