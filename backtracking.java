import java.util.*;

public class NQueens {
    private List<List<String>> solutions;
    
    private boolean isSafe(char[][] board, int row, int col, int n) {
        // Проверка столбца
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Проверка главной диагонали
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Проверка побочной диагонали
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    private void solve(char[][] board, int row, int n) {
        if (row == n) {
            solutions.add(constructSolution(board));
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
    
    private List<String> constructSolution(char[][] board) {
        List<String> solution = new ArrayList<>();
        for (char[] row : board) {
            solution.add(new String(row));
        }
        return solution;
    }
    
    public List<List<String>> solveNQueens(int n) {
        solutions = new ArrayList<>();
        char[][] board = new char[n][n];
        for (char[] row : board) {
            Arrays.fill(row, '.');
        }
        solve(board, 0, n);
        return solutions;
    }
    
    public static void main(String[] args) {
        NQueens solver = new NQueens();
        int n = 8;
        List<List<String>> result = solver.solveNQueens(n);
        
        System.out.println("Количество решений для " + n + " ферзей: " + result.size());
        System.out.println("Первое решение:");
        
        for (List<String> solution : result) {
            for (String row : solution) {
                for (char cell : row.toCharArray()) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            break; // Покажем только первое решение
        }
    }
}
