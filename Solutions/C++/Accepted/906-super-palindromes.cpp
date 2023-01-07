/*
Problem Title: 906 - Super Palindromes
Lang: C++
Runtime: 232 ms
Memory: 6.1 MB
Problem Url: https://leetcode.com/problems/super-palindromes
Submission Url: https://leetcode.com/problems/super-palindromes/submissions/490713075
*/

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long ll = CI(left), rl=CI(right);
        unsigned long long nn = 0;
        int ans = 0;
        for(int i = 1; i < 100000; i++) {
            string x = to_string(i);
            int xs = x.size();
            for(int j = xs-2; j>= 0 ;j--){
                x += x[j];
            }
            long long n1 = CI(x);
            nn = n1*n1;
            if(nn > rl){
                break;
            }
            if( nn >= ll and nn <= rl and reverse(nn) == nn ) {
                ans+=1;
            }
        }
        
        for(int i=1;i<100000;i++){
            
            string y = to_string(i);
            int ys = y.size();
            for(int j = ys-1; j>= 0 ;j--){
                y += y[j];
            }
            long n2 = CI(y);
            nn = n2*n2;
            if(nn > rl){
                break;
            }
            if( nn >= ll and nn <= rl and reverse(nn) == nn ) {
                ans+=1;
            }
        }
        
        return ans;
    }
    
    long CI(string x){
        long n = 0;
        for(char ch : x){
            n = n*10 + (ch - '0');
        }
        return n;
    }
    
     long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }
        return ans;
    }
};