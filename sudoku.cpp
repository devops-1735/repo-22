class Solution {
public:
vector<vector<char>> solve(vector<vector<char>>& board , vector<char>& v , vector<vector<char>>& v2){
     for(int i = 0 ; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
              if(board[i][j] == '.'){
                  for(char c = '1' ; c <= '9'; c++){
                      if(isvalid(board , i , j ,c)){
                          board[i][j] = c;
                      }
                      if(solve(board)==true){
                          v2.push_back(v);
                          return ;
                      }
                      else{
                          board[i][j] = '.';
                      }
                  }
                  return false;
              }
        }
     }
     return true;
}

bool isvalid(vector<vector<char>>& board , int row , int col , char c){
    for(int i = 0 ; i < 9 ; i++){
        if(board[row][i] == c)return false;
        if(board[i][col] == c)return false;
        if(board[3 * (row/3) + i/3][3 * (col/3) + i % 3])return false;
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};