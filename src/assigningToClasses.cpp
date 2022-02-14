/* CF - 1000 */
/*
B. Assigning to Classes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Reminder: the median of the array [??1,??2,É,??2??+1]
[
a
1
,
a
2
,
É
,
a
2
k
+
1
]
 of odd number of elements is defined as follows: let [??1,??2,É,??2??+1]
[
b
1
,
b
2
,
É
,
b
2
k
+
1
]
 be the elements of the array in the sorted order. Then median of this array is equal to ????+1
b
k
+
1
.

There are 2??
2
n
 students, the ??
i
-th student has skill level ????
a
i
. It's not guaranteed that all skill levels are distinct.

Let's define skill level of a class as the median of skill levels of students of the class.

As a principal of the school, you would like to assign each student to one of the 2
2
 classes such that each class has odd number of students (not divisible by 2
2
). The number of students in the classes may be equal or different, by your choice. Every student has to be assigned to exactly one class. Among such partitions, you want to choose one in which the absolute difference between skill levels of the classes is minimized.

What is the minimum possible absolute difference you can achieve?

Input
Each test contains multiple test cases. The first line contains the number of test cases ??
t
 (1²??²104
1
²
t
²
10
4
). The description of the test cases follows.

The first line of each test case contains a single integer ??
n
 (1²??²105
1
²
n
²
10
5
) Ñ the number of students halved.

The second line of each test case contains 2??
2
n
 integers ??1,??2,É,??2??
a
1
,
a
2
,
É
,
a
2
n
 (1²????²109
1
²
a
i
²
10
9
) Ñ skill levels of students.

It is guaranteed that the sum of ??
n
 over all test cases does not exceed 105
10
5
.

Output
For each test case, output a single integer, the minimum possible absolute difference between skill levels of two classes of odd sizes.

Example
inputCopy
3
1
1 1
3
6 5 4 1 2 3
5
13 4 20 13 2 5 8 3 17 16
outputCopy
0
1
5
Note
In the first test, there is only one way to partition students Ñ one in each class. The absolute difference of the skill levels will be |1?1|=0
|
1
?
1
|
=
0
.

In the second test, one of the possible partitions is to make the first class of students with skill levels [6,4,2]
[
6
,
4
,
2
]
, so that the skill level of the first class will be 4
4
, and second with [5,1,3]
[
5
,
1
,
3
]
, so that the skill level of the second class will be 3
3
. Absolute difference will be |4?3|=1
|
4
?
3
|
=
1
.

Note that you can't assign like [2,3]
[
2
,
3
]
, [6,5,4,1]
[
6
,
5
,
4
,
1
]
 or []
[
]
, [6,5,4,1,2,3]
[
6
,
5
,
4
,
1
,
2
,
3
]
 because classes have even number of students.

[2]
[
2
]
, [1,3,4]
[
1
,
3
,
4
]
 is also not possible because students with skills 5
5
 and 6
6
 aren't assigned to a class.

In the third test you can assign the students in the following way: [3,4,13,13,20],[2,5,8,16,17]
[
3
,
4
,
13
,
13
,
20
]
,
[
2
,
5
,
8
,
16
,
17
]
 or [3,8,17],[2,4,5,13,13,16,20]
[
3
,
8
,
17
]
,
[
2
,
4
,
5
,
13
,
13
,
16
,
20
]
. Both divisions give minimal possible absolute difference.
*/

/* Time Complexity: O(n lg n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)
#define pb push_back
#define SHUF(v) shuffle(all(v), mt_rand)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN

#ifdef _GLIBCXX_DEBUG
#define debug(...) cerr << "[DEBUG]: [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const double PI = acos(-1);

int solve(vi& a) {
    int n = sz(a);
    sort(all(a));

    return a[n/2] - a[(n/2)-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(2 * n);
        trav(i, a)
            cin >> i;

        cout << solve(a) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
