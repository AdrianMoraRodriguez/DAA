/**
 * @file HanoiTowers.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase HanoiTowers
 * @version 0.1
 * @date 2024-03-04
 * 
 */

#include "DivideAndConquer.h"

#pragma once
template <class P, class S>
class HanoiTowers : public DivideAndConquer<P, S> {
 public:
  HanoiTowers(int how_many = 2) : DivideAndConquer<P, S>(how_many) {}
  bool isSmall(const Problem<P>& problem, int length, int search) override {
    return problem[0] <= 1;
  }

  virtual std::vector<Problem<P>> divide(const Problem<P>& problem, int length, int search, int how_many) override {
    // Dividimos el problema en dos subproblemas, donde movemos el disco superior a un poste auxiliar
    std::vector<Problem<P>> subproblems;
    Problem<P> subproblem;
    subproblem.setProblem({problem[0] - 1, problem[1], problem[2], problem[3]});
    subproblems.push_back(subproblem);
    subproblem.setProblem({problem[0] - 1, problem[2], problem[3], problem[1]});
    subproblems.push_back(subproblem);
    return subproblems;
  }

  virtual Solution<S> makeSolution(const Problem<P>& problem, int search) override {
    // Movemos el disco único a la posición deseada
    Solution<S> solution;
    solution.addMove(problem[0], problem[1], problem[3]);
    return solution;
  }

  virtual Solution<S> combine(const std::vector<Solution<S>>& solutions) override {
    // Combinamos las soluciones de los subproblemas
    Solution<S> solution;
    std::vector<std::vector<int>> actualSolution;
    for (int i = 0; i < solutions.size(); i++) {
      actualSolution = solutions[i].getSolution();
      for (int j = 0; j < actualSolution.size(); j++) {
        solution.addMove(actualSolution[j][0], actualSolution[j][1], actualSolution[j][2]);
      }
    }
    return solution;
  }

  std::string get_recursivity() override {
    return "T(n) = 2T(n/2) + 1";
  }
  std::string get_factor() override {
    return "2";
  }
  virtual std::string get_combine_complex() override {
    return "O(1)";
  }

 private:
  
};