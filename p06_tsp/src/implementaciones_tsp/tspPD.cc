#include <chrono>
#include <math.h>
#include "tspPD.h"

void setup(std::vector<std::vector<double>>& dist, std::vector<std::vector<double>>& dp, int pos, int n) {
  for (int i = 0; i < n; i++) {
    if (i != pos) {
      dp[i][1 << pos | 1 << i] = dist[pos][i];
    }
  }
}

bool notIn(int subset, int pos) {
  return ((1 << pos) & subset) == 0;
}

void combinations(int r, int n, int set, int at, std::vector<int>& result) {
  if (r == 0) {
    result.push_back(set);
  } else {
    for (int i = at; i < n; i++) {
      set = set | (1 << i);
      combinations(r - 1, n, set, i + 1, result);
      set = set & ~(1 << i);
    }
  }
}
std::vector<int> combinations(int r, int n) {
  std::vector<int> result;
  combinations(r, n, 0, 0, result);
  return result;
}


void solve(std::vector<std::vector<double>>& dist, std::vector<std::vector<double>>& dp, int pos, int n, int max_time = 5) {
  auto start = std::chrono::high_resolution_clock::now();
  for (int r = 3; r <= n; r++) {
    for (auto subset: combinations(r, n)) {
      if (notIn(subset, pos)) {
        continue;
      }
      for (int next = 0; next < n; next++) {
        if (next == pos || notIn(subset, next)) {
          continue;
        }
        int subsetWithoutNext = subset ^ (1 << next);
        double minDist = INFINITY;
        for (int end = 0; end < n; end++) {
          if (end == pos || end == next || notIn(subset, end)) {
            continue;
          }
          minDist = std::min(minDist, dp[end][subsetWithoutNext] + dist[end][next]);
          dp[next][subset] = minDist;
        }
      }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - start);
    if (duration.count() > max_time) {
      if (duration.count() < 10) {
        continue;
      }
      return;
    }
  }
}

double findMinCost(std::vector<std::vector<double>>& dist, std::vector<std::vector<double>>& dp, int pos, int n) {
  int finalMask = (1 << n) - 1;
  double minCost = INFINITY;
  for (int i = 0; i < n; i++) {
    if (i == pos) {
      continue;
    }
    minCost = std::min(minCost, dp[i][finalMask] + dist[i][pos]);
  }
  return minCost;
}

std::vector<int> findOptimalPath(std::vector<std::vector<double>>& dist, std::vector<std::vector<double>>& dp, int pos, int n) {
  int lastIndex = pos;
  int state = (1 << n) - 1;
  std::vector<int> path(n);
  for (int i = n -1; i >= 1; i--) {
    int index = -1;
    for (int j = 0; j < n; j++) {
      if (j == pos || notIn(state, j)) {
        continue;
      }
      if (index == -1) {
        index = j;
      }
      double prevDist = dp[index][state] + dist[index][lastIndex];
      double newDist = dp[j][state] + dist[j][lastIndex];
      if (newDist < prevDist) {
        index = j;
      }
    }
    path[i] = index;
    state = state ^ (1 << index);
    lastIndex = index;
  }
  path[0] = pos;
  return path;
}

double TSPPD::resolver(std::string ciudad_de_inicio, int tiempo_maximo) {
  int n = ciudades_.size();
  std::vector<std::vector<double>> dp(n, std::vector<double>(1 << n, INFINITY));
  std::vector<std::vector<double>> dist(n, std::vector<double>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = ciudades_[i].getAristaConCiudad(ciudades_[j].getNombre()).getDistancia();
    }
  }
  setup(dist, dp, getPosicionCiudad(ciudad_de_inicio), n);
  solve(dist, dp, getPosicionCiudad(ciudad_de_inicio), n, tiempo_maximo);
  double distancia_minima = findMinCost(dist, dp, getPosicionCiudad(ciudad_de_inicio), n);
  //std::vector<int> path = findOptimalPath(dist, dp, getPosicionCiudad(ciudad_de_inicio), n);
  //for (int i = 0; i < n; i++) {
  //  mejorCamino_.push_back(ciudades_[path[i]]);
  //}
  return distancia_minima;

  /**int n = ciudades_.size();
  double dp [n][1 << n];
  for (int i = 0; i < n; i++) {
    dp[i][0] = ciudades_[i].getAristaConCiudad(ciudad_de_inicio).getDistancia();
  }
  for (int j = 1; j < (1 << n); j++) {
    for (int i = 0; i < n; i++) {
      if ((j & (1 << i)) != 0) {
        dp[i][j] = INFINITY;
        for (int k = 0; k < n; k++) {
          if (k != i && (j & (1 << k)) != 0) {
            dp[i][j] = std::min(dp[i][j], dp[k][j ^ (1 << i)] + ciudades_[k].getAristaConCiudad(ciudades_[i].getNombre()).getDistancia());
          }
        }
      }
    }
  }
  double distancia_minima = INFINITY;
  for (int i = 0; i < n; i++) {
    distancia_minima = std::min(distancia_minima, dp[i][(1 << n) - 1]);
  }
  return distancia_minima;*/
}

double TSPPD::resolverRecursivo(int pos, int bitmask, std::vector<std::vector<double>>& dp, std::vector<std::vector<double>>& dist, int tiempo_maximo) {
  auto start = std::chrono::high_resolution_clock::now();
  if (bitmask == (1 << pos) | 3) {
    return dist[1][pos];
  }
  if (dp[pos][bitmask] != INFINITY) {
    return dp[pos][bitmask];
  }
  double distancia_minima = INFINITY;

  for (int j = 1; j < ciudades_.size(); j++) {
    if ((bitmask & (1 << j)) && j != pos && j != 1) {
      distancia_minima = std::min(distancia_minima,
                                  resolverRecursivo(j, bitmask & (~(1 << pos)),dp, dist, tiempo_maximo) + dist[j][pos]);
    }
    return dp[pos][bitmask] = distancia_minima;
  }
  
}