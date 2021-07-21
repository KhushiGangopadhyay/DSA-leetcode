//problem link:https://leetcode.com/problems/number-of-islands/


class Solution {
public:
    void helper(vector<vector<char>> &grid, int i, int j) {
        if(i>=size(grid) or j>=size(grid[0])) return;
        if(i<0 or j<0) return;
        if(grid[i][j]  == '0' or grid[i][j] == '2') return;
        if(grid[i][j] == '1') grid[i][j] = '2';
        helper(grid, i+1,j);
        helper(grid, i-1,j);
        helper(grid, i,j+1);
        helper(grid, i,j-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = size(grid),col=size(grid[0]);
        int count =0;
        for(int i=0 ; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') count++ , helper(grid,i,j);
            }
        }
        return count;
    }
};
