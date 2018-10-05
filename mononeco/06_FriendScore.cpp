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

class FriendScore {
public:
    int highestScore(vector<string> &friends) {
        vector<vector<bool>> distance1, distance2;
        distance1 = vector<vector<bool>>(friends.size(), vector<bool>(friends.size(), false));
        distance2 = vector<vector<bool>>(friends.size(), vector<bool>(friends.size(), false));
        REP(i, friends.size()) {
            REP(j, friends.size()) {
                distance1[i][j] = friends[i][j] == 'Y';
            }
        }
        REP(i, friends.size()) {
            REP(j, friends.size()) {
                if (distance1[i][j]) {
                    REP(k, friends.size()) {
                        if (distance1[j][k] && i != k) {
                            distance2[i][k] = true;
                        }
                    };
                }
            }
        }
        int maxScore = 0;
        REP(i, friends.size()) {
            int score = 0;
            REP(j, friends.size()) {
                if(distance1[i][j] || distance2[i][j]) {
                    score++;
                }
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
