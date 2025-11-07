#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueens {
private:
    vector<vector<string>> solutions;
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Проверка столбца
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Проверка главной диагонали (слева вверх)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Проверка побочной диагонали (справа вверх)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void solve(vector<string>& board, int row, int n) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        solutions.clear();
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return solutions;
    }
};

int main() {
    NQueens solver;
    int n = 8;
    auto result = solver.solveNQueens(n);
    
    cout << "Количество решений для " << n << " ферзей: " << result.size() << endl;
    cout << "Первое решение:" << endl;
    
    for (const auto& solution : result) {
        for (const string& row : solution) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        break; // Покажем только первое решение
    }
    
    return 0;
}
