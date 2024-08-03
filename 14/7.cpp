#include <iostream>
#include <cctype>
#include <string>

bool isPalindrome(const std::string& str, const std::string& ignoreChars) {
    std::string filtered;
    for (char c : str) {
        if (isalnum(c) && ignoreChars.find(tolower(c)) == std::string::npos) {
            filtered += tolower(c);
        }
    }
    
    int left = 0, right = filtered.size() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) return false;
        ++left;
        --right;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is palindrome (ignore ' '): " << isPalindrome("A man a plan a canal Panama", " ") << std::endl;
    std::cout << "Is palindrome (ignore ' ' and 'a'): " << isPalindrome("A man a plan a canal Panama", "a ") << std::endl;
    
    return 0;
}
