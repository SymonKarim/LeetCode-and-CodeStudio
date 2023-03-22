class Solution {
public:
    int row = 0, col = 0, mx = 0;
    vector<vector<int>>offset{{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<bool>>& visit) {
        if (i<0 or i >= row or j<0 or j >= col or grid[i][j] == 0 or visit[i][j] ) return 0;
       
            visit[i][j]= true; 
      int ans = grid[i][j] + max( 
            {
             solve(i,j+1,grid, visit),
             solve(i+1,j,grid, visit),
             solve(i,j-1,grid, visit),
             solve(i-1,j,grid, visit)
             }
         );
         visit[i][j] = false;
         return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        row = grid.size(), col = grid[0].size();
        for (int i = 0; i<row;i++) {
            for (int j = 0;j<col;j++) {
                if (grid[i][j]) { 
                    vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
                   mx= max(mx,solve(i, j, grid, visit));
                }
            }
        }
     return mx;
    }
};
