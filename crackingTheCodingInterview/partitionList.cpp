//https://leetcode.com/problems/partition-list/submissions/
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
    ListNode* partition(ListNode* head, int x) {
        //move all those greater than x to a new list 
        
        //keep the previous in the right place
        //ensure the new list doesn't point to the old list
        //keep the current iterator going properly
                
        ListNode* greaterListHead = new ListNode(-1);
        ListNode* greaterListCurrent = greaterListHead;
        greaterListHead->next = nullptr;
        
        if(head == nullptr)
        {
            return head;
        }
        
        //handle the first case
        while(head != nullptr && head->val >= x)
        {
            ListNode * temp = head;
            head = head->next;
            greaterListCurrent->next = temp;
            temp->next = nullptr;
            greaterListCurrent = greaterListCurrent->next;
        }
        
        ListNode* current = head;
        
       //work with the next one so you can move the previous to point after it
        while (current != nullptr && current->next != nullptr)
        {
            
            if(current->next->val >= x) //continue working with next
            {
                //get a copy of the item to move
                ListNode* moving = current->next;
                //dereference the moving item from the main list keeping the previous in the right place
                current->next = current->next->next;
                
                //point the destination list to the new item
                greaterListCurrent->next = moving;
                //ensure the new list doesn't point to the old list
                
                //dereference the old list from the moved item
                moving->next = nullptr;
                
                //move the new list along for the next result
                greaterListCurrent = greaterListCurrent->next;
            }
            else
            {
                //keep the current iterator going properly
                current = current->next;
            }
            
        }
        
        //in the case that all were greater than the list, the original list may be null and need to just return the greater list
        if(current != nullptr)
        {
            current->next = greaterListHead->next;
        }
        else
        {
            head = greaterListHead->next;
        }
        
        return head;
    }
};