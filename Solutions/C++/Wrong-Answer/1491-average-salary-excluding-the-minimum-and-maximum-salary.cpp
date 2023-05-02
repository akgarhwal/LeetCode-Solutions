/*
Problem Title: 1491 - Average Salary Excluding the Minimum and Maximum Salary
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
Submission Url: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/submissions/942452798
*/

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        
        int total = accumulate(salary.begin(), salary.end(), 0);
        total = total - salary[0] - salary[salary.size()-1];
        
        return total/(salary.size()-2);
    }
};