#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[]) {
    // Open the input file
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Unable to open input file" << std::endl;
        return 1;
    }

    // Read the first line and get the count of numbers
    int count;
    input_file >> count;

    // Read the next line and get the numbers
    std::vector<int> numbers(count);
    for (int i = 0; i < count; ++i) {
        input_file >> numbers[i];
    }

    // Sort the numbers in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Calculate the maximum win
    int max_win = numbers[count - 1] + numbers[count - 2];

    // Write the maximum win to the output file
    std::ofstream output_file(argv[2]);
    if (!output_file.is_open()) {
        std::cerr << "Unable to open output file" << std::endl;
        return 1;
    }
    output_file << max_win << std::endl;

    return 0;
}
