/*
 * quickSort.cpp
 *
 *  Created on: Nov 4, 2018
 *      Author: Harrison.Ding
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> store;
int size = 10;

/*void swap(int & a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void quick_sort(int left, int right) {
	int tmp = store.at(left);

	if (left > right)
		return;

	int l = left, r = right;

	while (l != r) {
		while (store.at(r) >= tmp && l < r)
			r--;
		while (store.at(l) <= tmp && l < r)
			l++;

		if (l <= r)
			swap(store.at(l), store.at(r));
	}
	swap(store.at(left), store.at(l));

	quick_sort(left, l - 1);
	quick_sort(l + 1, right);
 }*/

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

int partition(int left, int right) {
	int pivotKey = store.at(left);

	while(left < right) {
		while(left < right && store.at(right) >= pivotKey)
			right--;
		store[left] = store[right];
		while (left < right && store.at(left) <= pivotKey)
			left++;
		store[right] = store[left];
	}
	store[left] = pivotKey;
	return left;
}

void quickSort(int left, int right) {
	if(left >= right)
		return;
	int pivotPos = partition(left, right);
	quickSort(left, pivotPos - 1);
	quickSort(pivotPos + 1, right);
}

void sort() {
	if (store.size() == 0)
		return;
	quickSort(0, store.size() - 1);
}


int main() {
	init();
	cout << "After init ..." << endl;
	show();

	sort();
	cout << "\nAfter quick sort ..." << endl;
	show();

}

