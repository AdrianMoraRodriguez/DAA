#include <fstream>
#include "maquina.h"

Maquina::Maquina(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile, int vector_length, int number_of_registers) {
  data_memory_ = DataMemory(number_of_registers, vector_length);
  program_memory_ = ProgramMemory();
  input_tape_ = InputTape();
  input_tape_.loadTape(kInputFileName);
  output_tape_.loadTape(kOutputFile);
  program_memory_.loadProgram(kFileName, &pc_, &data_memory_, &output_tape_, &input_tape_);
  input_file_ = kInputFileName;
  output_file_ = kOutputFile;
}

void Maquina::printState() {
  //crear un fichero de salida con el estado de la máquina, siempre hacer que lo nuevo se escriba al final
  std::ofstream file;
  file.open("debug_info.txt", std::ios::app);
  file << "PC: " << pc_ << std::endl;
  file << "--------------------------------" << std::endl;
  file << "Instrucción ejecutada:" << alu_->getOperationName() << std::endl;
  file << "--------------------------------" << std::endl;
  file << "Memoria de datos: " << std::endl;
  file << data_memory_.printMemory();
  file << "--------------------------------" << std::endl;
  file << "Cinta de entrada: " << std::endl;
  file << input_tape_.printTape() << std::endl;
  file << "--------------------------------" << std::endl;
  file << "Cinta de salida: " << std::endl;
  file << output_tape_.printTape();
  file << "--------------------------------" << std::endl;
  file << std::endl;
}