#include <iostream>

class Calculator {
private:
    double result;

public:
    Calculator() : result(0) {}

    Calculator& add(double value) {
        result += value;
        return *this; // 자기 자신 반환
    }

    Calculator& subtract(double value) {
        result -= value;
        return *this; // 자기 자신 반환
    }

    Calculator& multiply(double value) {
        result *= value;
        return *this; // 자기 자신 반환
    }

    Calculator& divide(double value) {
        if (value != 0) {
            result /= value;
        }
        return *this; // 자기 자신 반환
    }

    double getResult() const {
        return result;
    }
};

int main() {
    Calculator calc;
    double result = calc.add(5)
                        .multiply(2)
                        .subtract(3)
                        .divide(2)
                        .getResult();

    std::cout << result << std::endl; // 출력: 4
    return 0;
}