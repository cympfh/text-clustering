#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;

int main() {
  map<string, int> dict;
  string line;
  int ln = 0;
  while (getline(cin, line)) {
    stringstream ss(line);
    string w;
    map<int, int> fs;
    while (ss >> w) {
      if (not dict.count(w)) {
        int id = dict.size() + 1;
        dict[w] = id;
      }
      fs[dict[w]]++;
    }
    printf("%d", ln);
    for (auto&f: fs) {
      printf("\t%d\t%d", f.first, f.second);
    }
    printf("\n");
    ++ln;
  }
}
