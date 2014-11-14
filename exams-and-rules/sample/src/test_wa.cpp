#include "binary_heap.h"

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void gen( int n, vector <int> &a ) {
  a.resize(n);
  forn(i, n)
    a[i] = rand();
}

const int maxN = 100;
Heap<int, INT_MAX, maxN> h;

int main() {
  vector <int> x, ns = {3, 5, 10, 20, maxN};
  for (auto n : ns) // size of test
    forn(t, 10000) { // number of tests
      gen(n, x);
      // test build + extract
      h.build(n, x.begin());
      forn(i, n) {
        auto it = min_element(x.begin(), x.end());
        assert(h.extractMin() == *it);
        x.erase(it);
      }
      // test add + extract + min
      gen(n, x);
      forn(i, n)
        h.add(x[i]);
      forn(i, n) {
        auto it = min_element(x.begin(), x.end());
        assert(h.min() == *it);
        assert(h.extractMin() == *it);
        x.erase(it);
      }
    }
  fprintf(stderr, "Test for WA: OK.\n");
}
