/*
Problem Title: 93 - Restore IP Addresses
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/restore-ip-addresses
Submission Url: https://leetcode.com/problems/restore-ip-addresses/submissions/882113702
*/

class Solution {
public:

    bool isValidIP(string ip){
        int num = 0;
        bool leadingZero = false;
        int i = 0;
        for(char ch : ip){
            if(ch == '.') {
                if(num > 255) {
                    return false;
                }
                num = 0;
                leadingZero = false;
            } else if(num == 0 and ch == '0' and !leadingZero){ 
                leadingZero = true;
            }
            else if(num == 0 and leadingZero){
                return false;
            }
            else {
                num  = num * 10 +  (ch - '0');
            }
            i++;
        }
        if(num > 255) {
            return false;
        }
        return true;
    }
    void solve(int index, string s, string ip, int dc, vector<string>& ans) {
        if(index >= ip.size()){
            return;
        }
        if(dc == 3) {
            if(isValidIP(ip)) {
                ans.push_back(ip);
            }
            return;
        }
        for(int i = index + 1; i < min((int)ip.size(), index+4); i++) {
            solve(i+1, s, ip.substr(0,i) + "." + ip.substr(i), dc + 1, ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(0, s, s, 0, ans);
        return ans;
    }
};