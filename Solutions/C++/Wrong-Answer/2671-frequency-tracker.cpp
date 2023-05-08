/*
Problem Title: 2671 - Frequency Tracker
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/frequency-tracker
Submission Url: https://leetcode.com/problems/frequency-tracker/submissions/946022853
*/

class FrequencyTracker {
public:
    unordered_map<int, int> mp1, mp2;
    FrequencyTracker() {
    }
    
    void add(int number) {
        mp1[number] += 1;
        int freq = mp1[number];
        if(freq != 1) {
            mp2[freq-1] -= 1;
        }
        mp2[freq] += 1;
    }
    
    void deleteOne(int number) {
        if(mp1.find(number) == mp1.end()) {
            return;
        }
        mp1[number] -= 1;
        int freq = mp1[number];
        mp2[freq+1] -= 1;
        mp2[freq] += 1;
    }
    
    bool hasFrequency(int frequency) {
        return mp2[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */