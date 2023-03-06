/*
Problem Title: 2578 - Split With Minimum Sum
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/split-with-minimum-sum
Submission Url: https://leetcode.com/problems/split-with-minimum-sum/submissions/909203386
*/

class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());

        int num1 = 0, num2 = 0;

        for(int i=0; i < str.size(); i++) {

            num1 = num1*10 + (str[i]-'0');
            if(i+1 < str.size()) {
                num2 = num2*10 + (str[i+1]-'0');
                i++;
            }
            
        }

        return num1+num2;
    }
};