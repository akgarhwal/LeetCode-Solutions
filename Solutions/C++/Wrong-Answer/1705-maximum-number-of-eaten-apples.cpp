/*
Problem Title: 1705 - Maximum Number of Eaten Apples
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-number-of-eaten-apples
Submission Url: https://leetcode.com/problems/maximum-number-of-eaten-apples/submissions/435008294
*/

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int day_count = 0, ans = 0, t =0;
        for(int i = 0; i< apples.size();i++){
                int safe = i+days[i];
                int mi = min(apples[i], days[i]);
                if(day_count <= i){
                    day_count = i+1;
                }
                cout<<"dc = "<<day_count<<endl;
                t = 0;
                if(day_count <= safe){
                    if(day_count >= i+1){
                        ans += (mi - (day_count-i-1));
                        day_count += (mi - (day_count-i-1));
                    }
                    else{
                        ans += mi;
                        day_count += mi;
                    }
                }
                
                
                
                    
                cout<<mi<<" -- "<<ans<<endl;
            
        }
        return ans;
    }
};