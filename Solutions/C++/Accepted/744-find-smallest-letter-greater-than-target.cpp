/*
Problem Title: 744 - Find Smallest Letter Greater Than Target
Lang: C++
Runtime: 18 ms
Memory: 15.8 MB
Problem Url: https://leetcode.com/problems/find-smallest-letter-greater-than-target
Submission Url: https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/887786118
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(target >= letters[n-1]){
            return letters[0];
        }
        
        int lo = 0, hi = n;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(letters[mid] > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return letters[lo];
    }
};