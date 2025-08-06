#include <bits/stdc++.h>
using namespace std;

class rectangle {
  public:
    int x1, x2, y1, y2;
    rectangle() {}
    rectangle(int x1, int x2, int y1, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
};

struct Event {
    int x, y1, y2, d;
    bool operator<(const Event& o) const {
        return x < o.x;
    }
};

class AreaCalculator {
  public:
    vector<int> ys;
    vector<long long> segLen;
    vector<int> segCnt;
    int m;

    void update(int idx, int l, int r, int ql, int qr, int d) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            segCnt[idx] += d;
        } else {
            int mid = (l + r) >> 1;
            update(idx<<1,     l,   mid, ql, qr, d);
            update(idx<<1|1, mid,     r, ql, qr, d);
        }
        if (segCnt[idx] > 0) {
            segLen[idx] = ys[r] - ys[l];
        } else if (l + 1 == r) {
            segLen[idx] = 0;
        } else {
            segLen[idx] = segLen[idx<<1] + segLen[idx<<1|1];
        }
    }

    long long compute(int n, rectangle r[]) {
        ys.clear();
        ys.reserve(2*n);
        for (int i = 0; i < n; i++) {
            ys.push_back(r[i].y1);
            ys.push_back(r[i].y2);
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        m = ys.size();

        vector<Event> ev;
        ev.reserve(2*n);
        for (int i = 0; i < n; i++) {
            int a = int(lower_bound(ys.begin(), ys.end(), r[i].y1) - ys.begin());
            int b = int(lower_bound(ys.begin(), ys.end(), r[i].y2) - ys.begin());
            ev.push_back({r[i].x1, a, b, +1});
            ev.push_back({r[i].x2, a, b, -1});
        }
        sort(ev.begin(), ev.end());

        segLen.assign(4*m, 0LL);
        segCnt.assign(4*m, 0);

        long long A = 0;
        int prevX = ev[0].x;
        for (auto &e : ev) {
            A += (long long)(e.x - prevX) * segLen[1];
            update(1, 0, m-1, e.y1, e.y2, e.d);
            prevX = e.x;
        }
        return A;
    }
};

long long int totalArea(int n, rectangle r[]) {
    AreaCalculator calc;
    return calc.compute(n, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    rectangle r[n];
    for (int i = 0; i < n; i++) {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
    }
    cout << totalArea(n, r) << "\n";
    return 0;
}
