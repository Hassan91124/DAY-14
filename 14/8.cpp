#include <iostream>

template <typename T, typename U>
U convert(const T& value) {
    return static_cast<U>(value);
}

int main() {
    int i = 42;
    double d = convert<int, double>(i);
    char c = convert<int, char>(i);

    std::cout << "Int to double: " << d << std::endl;
    std::cout << "Int to char: " << static_cast<int>(c) << std::endl;
    
    return 0;
}
