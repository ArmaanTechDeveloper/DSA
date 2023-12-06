/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

#include <iostream>

using namespace std;

int partitionArray(int input[], int start, int end) {
	
	int pivot = start;

	int i=start;
	int j=end;

	while(i < j) {

		/*

		pivot ki sahi place find karne ke liye uske
		left side mein pivot se sare chote elements
		aur right side mein pivot se sare bade elements

		*/
		while(input[i] <= input[pivot] && i < end) i++;
		while(input[j] > input[pivot] && j > start) j--;

		if(i < j) swap(input[i] , input[j]);
	}

	swap(input[pivot] , input[j]);
	
	return j;
}

void quickSort(int input[], int start, int end) {
	if(start < end){

		int pIndex = partitionArray(input, start, end);

		// for the left part
		quickSort(input, start, pIndex -1);

		// for the right part
		quickSort(input, pIndex +1 , end);

	}
}