/*
Problem Title: 2550 - Count Collisions of Monkeys on a Polygon
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon
Submission Url: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/submissions/887178270
*/

class Solution {
public:
    
    
    long long cal_pow(long long x){ 
        long long res; 
        if (x == 0)	{
            res=1; 
        }
        else if (x == 1) {
            res=2;
        }
        else { 
            res = cal_pow(x/2); 
            if (x % 2 == 0)	 
                res = (res * res) % (1000000007L); 
            else 
                res = (((res*res) % 1000000007L) * 2) % 1000000007L; 
        } 
        return res; 
    } 

    int monkeyMove(int n) {
        long long total = cal_pow(n);
        return (total-2+1000000007)%1000000007;   
    }
};