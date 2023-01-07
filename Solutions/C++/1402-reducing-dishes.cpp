/*
Problem Title: 1402 - Reducing Dishes
Lang: C++
Runtime: 4 ms
Memory: 6.6 MB
Problem Url: https://leetcode.com/problems/reducing-dishes
Submission Url: https://leetcode.com/problems/reducing-dishes/submissions/323008091
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = INT_MIN, ind = 0;
        
        while( ind < satisfaction.size()){
            
            int temp = 0, count = 1;
            for(int i = ind; i < satisfaction.size(); i++){
                temp += satisfaction[i] * count; 
                count += 1;
            }
            if(temp > ans){
                ans = temp;
            }
            else{
                break;
            }
            ind += 1;
        }
        
        return max(ans, 0);
    }
};