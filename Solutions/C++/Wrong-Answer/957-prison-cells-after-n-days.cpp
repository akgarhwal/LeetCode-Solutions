/*
Problem Title: 957 - Prison Cells After N Days
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/prison-cells-after-n-days
Submission Url: https://leetcode.com/problems/prison-cells-after-n-days/submissions/305693681
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<vector<int>, int> memory;
        int count = 1;
        
        while(N > 0) {
            
            if(memory.count(cells) > 0){
                int interval = count - memory[cells];
                cout<<" -- "<<interval<<" "<<N<<endl;
                N = N % (interval);
            }
            
            memory.insert({cells, count});
            
            vector<int> new_cells(8,0);
            
            for(int index = 1; index < 7; index++) {
                if( (cells[index-1] == 0 && cells[index+1] == 0) || (cells[index-1] == 1 && cells[index+1] == 1) ) {
                    new_cells[index] = 1;
                }
            }
            
            cells = new_cells;
            count++;
            N -= 1;
        }
        
        return cells;
    }
};