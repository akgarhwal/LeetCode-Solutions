/*
Problem Title: 989 - Add to Array-Form of Integer
Lang: C++
Runtime: 35 ms
Memory: 28.7 MB
Problem Url: https://leetcode.com/problems/add-to-array-form-of-integer
Submission Url: https://leetcode.com/problems/add-to-array-form-of-integer/submissions/898179470
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int i = 0, c = 0, temp = 0;
        vector<int> ans;

        while(k > 0) {
            int d = k % 10;
            temp = (i >= num.size() ? 0 :  num[i]) + d + c;

            ans.push_back(temp%10);

            c = temp/10;
            k = k/10;
            i++;
        }

        while( i < num.size()){
            ans.push_back((c + num[i])%10);
            c = (c + num[i])/10;
            i++;
        }

        if(c > 0) {
            ans.push_back(c);
        }


        reverse(ans.begin(), ans.end());
        return ans;
    }
};