#include <bits/stdc++.h>

using namespace std;

template <class T, const T INF, const int N>
struct Heap {
  int n;
  T h[N + 1];

  Heap() { n = 0; }
  Heap( int n, T *a ) { build(n, a); }

  void clear() { n = 0; }
  
  template <class POINTER>
  void build( int an, POINTER a ) { // O(n)
    clear();
    for (int i = 0; i < an; i++)
      h[++n] = *a++;
    for (int i = n; i >= 1; i--)
      down(i);
  }

  void up( int i ) { // O(logi)
    T y = h[i];
    for (; i > 1 && h[i >> 1] > y; i >>= 1) 
      h[i] = h[i >> 1];
    h[i] = y;
  }
  void add( int x ) { // O(logn)
    h[++n] = x, up(n);
  }
  int down( int v ) { // O(log(n/v))
    while (v < n) {
      int m = v, l = 2 * v, r = l + 1;
      if (l <= n && h[l] < h[m]) m = l;
      if (r <= n && h[r] < h[m]) m = r;
      if (m == v)
        break;
      swap(h[m], h[v]);
      v = m;
    }
    return v;
  }
  T extractMin() { // O(logn)
    T result = h[1];
    assert(n >= 1);
    h[1] = h[n--];
    down(1);
    return result;
  }
  T min() { return n ? h[1] : INF; } // O(1)
};
