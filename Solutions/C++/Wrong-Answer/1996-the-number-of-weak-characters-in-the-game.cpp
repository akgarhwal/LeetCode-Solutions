/*
Problem Title: 1996 - The Number of Weak Characters in the Game
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game
Submission Url: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/submissions/549664922
*/

class Solution {
public:
    static bool customSort(vector<int> a, vector<int> b){
        if( (a[0] < b[0] and a[1] < b[1]) or (a[0] <= b[0] and a[1] < b[1]) or (a[0] < b[0] and a[1] <= b[1])){
            return true;
        }
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        
        sort(properties.begin(), properties.end(), customSort);
        
       
        for(auto v : properties){
            cout<<v[0]<<","<<v[1]<<endl;
        }
        int ans = 0;
        
        int end = properties.size()-1;
        for(int i=0; i < properties.size();i++){
            
            
            if(properties[i][0] < properties[end][0] and  properties[i][1] < properties[end][1])
                ans++;
            
            
        }
        
        cout<<endl;
        
        
        return ans;
    }
};