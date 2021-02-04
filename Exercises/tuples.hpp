///
/// Exemples sur les paires, tuples et liaisons structurées.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <utility>
#include <tuple>
#include <string>
#include <span>
#include <numeric>

using namespace std;


struct MinMax {
	int min;
	int max;
};


MinMax findMinMax_v1(span<const int> values);

pair<int, int> findMinMax(span<const int> values);

tuple<int, int, double> findMinMaxAvg(span<const int> values);

