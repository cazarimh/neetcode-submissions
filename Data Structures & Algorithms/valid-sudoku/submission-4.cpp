class Solution {
public:
    bool isValidSequence(vector<char> sequence) {
        set<char> sequenceSet;
        for (int i = 0; i < 9; i++) {
            if (sequence[i] == '.') continue;
            
            if (sequenceSet.contains(sequence[i])) return false;
            sequenceSet.insert(sequence[i]);
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidSequence(board[i])) return false;

            if (!isValidSequence({
                board[0][i], board[1][i], board[2][i], 
                board[3][i], board[4][i], board[5][i], 
                board[6][i], board[7][i], board[8][i]
            })) return false;

            int m = (i / 3) * 3;
            int n = (i % 3) * 3;
            if (!isValidSequence({
            board[m+0][n+0], board[m+0][n+1], board[m+0][n+2],
            board[m+1][n+0], board[m+1][n+1], board[m+1][n+2],
            board[m+2][n+0], board[m+2][n+1], board[m+2][n+2]
            })) return false;
        }
        return true;
    }
};
