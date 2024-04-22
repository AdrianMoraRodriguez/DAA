#include "problem.h"
#include "greedy.h"
#include "algorithm.h"
#include "grasp.h"
#include "grasp_swap_intra.h"
#include "grasp_swap_inter.h"
#include "grasp_insert_intra.h"
#include "grasp_insert_inter.h"
#include "grasp_insert_intra_VNS.h"
#include "grasp_swap_inter_VNS.h"
#include "grasp_swap_intra_VNS.h"
#include "gvns_mod.h"
#include "vnd.h"
#include "gvns.h"
#include <ctime>

int main() {
  std::cout << "Introduce el nombre del fichero con el problema: ";
  std::string filename;
  std::cin >> filename;
  Problem problem(filename);
  std::cout << "Modo de ejecución: GVNS (1) o elegir algoritmo (2), algoritmo greedy(3), mod(4): ";
  int mode;
  std::cin >> mode;
  if (mode == 2) {
    clock_t start, end;
    double cpu_time_used;
    Solution solution;
    Algorithm* algorithm;
    std::cout << "Introduce el número de iteraciones del Grasp: ";
    int tries;
    std::cin >> tries;
    std::cout << "Introduce el tamaño de la lista restringida de candidatos: ";
    int lrc_size;
    std::cin >> lrc_size;
    std::cout << "Introduce el algoritmo de búsqueda: SwapIntra (1) o SwapInter (2), InsertIntra (3), InsertInter (4): ";
    int search_algorithm;
    std::cin >> search_algorithm;
    switch(search_algorithm) {
     case 1:
      algorithm = new GraspSwapIntra(problem, lrc_size, tries);
      break;
     case 2:
      algorithm = new GraspSwapInter(problem, lrc_size, tries);
      break;
     case 3:
      algorithm = new GraspInsertIntra(problem, lrc_size, tries);
      break;
     case 4:
      algorithm = new GraspInsertInter(problem, lrc_size, tries);
      break;
     default:
      std::cout << "Opción no válida\n";
      return 1;
    }
    Solution best_solution;
    start = clock();
    solution = algorithm->run();
    Solution initial_solution = solution;
    solution = algorithm->localSearch(solution);
    best_solution = solution;
    algorithm->set_problem(problem);
    for (int i = 1; i < tries; i++) {
      solution = algorithm->run();
      solution = algorithm->localSearch(solution);
      if (solution.get_total_tct() < best_solution.get_total_tct()) {
        best_solution = solution;
      }
      algorithm->set_problem(problem);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Solución inicial:\n";
    initial_solution.print();
    std::cout << "Tiempo de ejecución: " << cpu_time_used * 1000 << "ms\n";

    std::cout << "Mejor solución encontrada:\n";
    best_solution.print();
    float initial_tct = initial_solution.get_total_tct();
    float final_tct = best_solution.get_total_tct();
    float improvement = (initial_tct - final_tct) / initial_tct * 100;
    std::cout << "Porcentaje de mejora: " << improvement << "%\n";
  } else if (mode == 1) {
    clock_t start, end;
    double cpu_time_used;
    std::cout << "Introduce el tamaño de la lista restringida de candidatos: ";
    int lrc_size;
    std::cin >> lrc_size;
    Algorithm* algorithm = new GraspInsertIntraVNS(problem, lrc_size, 10);
    std::vector<Algorithm*> algorithms_to_gnvs;
    algorithms_to_gnvs = {new GraspInsertInter(problem, lrc_size, 10), new GraspSwapIntraVNS(problem, lrc_size, 10), new GraspInsertIntraVNS(problem, lrc_size, 10), new GraspSwapInterVNS(problem, lrc_size, 10)};
    std::cout << "Introduce kmax: ";
    int kmax;
    std::cin >> kmax;
    std::cout << "Introduce max_iters: ";
    int max_iters;
    std::cin >> max_iters;
    GVNS gvns(problem, algorithms_to_gnvs, kmax, max_iters);
    start = clock();
    Solution solution = gvns.run();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Solución final:\n";
    solution.print();
    float initial_tct = gvns.get_initial_solution().get_total_tct();
    float final_tct = solution.get_total_tct();
    float improvement = (initial_tct - final_tct) / initial_tct * 100;
    std::cout << "Porcentaje de mejora: " << improvement << "%\n";
    std::cout << "Tiempo de ejecución: " << cpu_time_used << "s\n";
  } else if (mode == 3) {
    clock_t start, end;
    double cpu_time_used;
    Algorithm* algorithm = new Greedy(problem);
    start = clock();
    Solution solution = algorithm->run();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Tiempo de ejecución: " << cpu_time_used * 1000 << "ms\n";
    std::cout << "Solución greedy:\n";
    solution.print();
  } else if (mode == 4) { //MODIFICACION
    std::vector<Algorithm*> algorithms_to_gnvs;
    std::cout << "Introduce el tamaño de la lista restringida de candidatos: ";
    int lrc_size;
    std::cin >> lrc_size;
    algorithms_to_gnvs = {new GraspSwapInterVNS(problem, lrc_size, 10), new GraspInsertIntraVNS(problem, lrc_size, 10), new GraspSwapIntraVNS(problem, lrc_size, 10), new GraspInsertInter(problem, lrc_size, 10)};
    std::cout << "Introduce kmax: ";
    int kmax;
    std::cin >> kmax;
    std::cout << "Introduce max_iters: ";
    int max_iters;
    std::cin >> max_iters;
    GVNSMod gvns(problem, algorithms_to_gnvs, kmax, max_iters);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    Solution solution = gvns.run();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Solución final:\n";
    solution.print();
    std::cout << "Tiempo de ejecución: " << cpu_time_used << "s\n";
  } else {
    std::cout << "Opción no válida\n";
    return 1;
  }
}