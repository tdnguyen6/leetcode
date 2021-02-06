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

VI commaDelimVector(string s) {
    VI v;
    s.pop_back();
    stringstream ss(s.substr(1));
    while (ss.good()) {
        string ts;
        getline(ss, ts, ',');
        v.push_back(stoi(ts));
    }
    return v;
}

VVI commaDelimVectorOfVector(string s) {
    VVI v;
    s.pop_back();
    stringstream ss(s.substr(1));
    while (ss.good() and ss.str() != "") {
        string ts;
        getline(ss, ts, '|');
        v.push_back(commaDelimVector(ts));
    }
    return v;
}

int minimumHammingDistance(VI& source, VI& target, VVI& allowedSwaps) {
    int s = source.size(), res = 0;
    VI u(s, -1);
    function<int(int)> find = [&](int i) {
        return (u[i] < 0) ? i : u[i] = find(u[i]);
    };
    for(auto& sw : allowedSwaps) {
        int i = find(sw[0]), j = find(sw[1]);
        if(i != j) {
            if(u[i] > u[j])
                swap(i,j);
            u[i] += u[j];
            u[j] = i;
        }
    }
    vector<unordered_multiset<int>> unions(s);
    REP(i, s) {
        if (source[i] != target[i])
            unions[find(i)].insert(source[i]);
    }
    REP(i, s) {
        if (source[i] != target[i]) {
            auto &Union = unions[find(i)];
            auto it = Union.find(target[i]);
            if(it != Union.end()) {
                Union.erase(it);
            } else {
                res++;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test = 4;
    while (n_test--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        VI s = commaDelimVector(s1), d = commaDelimVector(s2);
        VVI sw = commaDelimVectorOfVector(s3);
        cout << minimumHammingDistance(s, d, sw) << '\n';
    }
}