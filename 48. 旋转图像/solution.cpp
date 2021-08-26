#include <vector>

using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;    
            }
        }
    }

    void mirror(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = n - 1; j < k; ++j, --k) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];   
                matrix[i][k] = temp;             
            }
        }       
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirror(matrix);
    }
};