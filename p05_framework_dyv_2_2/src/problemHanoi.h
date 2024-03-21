# include "baseProblem.h"


#pragma once

template <typename T>
class ProblemHanoi: public BaseProblem<T> {
 public:
  ProblemHanoi(int discs, char from, char to, char aux) {
    this->discs_ = discs;
    this->origin_ = from;
    this->destiny_ = to;
    this->aux_ = aux;
  }
  ProblemHanoi(int discs, int from, int to, int aux) {
    this->discs_ = discs;
    this->origin_ = from;
    this->destiny_ = to;
    this->aux_ = aux;
  }
  ProblemHanoi() {}
  void push_back(const int& kProblemGiven) override { this->problem_.push_back(kProblemGiven); }
  int operator[](const int& kIndex) const override { return this->problem_[kIndex]; } const
  int size() const { return this->problem_.size(); }
  void setProblem(const T& kProblemGiven) { this->problem_ = kProblemGiven; }
  void setAux(const int& kAux) override { this->aux_ = kAux; }
  void setDiscs(const int& kDiscs) override { this->discs_ = kDiscs; }
  void setOrigin(const int& kOrigin) override { this->origin_ = kOrigin; }
  void setDestiny(const int& kDestiny) override { this->destiny_ = kDestiny; }
  int getDiscs() const override { return this->discs_; }
  int getOrigin() const override { return this->origin_; }
  int getDestiny() const override { return this->destiny_; }
  int getAux() const override { return this->aux_; }
};
