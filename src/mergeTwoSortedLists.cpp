// LC - Easy, grind 3
/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

/* Time Complexity: O(n + m) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
/* const ld PI = acos(-1.0); */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve1(ListNode* list1, ListNode* list2) {
    // Iterative Algorithm:
    // If any of the given lists is empty, return the other one.
    // Create pointer "head", that points to the smallest of first elements.
    // This pointer should be returned at the end.
    // Create another pointer res that points to head.
    //
    // while list1 and list2 are not null, iterate through them
    // if list1->val < list2->val, then res->next = list1, list1 = list1->next
    // else res->next = list2, list2 = list2->next
    // update res = res->next
    //
    // after the while loop ends, at least one list will be completed.
    // so check whichever list is not null, and simply point res to it.
    // return head
    //
    // Time: O(n + m)
    // Space: O(1)

    if (!list1)
        return list2;
    if (!list2)
        return list1;

    ListNode* head = new ListNode();
    ListNode* movingTail = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            movingTail->next = list1;
            list1 = list1->next;
        } else {
            movingTail->next = list2;
            list2 = list2->next;
        }
        movingTail = movingTail->next;
    }

    if (!list1)
        movingTail->next = list2;
    else
        movingTail->next = list1;

    return head->next;
}

ListNode* solve2(ListNode* list1, ListNode* list2) {
    // Recursive Algorithm:
    // If any of the given lists is empty, return the other one.
    // If list1 has smaller element, call func recursively with l1->next, l2;
    // set the returned value to l1->next, and return l1
    // else call func recursively with l1, l2->next;
    // set the returned value to l2->next, and return l2
    //
    // Time: O(n + m)
    // Space: O(n + m)

    if (!list1)
        return list2;
    if (!list2)
        return list1;

    if (list2->val >= list1->val) {
        list1->next = solve2(list1->next, list2);
        return list1;
    }

    list2->next = solve2(list1, list2->next);
    return list2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
