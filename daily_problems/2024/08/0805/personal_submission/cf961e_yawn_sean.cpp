#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        p++;
        while (p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> tmp(n);

    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        nums[i] = min(nums[i], n) - 1;
        tmp[nums[i]].emplace_back(i);
    }

    long long ans = 0;
    fenwick_tree<int> fen(n);
    for (int i = n - 1; i >= 0; i --) {
        for (auto &x: tmp[i])
            fen.add(x, 1);
        if (nums[i] > i)
            ans += fen.sum(i + 1, nums[i] + 1);
    }
    cout << ans;

    return 0;
}