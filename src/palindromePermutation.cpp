/* CTCI */
/* Function to check if the given string is a permutation of a palindrome */

/* We iterate through a hash table and ensure that no more than one char */
/* has an odd count. */

/* Time Complexity: O(N) */
/* Space Complexity: O(N) */

/* We dont necessarily need to know the count of each letters */
/* we just need to know if it is odd or even. */
/* Hence, we can use a bit vector as a toggle switch */

#include <bits/stdc++.h>
using namespace std;

/* map each char to number, a -> 0, b -> 1, c -> 2, ... */
int getCharNumber(char c) {
    int a = 'a';
    int z = 'z';
    int val = (int) c;

    if (a <= val && val <= z)
        return val - a;
    return -1;
}

/* count how many times each character appears */
vector<int> buildCharFrequencyTable(string str) {
    vector<int> table('z' - 'a' + 1);

    for (char c: str) {
        int x = getCharNumber(c);
        if (x != -1)
            table[x]++;
    }
    return table;
}

/* check that no more than one character has an odd count */
bool checkMaxOneOdd(vector<int>& table) {
    bool foundOdd = false;

    for (int count : table) {
        if (count % 2 == 1) {
            if (foundOdd)
                return false;

            foundOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome(string str) {
    vector<int> table;
    table = buildCharFrequencyTable(str);
    return checkMaxOneOdd(table);
}

/* toggle the ith bit in the integer */
int toggle(int bitVector, int index) {
    if (index < 0)
        return bitVector;

    int mask = 1 << index;

    if ((bitVector & mask) == 0)
        bitVector |= mask;
    else
        bitVector &= ~mask;

    return bitVector;
}

/* create a bit vector. For each letter with value i, toggle the ith bit */
int createBitVector(string str) {
    int bitVector = 0;
    for (char c : str) {
        int x = getCharNumber(c);
        bitVector = toggle(bitVector, x);
    }
    return bitVector;
}

/* check that exactly one bit is set by subtracting one from the integer and */
/* ANDing it with the original integer */
bool checkExactlyOneBitSet(int bitVector) {
    return (bitVector & (bitVector - 1)) == 0;
}

bool isPermutationOfPalindrome2(string str) {
    int bitVector = createBitVector(str);
    return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    cout << isPermutationOfPalindrome(str) << "\n";
    cout << isPermutationOfPalindrome2(str) << "\n";

    return 0;
}
