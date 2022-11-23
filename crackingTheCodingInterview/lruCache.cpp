class LRUCache {
public:
    unordered_map<int, int> entries;
    vector<int> cacheQueue;
    int capacity = 0;
    LRUCache(int cap) {
        capacity = cap;
        //preallocate vector with capacity+1
        cacheQueue.reserve(cap+1);
    }
    
    int get(int key) {

        if(entries.find(key) != entries.end())
        {
            auto index = find(cacheQueue.begin(), cacheQueue.end(), key);
            cacheQueue.erase(index);
            cacheQueue.emplace_back(key);

            return entries[key];
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        //if you're replacing a number, erase it
        //and then put it at the back.

        //if it's a new number, add it and see if
        //you need to remove a number
        if(entries[key])
        {
            //move to back of queue
            auto index = find(cacheQueue.begin(), cacheQueue.end(), key);
            cacheQueue.erase(index);
            cacheQueue.emplace_back(key);
        }
        else
        {
            cacheQueue.emplace_back(key);
            if(cacheQueue.size() > capacity)
            {
                entries.erase(cacheQueue[0]);
                cacheQueue.erase(cacheQueue.begin());
            }
        }

        entries[key] = value;
    }
};
