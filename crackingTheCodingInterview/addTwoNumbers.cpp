//https://leetcode.com/problems/add-two-numbers/submissions/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = new ListNode(0);
        ListNode* resultIter = result;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int newTotal = 0;
            
            newTotal += (l1 == nullptr ? 0 : l1->val);
            newTotal += (l2 == nullptr ? 0 : l2->val);
            newTotal += carry;

            resultIter->next = new ListNode( newTotal%10 );
            resultIter = resultIter->next;
            carry = ( newTotal/10 );

            l1 = (l1 == nullptr ? l1 : l1->next);
            l2 = (l2 == nullptr ? l2 : l2->next);
        }
        
        if(carry > 0)
        {
            resultIter->next = new ListNode( carry );
        }
        
        return result->next;
    }
};