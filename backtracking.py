class NQueens:
    def solveNQueens(self, n: int):
        def is_safe(board, row, col):
            # Проверка столбца
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
            
            # Проверка главной диагонали
            i, j = row - 1, col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1
            
            # Проверка побочной диагонали
            i, j = row - 1, col + 1
            while i >= 0 and j < n:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1
            
            return True
        
        def backtrack(row):
            if row == n:
                solutions.append(["".join(row) for row in board])
                return
            
            for col in range(n):
                if is_safe(board, row, col):
                    board[row][col] = 'Q'
                    backtrack(row + 1)
                    board[row][col] = '.'  # backtrack
        
        solutions = []
        board = [['.'] * n for _ in range(n)]
        backtrack(0)
        return solutions

if __name__ == "__main__":
    solver = NQueens()
    n = 8
    result = solver.solveNQueens(n)
    
    print(f"Количество решений для {n} ферзей: {len(result)}")
    print("Первое решение:")
    
    for solution in result:
        for row in solution:
            print(' '.join(row))
        break  # Покажем только первое решение
