/*
Problem Title: 904 - Fruit Into Baskets
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/fruit-into-baskets
Submission Url: https://leetcode.com/problems/fruit-into-baskets/submissions/893007680
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = 0, second = 0, ans = 0, N = fruits.size();
        set<int> st;
        map<int,int> mp;
        while(first < N) {

            while(second < N and st.size() <= 2) {
                mp[fruits[second]]++;
                st.insert(fruits[second++]);

                if(st.size() > 2){
                    break;
                }
                ans = max(ans, second-first);
                cout<<first<<" - "<<second<<endl;
            }

            if(mp[fruits[first]] == 1) {
                st.erase(fruits[first]);
            } else {
                mp[fruits[first]]--;
            }
            first++;
        }

        return ans;
    }
};