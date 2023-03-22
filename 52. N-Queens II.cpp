class Solution {
public:
    int cnt = 0,N;
    bool safe(char **grid, int r, int c){
        for(int i=0;i<r;i++){
            if(grid[i][c] =='Q') return false;
        }
        for(int i=r,j=c;i>=0 and j>=0;i--,j--){
             if(grid[i][j] =='Q') return false;
        }
          for(int i=r,j=c;i>=0 and j<N;i--,j++){
             if(grid[i][j] =='Q') return false;
        }
        return true;
    }
    void solve(char **grid, int row){
        if(row == N){
            cnt = cnt+1;
            return;
        }
        for(int i=0;i<N;i++){
            if(safe(grid, row, i)){
                grid[row][i] = 'Q';
                solve(grid, row+1);
                 grid[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        char **grid = new char*[n];
        for(int i=0;i<n;i++){
            grid[i] = new char[n];
            for(int j=0;j<n;j++){
                grid[i][j] = '.';
            }
        }
        N = n;
        solve(grid, 0);
        return cnt;
    }
};
