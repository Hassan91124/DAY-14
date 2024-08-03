#include <iostream>
#include <algorithm>

void sortPairs(std::pair<int, int> arr[], int size) {
    std::sort(arr, arr + size, [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
}

int main() {
    std::pair<int, int> arr[] = { {3, 4}, {2, 3}, {1, 2}, {3, 2}, {2, 1} };
    int size = sizeof(arr) / sizeof(arr[0]);

    sortPairs(arr, size);

    std::cout << "Sorted pairs:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "(" << arr[i].first << ", " << arr[i].second << ")\n";
    }
    
    return 0;
}
