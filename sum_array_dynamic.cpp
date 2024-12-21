#include "sum_array_dynamic.h"
#include <thread>
#include <numeric>
#include <algorithm>

long long sumArrayD(const std::vector<int>& numbers, size_t numThreads) {
    size_t dataSize = numbers.size();
    size_t chunkSize = (dataSize + numThreads - 1) / numThreads;
    std::vector<long long> partialResults(numThreads, 0);
    std::vector<std::thread> threads;

    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * chunkSize;
        size_t end = std::min(start + chunkSize, dataSize);

        if (start < end) {
            threads.emplace_back([&, start, end, i]() {
                partialResults[i] = std::accumulate(numbers.begin() + start, numbers.begin() + end, 0LL);
                });
        }
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return std::accumulate(partialResults.begin(), partialResults.end(), 0LL);
}