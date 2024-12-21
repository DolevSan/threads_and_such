#pragma once

#include <vector>

extern "C" __declspec(dllexport) long long sumArrayD(const std::vector<int>& numbers, size_t numThreads);