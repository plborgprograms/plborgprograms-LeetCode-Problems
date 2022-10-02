//https://leetcode.com/problems/add-two-numbers-ii/submissions/
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
		//make two stacks and use those to handle the offset case;
        stack<int> l1Stack;
        stack<int> l2Stack;
        
        ListNode* l1current = l1;
        while(l1current != nullptr)
        {
            l1Stack.push(l1current->val);
            l1current = l1current->next;
        }
        
        ListNode* l2current = l2;
        while(l2current != nullptr)
        {
            l2Stack.push(l2current->val);
            l2current = l2current->next;
        }
        
        int carry = 0;
        
        ListNode* resultHead = new ListNode(0);
        ListNode* resultCurrent = resultHead;
        while(l1Stack.size() > 0 || l2Stack.size() > 0)
        {
            int currentDigit = carry;
            if(l1Stack.size() > 0)
            {
                currentDigit += l1Stack.top();
                l1Stack.pop();
            }
            if(l2Stack.size() > 0)
            {
                currentDigit += l2Stack.top();
                l2Stack.pop();
            }
            
            carry = floor(currentDigit /10);
            ListNode * newNode = new ListNode(currentDigit%10);
            newNode->next = resultCurrent->next;
            resultHead->next = newNode;
        }
        
        if(carry > 0)
        {
            ListNode * newNode = new ListNode(carry);
            newNode->next = resultCurrent->next;
            resultHead->next = newNode;
        }
        
        return resultHead->next;
    }
};