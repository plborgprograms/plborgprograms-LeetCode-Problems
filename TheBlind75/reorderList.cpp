// https://leetcode.com/problems/reorder-list/submissions/
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

    ListNode* reverseList(ListNode* head) {
        //O(N)
        ListNode* current = head;
        ListNode* resultHead = nullptr;

		//create a temp to keep track of iterator
		//put the node at the front of the result linked list.
        while(current != nullptr)
        {
            ListNode* temp = current;
            current = current->next;

            temp->next = resultHead;
            resultHead = temp;
        }

        return resultHead;
    }

    void reorderList(ListNode* head) {
        
        //O(N)
        //find the midpoint by iterating one pointer two steps and 
        //another pointer one step. Take the second half of the 
        //linked list and separate it into its own linked list and 
        //reverse its order. Finally, /merge the two linked lists
        //with one element from each list


        //find the midpoint by iterating one pointer two steps and 
        //another pointer one step
        ListNode* halfwayPoint;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr)
        {
            fast = fast->next;
            if(fast == nullptr)
            {
                break;
            }
            fast = fast->next;
            slow = slow->next;

        }

        halfwayPoint = slow->next;
        slow->next = nullptr;

        //take the second half of the linked list and separate it
        //into its own linked list and reverse its order
        ListNode* secondHalf = reverseList(halfwayPoint);

        //merge the two linked lists with one element from each list
        ListNode* current = head;
        ListNode* backCurrent = secondHalf;

        while(current != nullptr && backCurrent != nullptr)
        {
            ListNode* moved = backCurrent;
            backCurrent = backCurrent->next;

            //move the back node in between the two nodes in current
            moved->next = current->next;
            current->next = moved;
            current = moved->next;

        }

    }
};