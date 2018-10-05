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

class CrazyBot {
public:
    double getProbability(int n, int east, int west, int south, int north) {
        double ans = 0;
        double probability = 1;
        vector<P> path;
        path.push_back({0, 0});
        dig(n, east, west, south, north, ans, probability, path);
        return 1 - ans;
    }

public:
    void dig(int n, int east, int west, int south, int north, double &ans, double &probability, vector<P> &path) {
        if (path.size() == n + 1) {
            return;
        }
        if (east > 0) {
            auto newX = (int) path[path.size() - 1].first + 1;
            auto newY = (int) path[path.size() - 1].second;
            if (hasPath(path, {newX, newY})) {
                path.push_back({newX, newY});
                probability *= east;
                dig(n, east, west, south, north, ans, probability, path);
                path.pop_back();
                probability /= east;
            } else {
                ans += probability * east / pow(100, path.size());
            }
        }
        if (west > 0) {
            auto newX = (int) path[path.size() - 1].first - 1;
            auto newY = (int) path[path.size() - 1].second;
            if (hasPath(path, {newX, newY})) {
                path.push_back({newX, newY});
                probability *= west;
                dig(n, east, west, south, north, ans, probability, path);
                path.pop_back();
                probability /= west;
            } else {
                ans += probability * west / pow(100, path.size());
            }
        }
        if (north > 0) {
            auto newX = (int) path[path.size() - 1].first;
            auto newY = (int) path[path.size() - 1].second + 1;
            if (hasPath(path, {newX, newY})) {
                path.push_back({newX, newY});
                probability *= north;
                dig(n, east, west, south, north, ans, probability, path);
                path.pop_back();
                probability /= north;
            } else {
                ans += probability * north / pow(100, path.size());
            }
        }
        if (south > 0) {
            auto newX = (int) path[path.size() - 1].first;
            auto newY = (int) path[path.size() - 1].second - 1;
            if (hasPath(path, {newX, newY})) {
                path.push_back({newX, newY});
                probability *= south;
                dig(n, east, west, south, north, ans, probability, path);
                path.pop_back();
                probability /= south;
            } else {
                ans += probability * south / pow(100, path.size());
            }
        }
    }

public:
    bool hasPath(vector<P> &path, P position) {
        for (auto throughPosition : path) {
            if (throughPosition.first == position.first && throughPosition.second == position.second) {
                return false;
            }
        }
        return true;
    }
};