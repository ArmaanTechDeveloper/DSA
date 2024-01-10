#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumberOne(vector<int>& nums) {
        long long int sum = 0;

        int n = nums.size();
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
        }

        long long int originalSum = (n*(n+1))/2;

        if(originalSum == sum) return 0;
        
        return originalSum - sum;
    }

    int missingNumberTwo(vector<int>& nums) {
        int n = nums.size();

        int xor1=0;
        int xor2 = 0;
        for(int j=0 ; j<n ; j++){
            xor2 = xor2 ^ nums[j];
            xor1 = xor1 ^ (j+1);
        }

        return xor1 ^ xor2;

    }
};