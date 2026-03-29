from typing import List

class Solution:
    def exist_aux(self, board: List[List[str]], word: str, index: int, row: int, col: int) -> bool:
        if index == len(word):
            return True  # Word found

        # Check if row, col are out of bounds
        if row < 0 or col < 0 or row >= len(board) or col >= len(board[0]):
            return False
        
        # Check if current character matches
        if board[row][col] != word[index]:
            return False

        # Temporarily mark cell as visited
        temp = board[row][col]
        board[row][col] = '#'  # Mark as visited

        # Explore all four possible directions
        result = (
            self.exist_aux(board, word, index + 1, row + 1, col) or
            self.exist_aux(board, word, index + 1, row - 1, col) or
            self.exist_aux(board, word, index + 1, row, col + 1) or
            self.exist_aux(board, word, index + 1, row, col - 1)
        )

        # Restore original character (backtrack)
        board[row][col] = temp

        return result

    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])

        # Start search from any cell in the board
        for r in range(rows):
            for c in range(cols):
                if self.exist_aux(board, word, 0, r, c):
                    return True

        return False