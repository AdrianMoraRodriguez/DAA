#include "vnd.h"


Solution VND::run(Solution solution) {
  Solution best_solution = solution;
  for (int i = 0; i < algorithms_.size(); i++) {
    solution = algorithms_[i]->localSearch(solution);
    if (solution.get_total_tct() < best_solution.get_total_tct()) {
      best_solution = solution;
      if (i > 0) {
        i = 0;
      }
    }
  }
  return best_solution;
}