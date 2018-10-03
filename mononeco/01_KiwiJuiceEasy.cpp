#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <ctime>

using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef long long int ll;
typedef pair<ll, ll> P;

// combination
const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// gcd, lcm
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

class KiwiJuiceEasy {
public:
    vector<int>
    thePouring(vector<int> &capacityList, vector<int> &amountList, vector<int> &fromIdList, vector<int> &toIdList) {
        REP(i, fromIdList.size()) {
            pour(i, capacityList, amountList, fromIdList, toIdList);
        }
        return amountList;
    }

public:
    int
    pour(int &i, vector<int> &capacityList, vector<int> &amountList, vector<int> &fromIdList, vector<int> &toIdList) {
        int from = fromIdList[i];
        int to = toIdList[i];
        int moveAmount = min(amountList[from], capacityList[to] - amountList[to]);
        amountList[from] -= moveAmount;
        amountList[to] += moveAmount;
        return 0;
    }
};
