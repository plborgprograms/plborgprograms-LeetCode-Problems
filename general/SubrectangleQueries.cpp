//https://leetcode.com/problems/subrectangle-queries/
class SubrectangleQueries {
public:
    vector<vector<int>> matrix;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        cout << "declare rectangle" << endl;
        matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        cout << "updating subRectangle" << endl;
        for(int y = row1; y <= row2; y++)
        {
            for(int x = col1; x <= col2; x++)
            {
                //matrix[x][y] = newValue;
                matrix[y][x] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        cout << "getting " << col << ", " << row << endl;
        return matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */