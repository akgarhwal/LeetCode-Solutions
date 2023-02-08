/*
Problem Title: 904 - Fruit Into Baskets
Lang: C++
Runtime: 256 ms
Memory: 78.4 MB
Problem Url: https://leetcode.com/problems/fruit-into-baskets
Submission Url: https://leetcode.com/problems/fruit-into-baskets/submissions/893008340
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = 0, second = 0, ans = 0, N = fruits.size();
        unordered_set<int> st;
        unordered_map<int,int> mp;
        while(first < N) {

            while(second < N and st.size() <= 2) {
                mp[fruits[second]]++;
                st.insert(fruits[second++]);

                if(st.size() > 2){
                    break;
                }
                ans = max(ans, second-first);
            }

            if(mp[fruits[first]] == 1) {
                st.erase(fruits[first]);
            }
            mp[fruits[first]]--;
            first++;
        }

        return ans;
    }
};