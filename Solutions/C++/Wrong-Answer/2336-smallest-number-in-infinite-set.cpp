/*
Problem Title: 2336 - Smallest Number in Infinite Set
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/smallest-number-in-infinite-set
Submission Url: https://leetcode.com/problems/smallest-number-in-infinite-set/submissions/939473114
*/

class SmallestInfiniteSet {
public:
    unordered_map<int,bool> mp;
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            pq.push(i);
            mp[i] = true;
        }
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        mp[smallest] = false;

        return smallest;
    }
    
    void addBack(int num) {
        if(mp[num] == false) {
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */