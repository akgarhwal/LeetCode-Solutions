/*
Problem Title: 1071 - Greatest Common Divisor of Strings
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/greatest-common-divisor-of-strings
Submission Url: https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/889080864
*/

class Solution {
public:
    bool isDivideStr(string str, string x){
        for(int i=0; i <str.size(); i++) {
            if(str[i] != x[(i%(int(x.size())))]){
                return false;
            }
        }
        return true and ((int)str.size())%(int(x.size())) == 0;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        char ch = str1[0];
        int index = str1.find(ch);
        cout<<index<<", ";
        while(index >= 0) {

            string x = str1.substr(0,index);
            if(x.size() > 0 and isDivideStr(str1, x) and isDivideStr(str2, x)) {
                ans = x;
            }
            int newIndex = str1.substr(index+1).find(ch);
            if(newIndex < 0) {
                break;
            }
            index = index + 1 + newIndex;
        }

        return ans;
    }
};