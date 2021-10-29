#include <iostream>
#include <limits>
#include <vector>

using namespace std;

enum pos_t { nothing, disk, pillar };

struct pillar_t {
  int x, y;
};

bool operator>(pillar_t a, pillar_t b) { return a.x > b.x; }

struct disk_t {
  int R, C, i;
};

ostream &operator<<(ostream &out, const pillar_t &pil) {
  out << "X: " << pil.x << "\nY: " << pil.y;
  return out;
}

class Graph {
private:
  int M, W, N;
  vector<vector<pos_t>> graph;
  vector<pillar_t> pillars;
  vector<disk_t> disks;
  int LENGTH;

public:
  Graph(int M, int N, int W, vector<pillar_t> pillars, vector<disk_t> disks) {
    this->M = M;
    this->W = W;
    this->N = N;
    this->pillars = pillars;
    this->disks = disks;
  }
  pillar_t find_max_pillar() {
    pillar_t base = {0, 0};
    for (pillar_t p : pillars) {
      if (p > base) {
        base = p;
      }
    }
    return base;
  }

  disk_t find_max_disk() {
    disk_t base = {0, 0, -1};
    for (disk_t d : disks) {
      if (d.R > base.R) {
        base = d;
      }
    }
    return base;
  }
  void print_graph() {
    for (int i = W - 1; i >= 0; i--) {
      for (int j = 0; j < LENGTH; j++) {
        if (graph.at(i).at(j) == nothing) {
          cout << " . ";
        } else if (graph.at(i).at(j) == pillar) {
          cout << " * ";
        } else {
          cout << " ! ";
        }
      }
      cout << "\n";
    }
  }

  void initialize_graph() {
    LENGTH = find_max_disk().R + find_max_pillar().x;

    for (int i = 0; i < W; i++) {
      vector<pos_t> line;
      for (int j = 0; j < LENGTH; j++) {
        line.push_back(nothing);
      }
      graph.push_back(line);
    }

    for (pillar_t p : pillars) {
      graph.at(p.y).at(p.x) = pillar;
    }
  }

  int find_min_cost() {
    int cost = 0;
    for (pillar_t p : pillars) {
    }
  }
};
