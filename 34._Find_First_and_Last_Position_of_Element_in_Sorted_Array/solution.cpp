#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
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

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
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

/**************************************/

/******** Utilities Function *******/
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/* void file()
{
    auto a = freopen("a.in", "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if (!a || !b)
        cout << "uh oh" << endl;
} */

/**************************************/

/******** User-defined Function *******/
int binSearch(vector<int> v, int l, int r, int key, bool left_end = true)
{
    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == key)
        {
            if (left_end)
            {
                if (mid == 0 || (mid > 0 && v[mid - 1] != key))
                {
                    return mid;
                }
                r = mid - 1;
            }
            else
            {
                if (mid == (int) v.size() - 1 || (mid < (int) v.size() - 1 && v[mid + 1] != key))
                {
                    return mid;
                }
                l = mid + 1;
            }
        }
        else if (v[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

tuple<vector<int>, int> input()
{
    string str;
    cin >> str;
    str.pop_back();
    str = str.substr(1);
    vector<int> vec;
    if (!str.empty())
    {
        stringstream ss(str);
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            vec.push_back(stoi(substr));
        }
    }
    int target;
    cin >> target;
    return {vec, target};
}

vector<int> solve(tuple<vector<int>, int> input)
{
    vector<int> nums;
    int target;
    tie(nums, target) = input;
    int left = binSearch(nums, 0, nums.size() - 1, target);
    int right = binSearch(nums, left >= 0 ? left : 0, nums.size() - 1, target, false);
    return {left, right};
}

string output(vector<int> solution)
{
    stringstream answer;
    answer << '[' << solution[0] << ',' << solution[1] << ']';
    return answer.str();
}

/**************************************/

/********** Main()  function **********/

int main()
{
    fast();
    // file();

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        cout << output(solve(input())) << endl;
    }
}
