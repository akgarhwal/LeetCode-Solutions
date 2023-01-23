/*
Problem Title: 2545 - Sort the Students by Their Kth Score
Lang: C++
Runtime: 102 ms
Memory: 55.9 MB
Problem Url: https://leetcode.com/problems/sort-the-students-by-their-kth-score
Submission Url: https://leetcode.com/problems/sort-the-students-by-their-kth-score/submissions/882774683
*/

class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](vector<int> a, vector<int> b) {
            return a[k] > b[k]; 
        });
        
        return score;
    }
};