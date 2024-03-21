#include "DivideAndConquer.h"

template <class P, class S>
class Fibonacci : public DivideAndConquer<P, S> {
  bool isSmall(const BaseProblem<P>* problem, int length) override {
    return problem->getFib() <= 1;
  }

  std::vector<BaseProblem<P>*> divide(const BaseProblem<P>* problem, int length, int how_many) override {
    std::vector<BaseProblem<P>*> problems;
    BaseProblem<P>* problem1 = new Problem<P>();
    BaseProblem<P>* problem2 = new Problem<P>();
    problem1->setFib(problem->getFib() - 1);
    problem2->setFib(problem->getFib() - 2);
    problems.push_back(problem1);
    problems.push_back(problem2);
    return problems;
  }

  Solution<S>* combine(const std::vector<Solution<S>*>& solutions, const BaseProblem<P>* problem) override {
    Solution<S>* combined = new Solution<S>();
    int sum = 0;
    for (int i = 0; i < solutions.size(); i++) {
      sum += solutions[i]->getSolution()[0];
    }
    combined->setSolution({sum});
    return combined;
  }

  Solution<S>* makeSolution(const BaseProblem<P>* problem, int length) override {
    Solution<S>* solution = new Solution<S>();
    solution->setSolution({problem->getFib()});
    return solution;
  }

  std::string get_recursivity() override {
    return "2";
  }

  std::string get_factor() override {
    return "-1";
  }

  std::string get_combine_complex() override {
    return "1";
  }
};