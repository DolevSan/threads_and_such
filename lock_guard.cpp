#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <numeric> // for std::accumulate

// Global variables for shared sum and mutex
long long sharedSum = 0;
std::mutex mtx;

// Function to compute partial sum and update shared sum
void computeAndUpdateSum(const std::vector<int>& data, size_t start, size_t end) {
    long long partialSum = std::accumulate(data.begin() + start, data.begin() + end, 0LL);

    // Lock the mutex before updating the shared sum
    std::lock_guard<std::mutex> lock(mtx);
    sharedSum += partialSum;
}

int main() {
    // Example array
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Number of threads
    size_t numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 2; // Fallback if hardware_concurrency returns 0

    size_t dataSize = numbers.size();
    size_t chunkSize = (dataSize + numThreads - 1) / numThreads;

    // Threads container
    std::vector<std::thread> threads;

    // Launch threads
    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * chunkSize;
        size_t end = std::min(start + chunkSize, dataSize);

        if (start < end) {
            threads.emplace_back(computeAndUpdateSum, std::cref(numbers), start, end);
        }
    }

    // Join threads
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    // Output the result
    std::cout << "Total sum: " << sharedSum << std::endl;

    return 0;
}
