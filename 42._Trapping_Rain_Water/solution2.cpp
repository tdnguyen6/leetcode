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
vector<int> input()
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
    return vec;
}

int solved(vector<int> nums)
{
    if (nums.size() <= 1)
        return 0;
    int max_h = 0, max_idx = 0, sum = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int diff = nums[i] - max_h;
        if (diff >= 0)
        {
            max_idx = i;
            max_h = nums[i];
        }
        else
        {
            if (i == (int)nums.size() - 1)
            {
                diff = max(nums[i - 1], nums[i]) - max_h;
                int redundant = (i - 1 - max_idx) * -diff;
                if (sum >= redundant)
                    sum -= redundant;
            }
            else
            {
                sum += -diff;
            }
        }
    }
    return sum;
}

int calTrappedRain(int l, int r, vector<int> height)
{
    int rain = 0;
    int level = min(height[l], height[r]);
    for (int i = l + 1; i < r; i++)
    {
        rain += level - height[i];
    }
    return rain;
}

int solve(vector<int> height)
{
    if (height.size() < 2)
        return 0;
    int max_h = 0, max_h_idx = -1;
    for (int i = 0; i < (int)height.size(); i++)
    {
        if (height[i] > max_h)
        {
            max_h = height[i];
            max_h_idx = i;
        }
    }

    vector<int> up_pattern{0}, down_pattern{(int)height.size() - 1};
    for (int i = 1; i <= max_h_idx; i++)
    {
        if (height[i] >= height[up_pattern.back()])
            up_pattern.push_back(i);
    }

    for (int i = (int)height.size() - 2; i >= max_h_idx; i--)
    {
        if (height[i] >= height[down_pattern.back()])
            down_pattern.push_back(i);
    }

    int sum = 0;

    for (int i = 0; i < (int)up_pattern.size() - 1; i++)
    {
        if (up_pattern[i + 1] - up_pattern[i] > 1)
            sum += calTrappedRain(up_pattern[i], up_pattern[i + 1], height);
    }

    for (int i = 0; i < (int)down_pattern.size() - 1; i++)
    {
        if (down_pattern[i] - down_pattern[i + 1] > 1)
            sum += calTrappedRain(down_pattern[i + 1], down_pattern[i], height);
    }

    return sum;
}

// string output(vector<int> solution)
// {
//     stringstream answer;
//     answer << "";
//     return answer.str();
// }

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
        cout << solve(input()) << endl;
    }
}
