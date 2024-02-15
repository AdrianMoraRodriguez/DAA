/**
 * @file data_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "data_memory.h"

void DataMemory::modifyMemory(int address, int value) {
  try {
    data_writter_->Write(address, value, registers_);
  } catch (const std::exception& e) {
    throw "Error en la escritura de datos";
  }
}

void DataMemory::load(int address) {
  registers_[0] = data_reader_->Read(address, registers_);
}

int DataMemory::Read(int address) {
  try {
    return data_reader_->Read(address, registers_);
  } catch (const std::exception& e) {
    throw "Error en la lectura de datos";
  }
}

void DataMemory::SetNewDataReader(std::string data_reader_type) {
  if (data_reader_type == "direct") {
    data_reader_ = new DirectDataReader();
  } else if (data_reader_type == "indirect") {
    data_reader_ = new IndirectDataReader();
  } else if (data_reader_type == "constant") {
    data_reader_ = new ContastDataReader();
  }
}

void DataMemory::SetNewDataWritter(std::string data_writter_type) {
  if (data_writter_type == "direct") {
    data_writter_ = new DirectDataWritter();
  } else if (data_writter_type == "indirect") {
    data_writter_ = new IndirectDataWritter();
  } else if (data_writter_type == "constant") {
    data_writter_ = new ContastDataWritter();
  }
}