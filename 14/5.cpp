#include <iostream>

class Polynomial {
private:
    int coefficients[3]; // Assumes polynomial of degree 2

public:
    Polynomial(int c0, int c1, int c2) {
        coefficients[0] = c0;
        coefficients[1] = c1;
        coefficients[2] = c2;
    }

    Polynomial operator+(const Polynomial& other) {
        return Polynomial(coefficients[0] + other.coefficients[0],
                          coefficients[1] + other.coefficients[1],
                          coefficients[2] + other.coefficients[2]);
    }

    Polynomial operator-(const Polynomial& other) {
        return Polynomial(coefficients[0] - other.coefficients[0],
                          coefficients[1] - other.coefficients[1],
                          coefficients[2] - other.coefficients[2]);
    }

    Polynomial operator*(const Polynomial& other) {
        return Polynomial(coefficients[0] * other.coefficients[0],
                          coefficients[1] * other.coefficients[1],
                          coefficients[2] * other.coefficients[2]);
    }

    int evaluate(int x) {
        return coefficients[0] + coefficients[1] * x + coefficients[2] * x * x;
    }

    void display() const {
        std::cout << coefficients[2] << "x^2 + " << coefficients[1] << "x + " << coefficients[0] << std::endl;
    }
};

int main() {
    Polynomial p1(1, 2, 3); // 3x^2 + 2x + 1
    Polynomial p2(4, 5, 6); // 6x^2 + 5x + 4

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "Sum: "; sum.display();
    std::cout << "Difference: "; diff.display();
    std::cout << "Product: "; prod.display();
    std::cout << "Evaluation of p1 at x = 2: " << p1.evaluate(2) << std::endl;
    
    return 0;
}
