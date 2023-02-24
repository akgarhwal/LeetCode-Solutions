/*
Problem Title: 502 - IPO
Lang: C++
Runtime: 220 ms
Memory: 82 MB
Problem Url: https://leetcode.com/problems/ipo
Submission Url: https://leetcode.com/problems/ipo/submissions/903627969
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> q;

        int index = 0;
        for (int i = 0; i < k; i++) {
            while (index < n && projects[index].first <= w) {
                q.push(projects[index++].second);
            }
            if (q.empty()) {
                break;
            }
            w += q.top();
            q.pop();
        }
        
        return w;
    }
};