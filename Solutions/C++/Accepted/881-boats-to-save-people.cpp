/*
Problem Title: 881 - Boats to Save People
Lang: C++
Runtime: 88 ms
Memory: 42 MB
Problem Url: https://leetcode.com/problems/boats-to-save-people
Submission Url: https://leetcode.com/problems/boats-to-save-people/submissions/927202594
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int first = 0, last = people.size()-1, ans = 0;

        while(first <= last) {
            if(people[first] + people[last] <= limit) {
                first += 1;
                last -= 1;
            } else {
                last -= 1;
            }
            ans += 1;
        }

        return ans;
    }
};