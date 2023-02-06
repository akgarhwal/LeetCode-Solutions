/*
Problem Title: 350 - Intersection of Two Arrays II
Lang: C++
Runtime: 0 ms
Memory: 15.7 MB
Problem Url: https://leetcode.com/problems/intersection-of-two-arrays-ii
Submission Url: https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/891664826
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1(10005, 0);
        vector<int> freq2(10005, 0);
        
        vector<int> ans;
        for(int num : nums1) {
            freq1[num]++;
        }
        for(int num : nums2) {
            freq2[num]++;
        }

        for(int i=0; i <=1000; i++ ){
            if(freq1[i] > 0 and freq2[i] > 0) {
                for(int x = 0; x < min(freq1[i], freq2[i]); x++ ) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};