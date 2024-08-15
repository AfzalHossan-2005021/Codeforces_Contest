#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

void solve() {
    int n, q; cin >> n >> q;
    vi p(n), a(n), pos(n);
    for (int i = 1; i < n; i++)
        cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++)
        cin >> a[i], pos[--a[i]] = i;
    p[0] = -1;

    auto h = [&](int i) -> int {
        return __lg(__bit_ceil(n / (i + 1) + 1));
    };

    int bad = pos[0] != 0;
    for (int i = 1; i < n; i++)
        if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
            bad++;

    auto remove = [&](int i) -> void {
        if (i == 0)
            bad -= pos[i] != 0;
        else
            if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
                bad--;
        i = ((i + 1) << 1) - 1;
        if (i >= n) return;
        if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
            bad--;
        i++;
        if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
            bad--;
    };

    auto add = [&](int i) -> void {
        if (i == 0)
            bad += pos[i] != 0;
        else
            if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
                bad++;
        i = ((i + 1) << 1) - 1;
        if (i >= n) return;
        if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
            bad++;
        i++;
        if (pos[i] != pos[p[i]] + 1 and pos[i] != pos[p[i]] + (1 << h(i)))
            bad++;
    };

    while (q--) {
        int x, y; cin >> x >> y;
        int i = a[--x], j = a[--y];
        int big = max(i, j), sml = min(i, j);
        remove(i); remove(j);
        if (((sml + 1) << 1) - 1 == big or ((sml + 1) << 1) == big)
            if (pos[big] != pos[sml] + 1 and pos[big] != pos[sml] + (1 << h(big)))
                bad++;
        pos[i] = y, pos[j] = x;
        swap(a[x], a[y]);
        add(i); add(j);
        if (i > j) swap(i, j);
        if (((sml + 1) << 1) - 1 == big or ((sml + 1) << 1) == big)
            if (pos[big] != pos[sml] + 1 and pos[big] != pos[sml] + (1 << h(big)))
                bad--;
        cout << (bad == 0 ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}