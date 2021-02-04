///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <span>

#include <tclap/CmdLine.h>
#include <cppitertools/range.hpp>

#include "competition.hpp"
#include "params.hpp"
#include "pointers.hpp"

using namespace std;


const int maxSize = 50;

struct Computer {
	string format, compagnie; double tailleEcranPouces, cpuGHz;
	int memoireRamGiB, memoireDisqueGB;
};

struct ComputerList {
	Computer elems[maxSize];
	int      numElems = 0;
};

void tableauVsStruct(Computer tableau[maxSize], ComputerList& structure)
{
	tableau[0].cpuGHz = 2.2; // modifie le tableau original
	structure.elems[0].cpuGHz = 2.2; // modifie la copie de la structure
}

int main() {
	ComputerList foo = {};
	Computer bar[maxSize] = {};
	tableauVsStruct(bar, foo);
	cout << foo.elems[0].cpuGHz << " " << bar[0].cpuGHz << "\n";

	runParamsExample();
	cout << string(50, '-') << "\n";

	cout << "Competition example:" << "\n";
	runCompetitionExample();
	cout << string(50, '-') << "\n";
	
	cout << "1D dynamic arrays example:" << "\n";
	run1DDynamicArrayExample();
	cout << string(50, '-') << "\n";
	
	cout << "2D dynamic arrays example:" << "\n";
	run2DDynamicArrayExample();
	cout << string(50, '-') << "\n";
}

