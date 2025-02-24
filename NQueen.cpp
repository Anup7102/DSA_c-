#include <iostream>
#include <vector>
#include <limits> // For input validation

using namespace std;

// Function to check if placing a queen is safe
bool isSafe(vector<vector<int> >& board, int row, int col, int n) {
    // Check row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens using backtracking
bool solveNQueenUtil(vector<vector<int> >& board, int col, int n) {
    if (col >= n) return true; // Base case: All queens placed successfully

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place queen
            cout << "Placing queen at: (" << i << ", " << col << ")\n"; // Debug print

            if (solveNQueenUtil(board, col + 1, n))
                return true; // If placing leads to a solution, return true

            board[i][col] = 0; // Backtrack
            cout << "Backtracking from: (" << i << ", " << col << ")\n"; // Debug print
        }
    }

    return false; // No placement possible
}

// Function to solve N-Queens problem
void solveNQueen(int n) {
    vector<vector<int> > board(n, vector<int>(n, 0));

    if (!solveNQueenUtil(board, 0, n)) {
        cout << "No solution exists for " << n << " queens.\n";
        return;
    }

    // Print the solution
    cout << "\nSolution for " << n << "-Queens:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";

    // Input validation
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input! Please enter a positive integer: ";
        cin.clear();  // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    solveNQueen(n);
    return 0;
}
