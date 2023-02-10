/*
Problem Title: 2306 - Naming a Company
Lang: C++
Runtime: 451 ms
Memory: 83.4 MB
Problem Url: https://leetcode.com/problems/naming-a-company
Submission Url: https://leetcode.com/problems/naming-a-company/submissions/894847267
*/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> initialGroup[26];
        for (auto& idea : ideas) {
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        long long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int commonCount = 0;
                for (auto& ideaA : initialGroup[i]) {
                    if (initialGroup[j].count(ideaA)) {
                        commonCount++;
                    }
                }
                answer += 2LL * (initialGroup[i].size() - commonCount) * (initialGroup[j].size() - commonCount);
            }
        }
        return answer;
    }
};