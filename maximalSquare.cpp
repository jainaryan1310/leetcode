class Solution {
public:

    int largerSquares(vector<vector<char>>& matrix, int size) {
        vector<vector<char>> new_matrix;
        int num_bigger_squares = 0;
        for (int i = 0; i < matrix.size() - 1; i++) {
            vector<char> v;
            new_matrix.push_back(v);
            for (int j = 0; j < matrix.at(i).size() - 1; j++) {
                if (matrix.at(i).at(j) == '1' && matrix.at(i + 1).at(j) == '1' && matrix.at(i).at(j + 1) == '1' && matrix.at(i + 1).at(j + 1) == '1') {
                    new_matrix.at(i).push_back('1');
                    num_bigger_squares += 1;
                } else {
                    new_matrix.at(i).push_back('0');
                }
            }
        }
        if (num_bigger_squares == 0) {
            return size * size;
        } else {
            return largerSquares(new_matrix, size + 1);
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int non_zero = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(i).size(); j++) {
                if (matrix.at(i).at(j) == '1') {
                    non_zero = 1;
                    break;
                }
            }
            if (non_zero == 1) {
                break;
            }
        }

        if (non_zero == 1) {
            return largerSquares(matrix, 1);
        } else {
            return 0;
        }

    }
};