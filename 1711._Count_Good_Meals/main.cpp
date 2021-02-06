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
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

ll binomialCoeff(int n, int k) {
    ll C[k + 1];

    memset(C, 0, sizeof(C));

    C[0] = 1;  // nC0 is 1

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--)
            C[j] += C[j - 1];
    }
    return C[k];
    return 0;
}

int countPairs(vector<int>& D) {
    int p2[22];
    REP(i, 22) {
        p2[i] = 1 << i;
    }

    map<int, int> um;
    for (auto d : D) {
        um[d]++;
    }
    ll ans = 0;
    int o;
    for (auto& [d, f] : um) {
        REP(i, 22) {
            o = p2[i] - d;
            if (o >= d && um.find(o) != um.end()) {
                if (o != d)
                    ans += (f * um[o]) % MOD;
                else
                    ans += binomialCoeff(f, 2) % MOD;
            }
        }
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test;
    cin >> n_test;
    while (n_test--) {
        int N;
        cin >> N;
        VI D(N);
        REP(i, N) {
            cin >> D[i];
        }
        cout << countPairs(D) << '\n';
    }
}