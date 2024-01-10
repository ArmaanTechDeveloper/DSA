#include <set>
#include <vector>

using namespace std;


int removeDuplicates(vector<int> &arr, int n) {
	/*

	---- APPROACH 1 -----

	set<int> st;

	for(int i=0 ; i<n ; i ++) st.insert(arr[i]);

	return st.size();

	*/

	int index = 1;
	int elem = arr[0];

	for(int i=0 ; i<n ; i ++){

		if(elem != arr[i]){
			arr[index] = arr[i];
			elem = arr[i];
			index ++;

		}
	}

	return index;
}