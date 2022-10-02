//https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/
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
	//delete a node in the list without being given the first node 
    void deleteNode(ListNode* node) {
        //I could just set this node to the next node's value and skip the next node and delete it
        //O(1)
        //4->5->1->9
        //4->1->(del)->9
        if(node->next != nullptr)
        {
            node->val = node->next->val;
            ListNode* toBeDeleted = node->next;
            node->next = node->next->next;
            delete toBeDeleted;
        }
        else
        {
            delete node;
        }
    }
};