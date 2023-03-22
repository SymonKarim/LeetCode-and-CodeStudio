class Solution {
public:
   int N;

   bool safe(char **grid, int row, int col){
       for(int i=0;i<row;i++){
        if(grid[i][col] == 'Q') return false;
       }
       for(int i=row,j=col; i>=0 and j>=0;i--,j--){
           if(grid[i][j] == 'Q') return false;
       }
        for(int i=row,j=col; i>=0 and j<N;i--,j++){
           if(grid[i][j] == 'Q') return false;
       }
       return true;
   }
   void solve(char **grid, int row,vector<vector<string>> &ans){
       if(row==N){
          
           vector<string>a;
         for(int i=0;i<N;i++){ 
             string s;
             for(int j=0;j<N;j++){
                 s.push_back(grid[i][j]);
             }
             a.push_back(s);
         }
          ans.push_back(a);
           return;
       }
       for(int i=0;i<N;i++){
           if(safe(grid, row,i)){
               grid[row][i] = 'Q';
               solve(grid, row+1,ans);
                 grid[row][i] = '.';
           }
       }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        char **grid;
        grid = new char*[n];
        for(int i=0;i<n;i++){
            grid[i] = new char[n];
            for(int j=0;j<n;j++){
              grid[i][j] = '.';
            }
        }
        N = n;
        solve(grid, 0,ans);
        return ans;
    }
};
