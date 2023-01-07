/*
Problem Title: 1427 - Perform String Shifts
Lang: C++
Runtime: 0 ms
Memory: 6.7 MB
Problem Url: https://leetcode.com/problems/perform-string-shifts
Submission Url: https://leetcode.com/problems/perform-string-shifts/submissions/324589272
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();
        int index = 0;
        for(auto row : shift){
            if(row[0] == 1){
                // right shift
                index = (index - row[1] + n) % n;
            }
            else{
                // left shift
                index = (index + row[1]) % n;
            }
        }
        string res = s + s;
        return res.substr(index, n);
    }
};