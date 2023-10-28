//https://leetcode.com/problems/time-based-key-value-store/submissions/
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hashmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         hashmap[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
		//O(1)
        auto it = upper_bound(begin(hashmap[key]), end(hashmap[key]), pair<int, string>(timestamp, ""), [](const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });
        return it == hashmap[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */