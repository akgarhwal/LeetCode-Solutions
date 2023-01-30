/*
Problem Title: 460 - LFU Cache
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/lfu-cache
Submission Url: https://leetcode.com/problems/lfu-cache/submissions/887145313
*/

class LFUCache {
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int size = 0;
    list<pair<int,int>> li;
public:
    LFUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            list<pair<int,int>>::iterator it = mp[key];
            int val = (*it).second;
            li.erase(it);
            li.push_front({key, val});
            mp[key] = li.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(li.size() == size){
            auto it = li.back();
            mp.erase(it.second);
            li.pop_back();
        }
        li.push_front({key, value});
        mp[key] = li.begin();
        cout<<key<<" = "<<value<<endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */