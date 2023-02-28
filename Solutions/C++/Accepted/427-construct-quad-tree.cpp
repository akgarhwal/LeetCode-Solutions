/*
Problem Title: 427 - Construct Quad Tree
Lang: C++
Runtime: 21 ms
Memory: 16.1 MB
Problem Url: https://leetcode.com/problems/construct-quad-tree
Submission Url: https://leetcode.com/problems/construct-quad-tree/submissions/906019336
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    pair<bool,int> isAllSame(vector<vector<int>>& grid, int x, int y, int n) {
        int sum = 0, count = 0;
        for(int i=x; i < x+n; i++){
            for(int j=y; j < y+n; j++) {
                sum += grid[i][j];
                count += 1;
            }
        }
        return {sum == count or sum == 0, sum};
    }

    Node* solve(vector<vector<int>>& grid, int x, int y, int n) {
        if(n == 1){
            return new Node(grid[x][y], 1);
        }

        auto pi = isAllSame(grid, x, y, n);

        if(pi.first) {
            return new Node((pi.second == 0 ? 0 : 1), 1);
        }

        int temp = n/2;

        Node* root = new Node();
        
        pi = isAllSame(grid, x, y, temp);
        if(pi.first) {
            root->topLeft = new Node((pi.second == 0 ? 0 : 1), 1);
        } else {
            root->topLeft = solve(grid, x, y, temp);
        }

        pi = isAllSame(grid, x, y+temp, temp);
        if(pi.first) {
            root->topRight = new Node((pi.second == 0 ? 0 : 1), 1);
        } else {
            root->topRight = solve(grid, x, y+temp, temp);
        }

        pi = isAllSame(grid, x+temp, y, temp);
        if(pi.first) {
            root->bottomLeft = new Node((pi.second == 0 ? 0 : 1), 1);
        } else {
            root->bottomLeft = solve(grid, x+temp, y, temp);
        }

        pi = isAllSame(grid, x+temp, y+temp, temp);
        if(pi.first) {
            root->bottomRight = new Node((pi.second == 0 ? 0 : 1), 1);
        } else {
            root->bottomRight = solve(grid, x+temp, y+temp, temp);
        }

        return root;
    }


    Node* construct(vector<vector<int>>& grid) {
        
        return solve(grid, 0, 0, grid.size());
    }
};