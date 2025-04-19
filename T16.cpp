#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
public:
    Matrix(int r, int c) {
        row = r;
        column = c;
        mat = new int *[row];
        for (int i = 0; i < row; ++i) {
            mat[i] = new int[column];
        }
    }

    void setValue(int value, int r ,int c) {
        mat[r][c] = value;j'f'h'k'l
    }
    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; i++) {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }

private:
    int row;
    int column;
    int **mat;
};
