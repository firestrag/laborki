//============================================================================
// Name        : heap_sort.cpp
// Author      : Konrad Str¹g
// Version     :
// Copyright   : All right reserved
// Description : Heap sort in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void out(string text, int array[], int size);
void out_heap(int array[], int start, int size, int tabs_count);
void make_heap(int array[], int first, int last);
void heap_sort(int arrray[], int size);

int main() {

	int array[] = {5, 6, 3, 7, 9, 8, 4 };
//	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof( array ) / sizeof( int );

	out("Tablica na poczatku", array, size);
	make_heap(array, 1, size);
	out("Tablica po stworzeniu kopca", array, size);
	out_heap(array, 1, size, 0);
	heap_sort(array, size);
	out("Tablica po posortowaniu", array, size);
	return 0;
}

void heap_sort(int array[], int size){
	for(int i=1; i<=size; i++){
		make_heap(array, i, size);
	}
}

void out_heap(int array[], int start,  int size, int tab_count){
	if(!tab_count)
		for(int i=0; i<80; i++) cout << "-";

	if(start > size) return;

	for(int i=0; i<tab_count; i++) cout << "    ";
	cout << array[start-1] << endl;

	out_heap(array, start*2, size, tab_count+1);
	out_heap(array, start*2+1, size, tab_count+1);
}

void make_heap(int array[], int first, int last){

	for(int i=0; i<=last-first; i++){
		for(int j=i; j>=0; j/=2){



			if(array[j-1+first] > array[(j/2)-1+first])
				swap(array[j-1+first], array[(j/2)-1+first]);
			else
				break;
		}
	}

	for(int i=first; i<=last; i++){
		if(i*2+1 > last) continue;
		if( array[i*2] > array[i*2-1])
			swap(array[i*2], array[i*2+1]);
	}

}

void out(string text, int array[], int size){
	int lenght = text.length();
	int i = 0;
	int a = (80 - lenght) / 2;
	a-=2;

	for(i=0;i<a;i++) cout << "=";
	cout << " " << text << " ";
	for(i=i+lenght+2; i<80; i++) cout << "=";

	for(i=0; i<size; i++){
		cout << "tab[ " << i << " ]:  " << array[i] << endl;
	}
}
