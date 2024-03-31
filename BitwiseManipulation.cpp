#include<bits/stdc++.h>.h>
using namespace std;

//Not 100% checked

//Bitwise AND
//Bitwise OR
//Bitwise XOR
//Bitwise NOT
//Left Shift (<<) : Multiplies a number by 2
//Right Shift (>>) : Divides a number by 2 (integer division)
//How to check if a bit is on or off in a number
//How to find the on bits in a number
//How to find the off bits in a number
//How to find the number of on bits in a number
//How to check if a number is even or odd
//How to turn on a bit in a number
//How to turn off a bit in a number
//How to toggle a bit in a number
//How to find the power of 2
    //2 ^ n => (1 << n)
//How to check if a number is a power of 2

//Checks if the kth bit of x is set(1) or not(0)
//0-based indexing
int checkKthBit(int x, int k) {
    return (x >> k) & 1;
}

//Prints the position of all set bits in the binary representation of x
void printSetBits(int x) {
    for(int k = 0; k < 32; k++) {
        if(checkKthBit(x, k)) {
            cout << k << " ";
        }
        cout << "\n";
    }
}

//Returns the count of set bits in the binary representation of x
int countSetBits(int x) {
    int ans = 0;
    for(int k = 0; k < 32; k++) {
        if(checkKthBit(x, k)) {
            ans++;
        }
    }
    return ans;
}

//Checks if x is even or odd
bool isEven(int x) {
    return !(x & 1);
}

//Sets the kth bit of x to 1 and returns the result
int setKthBit(int x, int k) {
    return x | (1 << k);
}

//Resets the kth bit of x to 0 and returns the result
int resetKthBit(int x, int k) {
    return x & (~(1 << k));
}

//Toggles the kth bit of x and returns the result
int toggleKthBit(int x, int k) {
    return x ^ (1 << k);
}

//Checks if x is a power of 2
bool checkPowerOf2(int x) {
    return (countSetBits(x) == 1);
}

int main() {
    return 0;
}