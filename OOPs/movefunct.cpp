#include <vector>
#include <iostream>
#include <utility>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};

    // Move the contents of 'source' into 'destination'
    std::vector<int> destination (source);

    // 'source' is now in a valid but unspecified state (usually empty)
    std::cout << "Source size after move: " << source.size() << std::endl; // Output: 0

    // 'destination' contains the elements previously owned by 'source'
    std::cout << "Destination size after move: " << destination.size() << std::endl; // Output: 5

    return 0;
}