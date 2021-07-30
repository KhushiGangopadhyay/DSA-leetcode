//problem link:https://leetcode.com/problems/number-of-enclaves/
class Solution {
public:
     
     void DFS(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j] != 1) return;
        grid[i][j] = -1;
        DFS(grid, i-1, j, m, n);
        DFS(grid, i+1, j, m, n);
        DFS(grid, i, j-1, m, n);
        DFS(grid, i, j+1, m, n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
      
        int m = grid.size();
        
      if(m == 0) return 0;  
        
     int n = grid[0].size();
     
     //Moving over firts and last column   
     for(int i=0; i<m; i++) {
         if(grid[i][0] == 1)
             DFS(grid, i, 0, m, n);
         if(grid[i][n-1] == 1)
             DFS(grid, i, n-1, m, n);
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<n; j++) {
         if(grid[0][j] == 1)
             DFS(grid, 0, j, m, n);
         if(grid[m-1][j] == 1)
             DFS(grid, m-1, j, m, n);
     }
        int count=0;
     for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(grid[i][j] == 1)
                 count++;
	}
    return count;
    }
};
