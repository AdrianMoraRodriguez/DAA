/**
 * @file maquina_ram.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la maquina RAM
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "maquina_ram.h"

/**
 * @brief Construye una Maquina RAM
 * 
 * @param kFileName 
 * @param kInputFileName 
 * @param kOutputFile 
 * @param number_of_registers 
 */
MaquinaRAM::MaquinaRAM(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile ,int number_of_registers) {
  data_memory_ = DataMemory(number_of_registers);
  program_memory_ = ProgramMemory();
  input_tape_ = InputTape();
  input_tape_.loadTape(kInputFileName);
  output_tape_.loadTape(kOutputFile);
  program_memory_.loadProgram(kFileName, &pc_, &data_memory_, &output_tape_, &input_tape_);
  input_file_ = kInputFileName;
  output_file_ = kOutputFile;
}

/**
 * @brief Ejecuta la maquina RAM
 * 
 */
void MaquinaRAM::Run() {
  while (true) {
    try {
      alu_ = program_memory_.getInstruction(pc_);
      alu_->operate();
    } catch (const char* e) {
      std::cerr << "Error en la línea " << (pc_ + 1)  << ": " << e << std::endl;
      exit(EXIT_FAILURE);
    }  catch (...) {
      std::cerr << "Error desconocido en la línea " << (pc_ + 1) << std::endl;
      exit(EXIT_FAILURE);
    }
    pc_++;
    if (pc_ >= program_memory_.getProgramSize()) {
      break;
    }
  }
}