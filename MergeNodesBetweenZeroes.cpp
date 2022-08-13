//https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode* mergeNodes(ListNode* head) {
        //consider an empty list
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* left = head;
        ListNode* current = head->next;
        
        //run across the list and identify when you have a 0
        //delete the nodes as you go;
        //when you find the next 0, place the total
        
        //stretch
        //to reduce 'new' operations, I could replace the first zero value with the total instead
        
        while(current != nullptr)
        {
            if(current->val == 0)
            {
                if(current->next == nullptr)
                {
                    left->next = nullptr;
                    delete current;
                    current = left;
                    break;
                }
                else
                {
                    left = current;
                }
            }
            else
            {
                left->val = left->val + current->val;
                left->next = current->next;
                delete current;
            }
            current = left->next;
        }
        
        
        return head;
    }
};