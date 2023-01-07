/*
Problem Title: 420 - Strong Password Checker
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/strong-password-checker
Submission Url: https://leetcode.com/problems/strong-password-checker/submissions/502761668
*/

class Solution {
public:
    int strongPasswordChecker(string password) {
        bool lc = false, uc = false, digit = false;
        for(char ch : password){
            if(ch >= 'a' and ch <= 'z'){
                lc = true;
            }
            else if (ch >= 'A' and ch <= 'Z'){
                uc = true;
            }
            else if(ch >= '0' and ch <= '9'){
                digit = true;
            }
        }
        int req = 0;
        if(!lc) req+=1;
        if(!uc) req+=1;
        if(!digit) req+=1;
        
        //cout<<req<<" - ";
        
        int miReq = max(0, 6 - (int)password.size());
        int mxReq = max(0, (int)password.size() - 20);
        
        //cout<<miReq<<" - "<<mxReq<<endl;
        
        return max(req, max(miReq, mxReq));
        
    }
};