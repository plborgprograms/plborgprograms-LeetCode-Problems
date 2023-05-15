//https://leetcode.com/problems/word-search/submissions/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		//O(N*M*(3^L))
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size()));

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (foundWord(board, used, word, 0, col, row)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool foundWord(vector<vector<char>>& board, vector<vector<bool>>& used, const string& targetWord, int currentLength, int currentCol, int currentRow) {

        //handle all negative cases
        if (currentCol < 0 || currentCol >= board[0].size() || currentRow < 0 || currentRow >= board.size() || used[currentRow][currentCol] || board[currentRow][currentCol] != targetWord[currentLength]) {
            return false;
        }

        //mark the current cell as used before recurring
        used[currentRow][currentCol] = true;
        currentLength++;

        //base case
        if (currentLength == targetWord.length()) {
            return true;
        }

        //recur
        bool result = foundWord(board, used, targetWord, currentLength, currentCol - 1, currentRow) ||
                      foundWord(board, used, targetWord, currentLength, currentCol + 1, currentRow) ||
                      foundWord(board, used, targetWord, currentLength, currentCol, currentRow - 1) ||
                      foundWord(board, used, targetWord, currentLength, currentCol, currentRow + 1);

        used[currentRow][currentCol] = false;

        return result;
    }
};