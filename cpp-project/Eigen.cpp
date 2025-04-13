#include <iostream>
#include <Eigen/Dense>

int main() {
    using namespace Eigen;
    using namespace std;

    MatrixXd A(3, 2);
    A << 1, 2,
         3, 4,
         5, 6;

    MatrixXd B(2, 3);
    B << 7, 8, 9,
         10, 11, 12;

    MatrixXd C = A * B;

    cout << "행렬 곱 결과:" << endl;
    cout << C << endl;

    return 0;
}
