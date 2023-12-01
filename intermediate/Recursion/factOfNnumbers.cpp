#include <vector>

using namespace std;

int fact(long long x){
    if (x == 0) return 1;
    return x * fact(x-1);
}
vector<long long> factorialNumbers(long long n) {

    vector <long long> temp;

    for(int i=1 ; i<=n ; i++){

        int k = fact(i);
        
        if(k > n) return temp;
        else temp.push_back(k);
    }
}