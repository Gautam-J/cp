/* CF - 900 */
/*
A. Wizards' Duel
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Harry Potter and He-Who-Must-Not-Be-Named engaged in a fight to the death once again. This time they are located at opposite ends of the corridor of length l. Two opponents simultaneously charge a deadly spell in the enemy. We know that the impulse of Harry's magic spell flies at a speed of p meters per second, and the impulse of You-Know-Who's magic spell flies at a speed of q meters per second.

The impulses are moving through the corridor toward each other, and at the time of the collision they turn round and fly back to those who cast them without changing their original speeds. Then, as soon as the impulse gets back to it's caster, the wizard reflects it and sends again towards the enemy, without changing the original speed of the impulse.

Since Harry has perfectly mastered the basics of magic, he knows that after the second collision both impulses will disappear, and a powerful explosion will occur exactly in the place of their collision. However, the young wizard isn't good at math, so he asks you to calculate the distance from his position to the place of the second meeting of the spell impulses, provided that the opponents do not change positions during the whole fight.

Input
The first line of the input contains a single integer l (1?²?l?²?1?000) Ñ the length of the corridor where the fight takes place.

The second line contains integer p, the third line contains integer q (1?²?p,?q?²?500) Ñ the speeds of magical impulses for Harry Potter and He-Who-Must-Not-Be-Named, respectively.

Output
Print a single real number Ñ the distance from the end of the corridor, where Harry is located, to the place of the second meeting of the spell impulses. Your answer will be considered correct if its absolute or relative error will not exceed 10?-?4.

Namely: let's assume that your answer equals a, and the answer of the jury is b. The checker program will consider your answer correct if .

Examples
inputCopy
100
50
50
outputCopy
50
inputCopy
199
60
40
outputCopy
119.4
Note
In the first sample the speeds of the impulses are equal, so both of their meetings occur exactly in the middle of the corridor.
*/

/* Time Complexity: O(1) */
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

long double solve(long double l, long double p, long double q) {
    long double res, firstMeetTime;

    // d = s * t
    firstMeetTime = l / (p + q);
    res = p * firstMeetTime;

    return res;
}

const char nl = '\n';
const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long double l, p, q;
    cin >> l >> p >> q;
    cout << solve(l, p, q) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
