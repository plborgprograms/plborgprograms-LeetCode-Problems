//https://leetcode.com/problems/n-queens/submissions/
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > result;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        
        std::vector<int> exclusions(5 * n - 2, 1);
        solveNQueens(result, nQueens, exclusions, 0, n);
        return result;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &excludedList, int row, int &n) {
        //if there are n rows, add this to the results
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        
		//iterate over the list handling diagonals and previous cases 
        for (int col = 0; col != n; ++col)
            if (excludedList[col] && excludedList[n + row + col] && excludedList[4 * n - 2 + col - row]) {
                excludedList[col] = excludedList[n + row + col] = excludedList[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, excludedList, row + 1, n);
                nQueens[row][col] = '.';
                excludedList[col] = excludedList[n + row + col] = excludedList[4 * n - 2 + col - row] = 1;
            }
    }
};