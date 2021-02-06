#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FE(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<PII> VII;
typedef map<int, int> MPII;
typedef unordered_map<int, int> UMPII;
typedef set<int> SETI;
typedef unordered_set<int> USETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

template <class T>
bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}

bool r(VI& a, VI& v, VB& used, int nUsed = 0, int idx = 0) {
    int s = v.size(); // size of used and v
    int sa = a.size();
    int nidx; // next valid index
    if (nUsed >= s) { // stop if all numbers are used
        return true;
    }
    REP(i, s) {
        if (!used[i] and idx + v[i] < sa and a[v[i] + idx] == -1) {
            used[i] = true; // mark number v[i] as used
            a[idx] = a[v[i] + idx] = v[i]; // assign value to correct positions
            for (nidx = idx + 1; nidx < sa and a[nidx] != -1; nidx++); // calc next valid index
            if (r(a, v, used, nUsed + 1, nidx)) return true; // explore, return if valid exploration
            a[idx] = a[v[i] + idx] = -1; // backtrack
            used[i] = false; // backtrack
        }
    }

    return false;
}

VI constructDistancedSequence(int n) {
    int len = 2 * (n - 1) + 1;
    VI ans(len, -1); // init ans with -1
    VI v(n);
    // fill v from n down to 2
    // Instead of 1, used 0 so that for all v[i]
    // ans[id] and ans[v[i] + id] behave the same
    // then replace 0 with 1 afterward
    iota(next(v.rbegin()), v.rend(), 2);
    VB used(n); // to mark each number in v is used
    r(ans, v, used); // recursion

    // replace the 0 in ans with 1
    REP(i, ans.size()) {
        if (ans[i] == 0) {
            ans[i] = 1;
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n) {
        auto res = constructDistancedSequence(n);
        for (int i : res) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}