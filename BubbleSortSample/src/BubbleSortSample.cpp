//============================================================================
// Name        : BubbleSortSample.cpp
// Author      : Harrison
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int ElementData;
int size = 10;

//ElementData store[size];
vector<ElementData> store;

void swap(ElementData *a, ElementData *b) {
	ElementData t = *a;
	*a = *b;
	*b = t;
}
auto swap_lambda = [](ElementData &a, ElementData &b) {
	ElementData t = a;
	a = b;
	b = t;
};

void init() {
	srand((unsigned) time(NULL));
	for (int i = 0; i < size; i++) {
		store.push_back(rand() % 100);
	}
}

void show() {
	for_each(store.begin(), store.end(), [](int n) {cout << n << " ";});
	cout << endl;
}
// Target to large -> small
void bubble_desc() {
	int i = 0, j = 0;
	for (; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (store[j] > store[i]) {
				swap(store[i], store[j]);
			}
		}
		cout << "After loop - " << i + 1 << " : ";
		show();
	}
}

void bubble_asc() {
	int i = 0, j = 0;
	for (; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (store[j] < store[i]) {
				swap_lambda(store[i], store[j]);
			}
		}
		cout << "After loop - " << i + 1 << " : ";
		show();
	}
}

int main() {
	cout << "!!! Start Bubble Test!!!" << endl;
	init();
	cout << "\n After init ..." << endl;
	show();

	bubble_desc();
	cout << "\nAfter bubble sort: descend ..." << endl;
	show();

	bubble_asc();
	cout << "\nAfter bubble sort: ascend ..." << endl;
	show();

	return 0;
}
