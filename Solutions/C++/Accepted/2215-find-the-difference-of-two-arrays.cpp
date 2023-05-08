/*
Problem Title: 2215 - Find the Difference of Two Arrays
Lang: C++
Runtime: 75 ms
Memory: 35.9 MB
Problem Url: https://leetcode.com/problems/find-the-difference-of-two-arrays
Submission Url: https://leetcode.com/problems/find-the-difference-of-two-arrays/submissions/943546046
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);

        unordered_set<int> hs1, hs2;

        for(int num : nums1) {
            hs1.insert(num);
        }
        for(int num : nums2) {
            hs2.insert(num);
        }

        set<int> temp;

        for(int num : nums1) {
            if(hs2.find(num) == hs2.end()) {
                temp.insert(num);
            }
        }
        
        ans[0] = vector<int> (temp.begin(), temp.end());
        temp.clear();

        for(int num : nums2) {
            if(hs1.find(num) == hs1.end()) {
                temp.insert(num);
            }
        }

        ans[1] = vector<int> (temp.begin(), temp.end());

        return ans;
    }
};