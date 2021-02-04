///
/// Exemples sur les paires, tuples et liaisons structurées.
///

#include <cstddef>
#include <cstdint>

#include <utility>
#include <tuple>
#include <string>
#include <span>
#include <numeric>

#include <cppitertools/enumerate.hpp>

#include "tuples.hpp"

using namespace std;
using namespace iter;


MinMax findMinMax_v1(span<const int> values) {
	MinMax result = {values[0], values[0]};
	for (int v : values) {
		if (v < result.min)
			result.min = v;
		else if (v > result.max)
			result.max = v;
	}
	return result;
}

pair<int, int> findMinMax(span<const int> values) {
	int min = values[0];
	int max = values[0];
	for (int v : values) {
		if (v < min)
			min = v;
		else if (v > max)
			max = v;
	}
	return {min, max};
}

tuple<int, int, double> findMinMaxAvg(span<const int> values) {
	auto&& [min, max] = findMinMax(values);
	double avg = accumulate(values.begin(), values.end(), 0) / (double)values.size();
	return {min, max, avg};
}

