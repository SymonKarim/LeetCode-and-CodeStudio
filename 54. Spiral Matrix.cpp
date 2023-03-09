class Solution {
public:
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0;
        int startCol =0;
        int endRow = matrix.size()-1;
        int endCol = matrix[0].size()-1;

        int total =  matrix.size()*matrix[0].size(),cnt = 0;
        vector<int>ans;
        while(cnt<total){
           for(int i= startCol; cnt<total and i<=endCol;i++){
               ans.push_back(matrix[startRow][i]);
               cnt++;
           }
           startRow++;
             for(int i= startRow; cnt<total and i<=endRow;i++){
               ans.push_back(matrix[i][endCol]);
               cnt++;
           }
           endCol--;
          for(int i= endCol; cnt<total and i>=startCol;i--){
               ans.push_back(matrix[endRow][i]); cnt++;
          }
          endRow--;
          for(int i= endRow; cnt<total and i>=startRow;i--){
               ans.push_back(matrix[i][startCol]); cnt++;
          }
          startCol++;
        }
        return ans;
    }
};
