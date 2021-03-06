#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

/*
[ 0 1 0 0 0 ]   [ f(1) ]   [ f(2) ]
[ 0 0 1 0 0 ]   [ f(2) ]   [ f(3) ]
[ 0 0 0 1 0 ] * [ f(3) ] = [ f(4) ]
[ 0 0 0 0 1 ]   [ f(4) ]   [ f(5) ]
[ 1 0 1 1 0 ]   [ f(5) ]   [ f(6) ]
*/

template <typename T>
struct FastMatExpo {
    ll n, m;
    vector<vector<T>> scalar, mult, ident, res;
    FastMatExpo(vector<vector<T>> _scalar, vector<vector<T>> _mult, ll _m) 
    { scalar = _scalar; mult = _mult; n = scalar.size(); m = _m; createIdent(); }
    void createIdent() {
        ident = vector<vector<T>>(n, vector<T>(n, 0));
        for (int i = 0; i < n; i++) ident[i][i] = 1;
    }
    vector<vector<T>> modPow(ll pow) { return res = applyMod(fastPow(scalar, pow)); }
    vector<vector<T>> fastPow(vector<vector<T>> mat, ll pow) {
        mat = applyMod(mat);
        if (pow==0) return ident;
        if (pow==1) return mat;
        if (pow&1) return matMult(mat, fastPow(mat, pow-1));
        return applyMod(fastPow(matMult(mat, mat), pow/2));
    }
    vector<vector<T>> matMult(vector<vector<T>> mat1, vector<vector<T>> mat2) {
        vector<vector<T>> res(n, vector<T>(n, (T)0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res[i][j] = (res[i][j] + ((mat1[i][k] * mat2[k][j]) % m)) % m;
        return applyMod(res);
    }
    vector<vector<T>> applyMod(vector<vector<T>> mat) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] %= m;
        return mat;
    }
    ll getAns(ll index) {
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + ((res[index][i] * mult[i][index]) % m)) % m;
        return ans;
    }
};

void solve(int t) {
    ll n, m; cin >> n >> m;
    n--;
    vector<vector<ll>> scalar = {{0, 1, 0, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 0, 1, 0},
                                 {0, 0, 0, 0, 1},
                                 {1, 0, 1, 1, 0}};
    vector<vector<ll>> mult = {{0},
                               {1},
                               {1},
                               {1},
                               {3}};

    FastMatExpo<ll> fme = FastMatExpo<ll>(scalar, mult, m);
    fme.modPow(n);
    cout << fme.getAns(0) << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 0; t < tt; t++)
        solve(t);    

    return 0;
}
