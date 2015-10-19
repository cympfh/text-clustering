#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;

int main(int argc, char*argv[]) {

  string c_path = "";
  string i_path = "";
  string deliminator = "";

  {
    int i = 1;
    string arg;
    for (; i< argc; ++i) {
      arg = argv[i];
      if (arg == "-h" or arg == "--help") {
usage:
        fprintf(stderr, "Usage: split2clusters.exe -c <output-of-bayon (0-origin)> -i <original-input> [-d <deliminator>]\n");
        exit(0);
      }
      if (arg == "-c") {
        c_path = argv[i+1];
        ++i;
      }
      else if (arg == "-i") {
        i_path = argv[i+1];
        ++i;
      }
      else if (arg == "-d") {
        deliminator = argv[i+1];
        ++i;
      }
      else {
        goto usage;
      }
    }
    if (c_path == "" or i_path == "") goto usage;
  }

  vector<vector<int>> clusters;
  vector<string> lines;

  {
    ifstream sin(c_path);
    string line;
    while (getline(sin, line)) {
      int i = clusters.size();
      clusters.push_back(vector<int>());
      stringstream ss(line);
      int x; ss >> x; // remove first number (cluster-id)
      while (ss >> x) clusters[i].push_back(x);
    }
  }

  {
    ifstream sin(i_path);
    string line;
    while (getline(sin, line)) lines.push_back(line);
  }
  const int n = lines.size();
  const char* d = deliminator.c_str();

  rep (i, clusters.size()) {
    rep (j, clusters[i].size()) {
      assert((n > clusters[i][j]) && "cluster line number not contained in input file");
      printf("%s\n", lines[clusters[i][j]].c_str());
    }
    printf("%s\n", d);
  }
  
}
