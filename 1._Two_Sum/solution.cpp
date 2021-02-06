#pragma GCC optimize("Ofast")
// -fopt-info, -fopt-info-loop, -fopt-info-loop-missed, -fopt-info-vec, -fopt-info-vec-missed
// #pragma GCC optimization("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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
#define EB emplace_back
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

/******** User-defined Function *******/

/********** Main()  function **********/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto a = freopen("a.in", "r", stdin);
    // auto b = freopen("a.out", "w", stdout);
    // if (!a || !b)
    //     cout << "uh oh" << endl;

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        // input
        string s;
        cin >> s;
        s.pop_back();
        s = s.substr(1);
        vector<int> nums;
        stringstream ss(s);
        while (!s.empty() && ss.good())
        {
            string s_part;
            getline(ss, s_part, ',');
            nums.push_back(stoi(s_part));
        }

        int target;
        cin >> target;

        // start solution
        int len = nums.size();
        map<int, vector<int>> m;
        REP(i, len)
            m[nums[i]].EB(i);

        // find
        int ans;
        REP(i, len)
        {
            auto found_v = m.find(target - nums[i]);
            if (found_v != m.end())
            {
                ans = found_v->second.back();
                if (ans != i)
                {
                    return ans;
                }
            }
        }
    }
}

/****** Template of some basic operations *****/
/* template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
} */

/**********************************************/

/****** Template of Fast I/O Methods *********/
/* template <typename T>
inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n * s;
} */
/************************************/

/******* Debugging Class Template *******/
/* #define DEBUG

#ifdef DEBUG

#define debug(args...) (Debugger()), args

class Debugger
{
public:
    Debugger(const std::string &_separator = " - ") : first(true), separator(_separator) {}

    template <typename ObjectType>
    Debugger &operator,(const ObjectType &v)
    {
        if (!first)
            cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger()
    {
        cerr << endl;
    }

private:
    bool first;
    std::string separator;
};

#else
#define debug(args...) // Just strip off all debug tokens
#endif */