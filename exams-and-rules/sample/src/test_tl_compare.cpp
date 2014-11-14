#include "binary_heap.h"
                                                                                 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

unsigned R() { return (rand() << 15) | rand(); } // mingw g++ has 15-bit rand()

void gen( int n, vector <int> &a ) {
  a.resize(n);
  forn(i, n)
    a[i] = R();
}

const int maxN = 1e6;
Heap<unsigned, INT_MAX, maxN> h;

double start = 0;
#define timeStamp(...) fprintf(stderr, __VA_ARGS__, (clock() - start) / CLOCKS_PER_SEC), start = clock()

int main() {
  vector <int> x;
  int n = maxN;
  gen(n, x);
  timeStamp("input is generated: %.2f\n");

  h.build(n, x.begin());
  forn(i, n)
    h.extractMin();
  timeStamp("heap: %.2f\n");

  priority_queue<int, vector<int>, greater<int>> q;
  forn(i, n)
    q.push(x[i]);
  forn(i, n)
    q.pop();
  timeStamp("priority_queue: %.2f\n");

  multiset<int> s;
  forn(i, n)
    s.insert(x[i]);
  forn(i, n)
    s.erase(s.begin());
  timeStamp("set: %.2f\n");
}
