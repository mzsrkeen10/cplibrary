/*
    n元一次連立方程式(Gauss-Jordan法)
    時間計算量 O(n^3)

    Usage:
        vector<vector<double>> Aに係数を格納
        vector<double> Bに右辺を代入
        Bに解が格納される

    *** 要改善 ***
    ピボット選択を追加
*/

#include <vector>

std::vector<std::vector<double>> A;
std::vector<double> B;

void gauss_jordan() {
    for (int i = 0; i < A.size(); i++) {
        B[i] /= A[i][i];
        double aii = A[i][i];
        for (int j = i; j < A.size(); j++)
            A[i][j] /= aii;
        for (int j = 0; j < A.size(); j++) {
            if (j == i)
                continue;
            B[j] -= A[j][i] * B[i];
            double aji = A[j][i];
            for (int k = i; k < A.size(); k++)
                A[j][k] -= aji * A[i][k];
        }
    }
}
