// https://leetcode.com/problems/top-k-frequent-elements/submissions/
#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>
class Solution {
public:


    vector<int> topKFrequent(vector<int>& nums, int k) {
        //O(n) or expanded as O(3n)
        //put all values into a hashmap and update the count
        //take all the values from the hashmap and put them into a heap
        
        unordered_map<int, long> totalCountOf;
        for(int n = 0; n < nums.size(); n++)
        {
            totalCountOf[ nums[n] ]++;
        }

        vector< pair<int,long> > heap;
        make_heap(heap.begin(), heap.end(), cmp);
        for(auto it:totalCountOf)
        {
            heap.push_back(pair(it.first, it.second));
            push_heap(heap.begin(), heap.end(), cmp);
        }


        vector<int> results;
        for(int i=0;i<k;i++){
            pop_heap(heap.begin(),heap.end()-i,cmp);
            results.emplace_back( heap[heap.size()-1-i].first );
        }
        
        return results;
    }


    static bool cmp(pair<int,long> &a,pair<int,long> &b){
    return a.second<b.second;
}

};