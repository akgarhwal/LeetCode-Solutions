/*
Problem Title: 692 - Top K Frequent Words
Lang: C++
Runtime: 25 ms
Memory: 12.7 MB
Problem Url: https://leetcode.com/problems/top-k-frequent-words
Submission Url: https://leetcode.com/problems/top-k-frequent-words/submissions/775129726
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ht;
        
        for(string word : words) {
            ht[word] += 1;
        }
        
        auto compare = [](const pair<string, int> &a, const pair<string, int> &b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> pq(compare);
        for(auto it = ht.begin(); it != ht.end(); it++){
            pq.push({it->first, it->second});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};