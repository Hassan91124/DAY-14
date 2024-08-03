#include <iostream>
#include <string>

bool stringToBool(const std::string& str, bool defaultValue) {
    if (str == "true") return true;
    if (str == "false") return false;
    return defaultValue;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "Converted 'true': " << stringToBool("true", false) << std::endl;
    std::cout << "Converted 'false': " << stringToBool("false", true) << std::endl;
    std::cout << "Converted 'invalid': " << stringToBool("invalid", true) << std::endl;
    
    return 0;
}
