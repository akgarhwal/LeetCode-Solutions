/*
Problem Title: 1700 - Number of Students Unable to Eat Lunch
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch
Submission Url: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/submissions/434763357
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c1 = 0;
        for(int x : students){
            c1 += x;
        }
        queue<int> q;
        for(int s : students){
            q.push(s);
        }
        int sp = 0;
        while(!q.empty()){
            
            if(q.front() != sandwiches[sp]){
                if( (c1 == q.size() and sandwiches[sp]==0 ) or ((students.size() - c1) == q.size() and sandwiches[sp]==1)  ){
                    break;
                }
                q.push(q.front());
            }
            else{
                if(q.front() == 1){
                    c1--;
                }
                sp+=1;
            }
            q.pop();
            
        }
        return q.size();
    }
};