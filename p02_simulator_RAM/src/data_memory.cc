#include "data_memory.h"

void DataMemory::Load(int address, int value) {
  registers_[address] = value;
}

int DataMemory::ReadDirect(int address) const {
  return registers_[address];
}

int DataMemory::ReadIndirect(int address) const {
  return registers_[ReadDirect(address)];
}