//https://leetcode.com/problems/merge-k-sorted-lists/submissions/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //O(n log n) for heap operation where n is the total of all elements in lists

        //collapse all the linked lists into one heap and then convert
        //the heap into a linked list. Reduce 'new' operations by making
        //the heap a vector of ListNodes. If the size() of the linked
        //lists had been passed in, this program could have allocated
        //space of the heap to reduce that operation.

        //collapse all linked lists into one heap
        vector<ListNode*> heap;
        auto heapComp = [](ListNode* lhs, ListNode* rhs) { return lhs->val < rhs->val; };
        make_heap(heap.begin(), heap.end(), heapComp);

        ListNode* current = nullptr;

        for(int x = 0; x < lists.size(); x++)
        {
            current = lists[x];
            while(current != nullptr)
            {
                heap.push_back(current);
                push_heap(heap.begin(),heap.end(), heapComp);

                current = current->next;
            }
        }

        //Convert the heap into one linked list
        ListNode* resultHead = nullptr;
        ListNode* nextNode;
        while(heap.size() > 0)
        {
            nextNode = heap.front();
            pop_heap(heap.begin(), heap.end(), heapComp);
            
            heap.pop_back();
            
            nextNode->next = resultHead;
            resultHead = nextNode;
        }

        return resultHead;
    }
};