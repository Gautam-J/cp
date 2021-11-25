// CF -
/*
A. Make Even
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has an integer n that doesn't contain the digit 0. He can do the following operation with his number several (possibly zero) times:

Reverse the prefix of length l (in other words, l leftmost digits) of n. So, the leftmost digit is swapped with the l-th digit from the left, the second digit from the left swapped with (l−1)-th left, etc. For example, if n=123456789 and l=5, then the new value of n will be 543216789.
Note that for different operations, the values of l can be different. The number l can be equal to the length of the number n — in this case, the whole number n is reversed.

Polycarp loves even numbers. Therefore, he wants to make his number even. At the same time, Polycarp is very impatient. He wants to do as few operations as possible.

Help Polycarp. Determine the minimum number of operations he needs to perform with the number n to make it even or determine that this is impossible.

You need to answer t independent test cases.

Input
The first line contains the number t (1≤t≤104) — the number of test cases.

Each of the following t lines contains one integer n (1≤n<109). It is guaranteed that the given number doesn't contain the digit 0.

Output
Print t lines. On each line print one integer — the answer to the corresponding test case. If it is impossible to make an even number, print -1.

Example
inputCopy
4
3876
387
4489
3
outputCopy
0
2
1
-1
Note
In the first test case, n=3876, which is already an even number. Polycarp doesn't need to do anything, so the answer is 0.

In the second test case, n=387. Polycarp needs to do 2 operations:

Select l=2 and reverse the prefix 38–––7. The number n becomes 837. This number is odd.
Select l=3 and reverse the prefix 837––––. The number n becomes 738. This number is even.
It can be shown that 2 is the minimum possible number of operations that Polycarp needs to do with his number to make it even.

In the third test case, n=4489. Polycarp can reverse the whole number (choose a prefix of length l=4). It will become 9844 and this is an even number.

In the fourth test case, n=3. No matter how hard Polycarp tried, he would not be able to make an even number.

*/

/* Time Complexity: O(log_10 n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int solve(int n) {
    if (n < 10)
        return n % 2 == 0 ? 0 : -1;

    // if first digit is even
    if ((n % 10) % 2 == 0)
        return 0;

    // if last digit is even
    int temp = n, digit;
    while (temp) {
        digit = temp % 10;
        temp /= 10;
    }
    if (digit % 2 == 0)
        return 1;

    temp = n;
    while (temp) {
        digit = temp % 10;
        temp /= 10;

        if (digit % 2 == 0)
            return 2;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve(n) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
