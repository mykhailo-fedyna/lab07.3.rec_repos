#include <iostream>
#include <iomanip>
using namespace std;
void FindMaxElement(int** matrix, int n, int& maxElem, int& maxRow, int& maxCol, int row, int col) {
    if (col == n) return;
    if (matrix[row][col] > maxElem) {
        maxElem = matrix[row][col];
        maxRow = row;
        maxCol = col;
    }
    if (col < n - 1) {
        FindMaxElement(matrix, n, maxElem, maxRow, maxCol, row, col + 1);
    }
}
void FindMaxInRows(int** matrix, int n, int& maxElem, int& maxRow, int& maxCol, int row) {
    if (row == n) return;
    FindMaxElement(matrix, n, maxElem, maxRow, maxCol, row, 0);
    if (row < n - 1) {
        FindMaxInRows(matrix, n, maxElem, maxRow, maxCol, row + 1);
    }
}
void RearrangeMatrix(int** matrix, int n, int diagPos) {
    if (diagPos == n) return;
    int maxElem = matrix[diagPos][diagPos];
    int maxRow = diagPos, maxCol = diagPos;
    FindMaxInRows(matrix, n, maxElem, maxRow, maxCol, diagPos);
    swap(matrix[diagPos][diagPos], matrix[maxRow][maxCol]);
    RearrangeMatrix(matrix, n, diagPos + 1);
}
void PrintRow(int** matrix, int rowNo, const int colCount, int colNo) {
    cout << setw(4) << matrix[rowNo][colNo];
    if (colNo < colCount - 1) {
        PrintRow(matrix, rowNo, colCount, colNo + 1);
    }
    else {
        cout << endl;
    }
}
void PrintMatrix(int** matrix, const int rowCount, int rowNo) {
    if (rowNo < rowCount) {
        PrintRow(matrix, rowNo, rowCount, 0);
        PrintMatrix(matrix, rowCount, rowNo + 1);
    }
}
bool HasPositive(int** matrix, int rowNo, int colCount, int colNo) {
    if (colNo == colCount) return false;
    if (matrix[rowNo][colNo] > 0) return true;
    return HasPositive(matrix, rowNo, colCount, colNo + 1);
}
int FindFirstNonPositiveRow(int** matrix, int rowCount, int colCount, int rowNo) {
    if (rowNo == rowCount) return -1;
    if (!HasPositive(matrix, rowNo, colCount, 0)) return rowNo;
    return FindFirstNonPositiveRow(matrix, rowCount, colCount, rowNo + 1);
}
int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << "Initial matrix:\n";
    PrintMatrix(matrix, n, 0);
    RearrangeMatrix(matrix, n, 0);
    cout << "Modified matrix:\n";
    PrintMatrix(matrix, n, 0);
    int firstRow = FindFirstNonPositiveRow(matrix, n, n, 0);
    if (firstRow == -1) {
        cout << "No row without positive elements found.\n";
    }
    else {
        cout << "First row without positive elements: " << firstRow << endl;
    }
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}