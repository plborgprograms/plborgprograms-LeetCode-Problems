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
};