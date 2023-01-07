/*
Problem Title: 380 - Insert Delete GetRandom O(1)
Lang: C++
Runtime: 84 ms
Memory: 23 MB
Problem Url: https://leetcode.com/problems/insert-delete-getrandom-o1
Submission Url: https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/352907862
*/

class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last = arr.back();
        arr[mp[val]]  = last;
        arr.pop_back();
        mp[last] = mp[val];
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */