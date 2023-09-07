//https://leetcode.com/problems/middle-of-the-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //O(N/2) or O(N) depending on the interviewer
        //Iterate over the whole list with the fast node.
        //Iterate slow half the times. Fast will iterate
        //O(N) times and slow will iterate O(N/2) times.

        ListNode* slow = head;
        ListNode* fast = head;

        bool odd = 0;
        while(fast->next != nullptr)
        //while(fast != nullptr)
        {
            fast=fast->next;

            odd = !odd;
            if(odd)
            {
                slow = slow->next;
            }
        }
        
        return slow;
    }
};