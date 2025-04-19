#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Matrix {
public:
    Matrix(int r, int c) {
        row = r;
        column = c;
        mat = new int *[row];
        for (int i = 0; i < row; ++i) {
            mat[i] = new int[column];
            for (int j = 0; j < column; j++) {
                mat[i][j] = 0; // 初始化为0
            }
        }
    }

    // 析构函数
    ~Matrix() {
        for (int i = 0; i < row; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // 复制构造函数
    Matrix(const Matrix& other) {
        row = other.row;
        column = other.column;
        mat = new int *[row];
        for (int i = 0; i < row; ++i) {
            mat[i] = new int[column];
            for (int j = 0; j < column; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    void setValue(int value, int r, int c) {
        mat[r][c] = value;
    }

    int getRow() const {
        return row;
    }

    int getColumn() const {
        return column;
    }

    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << setw(10) << mat[i][j];
            }
            // 只在非最后一行时输出endl换行符
            if (i < row - 1) {
                cout << endl;
            }
        }
    }

    // 重载乘法运算符
    Matrix operator*(const Matrix& other) const {
        // 检查是否可以相乘
        bool canMultiply = false;

        // 标准矩阵乘法条件：第一个矩阵的列数等于第二个矩阵的行数
        if (column == other.row) {
            canMultiply = true;
        }
        // 特殊情况：当第一个矩阵是1*1（标量）时
        else if (row == 1 && column == 1) {
            canMultiply = true;
        }
        // 特殊情况：当第二个矩阵是1*1（标量）时
        else if (other.row == 1 && other.column == 1) {
            canMultiply = true;
        }

        if (!canMultiply) {
            cout << "Invalid Matrix multiplication!" << endl;
            Matrix result(1, 1);
            result.setValue(0, 0, 0);
            return result;
        }

        // 标准矩阵乘法
        if (column == other.row) {
            Matrix result(row, other.column);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < other.column; j++) {
                    int sum = 0;
                    for (int k = 0; k < column; k++) {
                        sum += mat[i][k] * other.mat[k][j];
                    }
                    result.setValue(sum, i, j);
                }
            }
            return result;
        }
        // 特殊情况：第一个矩阵是1*1（标量）
        else if (row == 1 && column == 1) {
            Matrix result(other.row, other.column);
            int scalar = mat[0][0];
            for (int i = 0; i < other.row; i++) {
                for (int j = 0; j < other.column; j++) {
                    result.setValue(scalar * other.mat[i][j], i, j);
                }
            }
            return result;
        }
        // 特殊情况：第二个矩阵是1*1（标量）
        else {
            Matrix result(row, column);
            int scalar = other.mat[0][0];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    result.setValue(mat[i][j] * scalar, i, j);
                }
            }
            return result;
        }
    }

private:
    int row;
    int column;
    int **mat;
};

int main() {
    int row, column, value;
    vector<Matrix> matrices;

    // 输入两个矩阵
    for (int i = 0; i < 2; i++) {
        cin >> row >> column;
        // 确保行和列都是正数
        if (row <= 0 || column <= 0) {
            cout << "Invalid matrix dimensions!" << endl;
            return 1;
        }

        Matrix matrix(row, column);
        matrices.push_back(matrix);

        // 输入矩阵元素
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < column; k++) {
                cin >> value;
                matrices[i].setValue(value, j, k);
            }
        }
    }

    // 检查矩阵是否可以相乘
    bool canMultiply = false;

    // 标准矩阵乘法条件
    if (matrices[0].getColumn() == matrices[1].getRow()) {
        canMultiply = true;
    }
    // 特殊情况：当第一个矩阵是1*1（标量）时
    else if (matrices[0].getRow() == 1 && matrices[0].getColumn() == 1) {
        canMultiply = true;
    }
    // 特殊情况：当第二个矩阵是1*1（标量）时
    else if (matrices[1].getRow() == 1 && matrices[1].getColumn() == 1) {
        canMultiply = true;
    }

    if (!canMultiply) {
        cout << "Invalid Matrix multiplication!" << endl;
    } else {
        Matrix result = matrices[0] * matrices[1];
        result.display();
    }

    return 0;
}
