
#include <bits/stdc++.h>


using namespace std;

// we are following here 1 based indexing
// leaf node index are from n/2 +1 --> n th index
class heap {

    public:
        int arr [100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int data){
            
        size = size +1;
        int index = size;
        arr[index] = data;

        while(index > 1){

            int parent = index /2;
            if(arr[parent] < arr[index]){

                swap(arr[parent] , arr[index]);
                index = parent;

            }
            else{
                return;
            }
        }
    }

    void print(){
        cout << endl;
        for(int i=1 ; i <= size ; i ++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromHeap(){
        if(size == 0){
            cout << "Nothing to delete " << endl;
        }

        arr[1] = arr[size];
        int i = 1;
        size --;

        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex && arr[i] < arr[leftIndex]){
                swap(arr[i] , arr[leftIndex]);
            }
            else if(rightIndex && arr[i] < arr[rightIndex]){
                swap(arr[i] , arr[rightIndex]);
            }
            else{
                return;
            }
        }
    }
};

void heapify(int * arr , int size , int index){

    
}

void print(int * arr , int size){
    cout << endl;
    for(int i=1 ; i <= size ; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // h.deletefromHeap(); 
    h.print();

    int arr[6] = {-1 , 50 , 55 , 53 , 52 , 54};
    int n = 5;
    for(int i= n/2 ; i > 0 ; i --){
        heapify(arr , n , i);
    }
    print(arr , n);
    return 0;
}