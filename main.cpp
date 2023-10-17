#include <iostream>
#include <fstream>
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::fstream inFile(argv[1]); // Open the input file
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file" << argv[1];
        return 1;   // Return with error
    }
    int N;
    inFile >> N;
    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        inFile >> numbers[i];
    }
    std::sort(numbers.begin(), numbers.end());

    int mid = N / 2;
    std::vector<int> small(numbers.begin(), numbers.begin() + mid);
    std::vector<int> large(numbers.begin() + mid, numbers.end());

    int sum_small = std::accumulate(small.begin(), small.end(), 0);
    int sum_large = std::accumulate(large.begin(), large.end(), 0);

    int result = sum_large - sum_small;

    std::ofstream outFile(argv[2]); // Open the output file
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file";
        return 1;   // Return with error
    }

    outFile << result;
    outFile.close();

    return 0;
}