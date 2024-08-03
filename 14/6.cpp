#include <iostream>
#include <string>

std::string compressString(const std::string& str) {
    std::string compressed;
    int count = 1;
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] == str[i - 1]) {
            ++count;
        } else {
            compressed += str[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    compressed += str.back() + std::to_string(count);

    return compressed.size() < str.size() ? compressed : str;
}

int main() {
    std::string input = "aabcccccaaa";
    std::cout << "Compressed string: " << compressString(input) << std::endl;
    
    return 0;
}
