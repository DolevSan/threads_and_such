#pragma once

#ifndef SUM_ARRAY_H
#define SUM_ARRAY_H

#include <vector>

#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" DLL_EXPORT long long sumArray(const std::vector<int>& numbers, size_t numThreads);

#endif // SUM_ARRAY_H