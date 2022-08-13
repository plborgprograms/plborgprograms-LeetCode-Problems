/**
 * From https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* frontNode = head;
        int totalNodes = 0;
        while(frontNode != nullptr)
        {
            frontNode = frontNode->next;
            totalNodes++;
        }
        int beforeRemovalNodeIndex = totalNodes - n;
        if(beforeRemovalNodeIndex == 0)
        {
            ListNode * result = head->next;
            delete head;
            return result;
        }
        
        ListNode* beforeRemovalNode = head;
        for(int x = 1; x < beforeRemovalNodeIndex; x++)
        {
            beforeRemovalNode = beforeRemovalNode->next;
        }
        
        ListNode* toBeRemoved = beforeRemovalNode->next;
        beforeRemovalNode->next = toBeRemoved->next;
        
        delete toBeRemoved;
            
        return head;
        
    }
};