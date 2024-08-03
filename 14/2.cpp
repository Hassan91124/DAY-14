#include <iostream>

class CustomType {
public:
    int value;

    CustomType(int v) : value(v) {}

    // Custom type conversion to double
    operator double() const {
        return static_cast<double>(value);
    }
};

int main() {
    CustomType obj(42);
    double converted = obj; // Implicit conversion
    std::cout << "Converted value: " << converted << std::endl;
    
    return 0;
}
