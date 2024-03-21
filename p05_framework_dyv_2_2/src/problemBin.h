#include "baseProblem.h"

#pragma once

template <typename T>
class ProblemBin : public BaseProblem<T> {
 public:
  ProblemBin(const T& kProblemGiven, int search, int ini, int fin): BaseProblem<T>(kProblemGiven) {
    this->ini_ = ini;
    this->fin_ = fin;
    this->search_ = search;
  }
  ProblemBin() {}
  void push_back(const int& kProblemGiven) { this->problem_.push_back(kProblemGiven); }
  int operator[](const int& kIndex) const { return this->problem_[kIndex]; } const
  int size() const { return this->problem_.size(); }
  void setProblem(const T& kProblemGiven) { this->problem_ = kProblemGiven; }
  void setIni(const int& kIni) override { this->ini_ = kIni; }
  void setFin(const int& kFin) override { this->fin_ = kFin; }
  void setSearch(const int& kSearch) override { this->search_ = kSearch; }
  int getSearch() const override { return this->search_; }
  int getIni() const override { return this->ini_; }
  int getFin() const override { return this->fin_; }
};