//https://leetcode.com/problems/palindrome-linked-list/submissions/
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
    bool isPalindrome(ListNode* head) {
        //keep track with a midpoint, by moving two iterators
        //Instead
        //while that's going, push the members of the slow pointer onto a stack        
        ListNode* current = head;
        stack<int> backwards;
        
        while(current != nullptr)
        {
            backwards.push(current->val);
            current = current->next;
        }
        
        int originalTotal = backwards.size();
        current = head;
        
        //just check the first half; if there's a middle it'll be the same. (hence middle)
        while(backwards.size() > originalTotal/2)
        {
            if(current->val != backwards.top())
            {
                return false;
            }
            backwards.pop();
            current = current->next;
        }
        
        return true;
    }
};