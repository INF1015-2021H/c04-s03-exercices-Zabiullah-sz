///
/// Exemples des slides sur les pointeurs et les références
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <cstdio>

#include <cppitertools/range.hpp>

using namespace std;
using iter::range;


void run1DDynamicArrayExample() {
	// Déclaration d'un tableau dynamique d'entiers à une dimension.
	int* array;
	// Attribution d’un tableau de 150 entiers.
	array = new int[150];
	// Adresses du tableau et des cases.
	cout << "Address: " << array << endl;
	for (int i : range(3))
		printf("&array[%i]: %p" "\n", i, &array[i]);
	cout << "\n";
	// Initialise chaque valeur du tableau à 0.
	for (int i : range(150))
		array[i] = 0;
	// Remet en disponibilité l'espace mémoire du tableau d'entiers.
	delete[] array;
	array = nullptr;
	// Affiche (les adresses varient d'une exécution à l'autre):
	// Adresse du tableau: 00032F00
	// &array[0] est 00032F00; &array[1] est 00032F04; &array[2] est 00032F08;
}

void run2DDynamicArrayExample() {
	int height = 20;
	int width = 30;

	// Déclaration d'un tableau de réels à deux dimensions,
	// pemettant des lignes de longueurs différentes:
	double** mat;
	// Attribution de l'espace pour un tableau de 20 lignes x 30 colonnes:
	mat = new double*[height]; // Espace pour les 20 pointeurs de lignes.
	for (int row : range(height)) // Pour chaque row,
		mat[row] = new double[width]; // espace pour 30 colonnes de la row.
	// Initialise chaque valeur de la mat à zéro:
	for (int row : range(height))
		for (int col : range(width))
			mat[row][col] = 0.0;
	// Libération de l'espace mémoire:
	for (int row : range(height)) // Pour chaque row,
		delete[] mat[row]; // libérer l'espace pour la row.
	delete[] mat; // Libérer l'espace mémoire des pointeurs de lignes.
	mat = nullptr;

	// Déclaration d'un tableau de réels à "deux dimensions",
	// en utilisant un tableau une dimension:
	double* mat2;
	// Attribution de l'espace pour un tableau de 20 lignes x 30 colonnes:
	mat2 = new double[height * width];
	// Initialise chaque valeur de la mat à zéro:
	for (int row : range(height))
		for (int col : range(width))
			mat2[row*width + col] = 0.0;
	// Libération de l'espace mémoire:
	delete[] mat2;
	mat2 = nullptr;
}