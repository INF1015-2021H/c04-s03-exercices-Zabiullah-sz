///
/// Exemples des slides sur les paramètres.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <cstdio>

#include <cppitertools/range.hpp>

#include "params.hpp"

using namespace std;
using iter::range;


void swap_v1(int a, int b) {
	int buffer = a;
	a = b;
	b = buffer;
}

void swap_v2(int& a, int& b) {
	int buffer = a;
	a = b;
	b = buffer;
}

void modify1D(double values[], int numValues) {
	for (int i : range(numValues))
		values[i] *= 10;
}

void modify2D(double values[][5], int numValues) {
	for (int i : range(numValues))
		for (int j : range(5))
			values[i][j] *= 10;
}

void runParamsExample() {
	{
		int foo = 42;
		int bar = 69;
		printf("foo=%i, bar=%i" "\n", foo, bar);
		swap_v1(foo, bar);
		printf("foo=%i, bar=%i" "\n", foo, bar);
		swap_v2(foo, bar);
		printf("foo=%i, bar=%i" "\n", foo, bar);
	}
	cout << "\n";
	{
		const int size = 5;
		double vals[size] = {0.1, 0.2, 0.3, 0.4, 0.5};
		for (int i : range(size))
			printf("%4.1f ", vals[i]);
		cout << "\n";
		modify1D(vals, size);
		for (int i : range(size))
			printf("%4.1f ", vals[i]);
		cout << "\n";
	}
	cout << "\n";
	{
		double vals[3][5] = {
			{1.1, 1.2, 1.3, 1.4, 1.5},
			{2.1, 2.2, 2.3, 2.4, 2.5},
			{3.1, 3.2, 3.3, 3.4, 3.5}
		};
		for (int i : range(3)) {
			for (int j : range(5))
				printf("%4.1f ", vals[i][j]);
			cout << "\n";
		}
		cout << "\n";
		modify2D(vals, 3);
		for (int i : range(3)) {
			for (int j : range(5))
				printf("%4.1f ", vals[i][j]);
			cout << "\n";
		}
		cout << "\n";
	}
}
