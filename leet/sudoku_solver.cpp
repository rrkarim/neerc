/*
    Sudoku Solver
*/
class Solution {
public:
    unordered_map<int, int> mp_c, mp_r, mp_b;
    int ind[10][10];
    int box(int i, int j) {
        int a = i / 3, b = j / 3;
        return 3*a+b;
    }
    bool solve(vector <vector <char>>& board) {
       int r = -1, c = -1, cx = 0;
       for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board.size(); ++j) {
                if(board[i][j] == '.') {
                    r = i, c = j, cx = 1;
                    break;
                }
            }
            if(cx) break;
       }
       if(r == -1 && c == -1) return 1;

       int t = mp_c[r] | mp_r[c] | mp_b[ind[r][c]];
       for(int num = 1; num <= 9; ++num) {
            if((t & (1 << (num - 1))) == 0) {
                board[r][c] = num + '0';
                mp_c[r] |= 1 << (num-1), mp_r[c] |= 1 << (num-1), mp_b[ ind[r][c] ] |= 1 << (num-1);
                if(solve(board)) return true;
                board[r][c] = '.';
                int x = 0;
                for(int z = 0; z < 9; ++z) {
                    if(z == (num - 1)) continue;
                    x |= (1 << z);
                }
                mp_c[r] &= x, mp_r[c] &= x, mp_b[ ind[r][c] ] &= x;
            }
       }
       return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) ind[i][j] = box(i, j);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] != '.') {
                    int x = (board[i][j]-'0')-1;
                    mp_c[i] |= 1 << x;
                    mp_r[j] |= 1 << x;
                    mp_b[ ind[i][j] ] |= (1 << x);
                }
            }
        }
        solve(board);
    }
};