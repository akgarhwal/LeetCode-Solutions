/* Question: LRU Cache
 * Lang: cpp
 * Runtime: 560 ms
 * Memory: 37.4 MB
 * Question Url: https://leetcode.com/problems/lru-cache
 * Submission Url: https://leetcode.com/problems/lru-cache/submissions/329727753
 */

class LRUCache {
public:
  int capacity, size;
  unordered_map<int, int> cache;
  list<int> queue;

  LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
  }

  int get(int key) {
    auto it = find(queue.begin(), queue.end(), key);
    if (it == queue.end()) {
      return -1;
    }
    queue.erase(it);
    queue.push_front(key);
    return cache[key];
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      cache[key] = value;
      auto it = find(queue.begin(), queue.end(), key);
      queue.erase(it);
      queue.push_front(key);
      return;
    }
    if (size == capacity) {
      int lru = queue.back();
      queue.pop_back();
      cache.erase(lru);
      size--;
    }
    size++;
    queue.push_front(key);
    cache[key] = value;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */