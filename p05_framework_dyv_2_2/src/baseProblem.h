#include <iostream>


#pragma once


/**
 * @brief Clase Problem
 * 
 * @tparam T 
 */
template <typename T>
class BaseProblem {
 public:
  BaseProblem(const T& kProblemGiven): problem_(kProblemGiven) {}
  BaseProblem() {}
  T getProblem() const { return problem_; }
  virtual void setProblem(const T& kProblemGiven) = 0;
  virtual void push_back(const int& kProblemGiven) = 0;
  virtual int operator[](const int& kIndex) const = 0;
  virtual int getIni() const {return 0;}
  virtual int getFin() const {return problem_.size();}
  virtual int getSearch() const { return -1; }
  virtual void setIni(const int& kIni) {}
  virtual void setFin(const int& kFin) {}
  virtual void setSearch(const int& kSearch) {}
  virtual void setOrigin(const int& kOrigin) {}
  virtual void setDestiny(const int& kDestiny) {}
  virtual void setAux(const int& kAux) {}
  virtual void setFib(const int& kFib) { fib_ = kFib;}
  virtual int getFib() const { return fib_; }
  virtual void setDiscs(const int& kDiscs) {}
  virtual int getDiscs() const { return -1; }
  virtual int getOrigin() const { return -1; }
  virtual int getDestiny() const { return -1; }
  virtual int getAux() const { return -1; }
  void printHanoi() {}
  int size() const { return problem_.size(); }
 protected:
  T problem_;
  int ini_;
  int fin_;
  int search_;
  int origin_;
  int destiny_;
  int aux_;
  int discs_;
  int fib_;
};