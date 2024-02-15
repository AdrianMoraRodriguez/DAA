#include "alu.h"

class LOAD : public ALU {
 public:
  LOAD(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~LOAD() {}
  void operate() const override;
  void isValid() const override;
};