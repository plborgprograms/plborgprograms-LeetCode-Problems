//https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //iterate over each side simultaneously and put each result on a hashmap 
        //if the result is already on the hashmap, that must be the first result
        
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        
        unordered_map<ListNode*, bool> foundResults;
        
        while(currentA != nullptr || currentB != nullptr)
        {
            if(currentA != nullptr)
            {
                if(foundResults[currentA])
                {
                    return currentA;
                }
                else
                {
                    foundResults[currentA] = true;
                }
                currentA = currentA->next;
            }
            if(currentB != nullptr)
            {
                if(foundResults[currentB])
                {
                    return currentB;
                }
                else
                {
                    foundResults[currentB] = true;
                }
                currentB = currentB->next;
            }
        }
        
        return nullptr;
    }
};