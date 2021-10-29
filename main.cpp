#include "headers.cpp"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int N, M, W;
  cin >> N >> M >> W;
  int x, y, pos_counter = 0, disk_counter = 0;
  vector<pillar_t> pillars;
  vector<disk_t> disks;
  while (pos_counter < N) {
    cin >> x;
    cin >> y;
    pillars.push_back({x, y});
    pos_counter++;
  }

  while (disk_counter < M) {
    cin >> x;
    cin >> y;
    disks.push_back({x, y, disk_counter});
    disk_counter++;
  }

  Graph g(M, N, W, pillars, disks);
  g.initialize_graph();
  g.print_graph();

  cout << "N: " << N << endl;
  cout << "W: " << W << endl;

  for (pillar_t p : pillars) {
    cout << "[" << p.x << "][" << p.y << "]\n";
  }
}
