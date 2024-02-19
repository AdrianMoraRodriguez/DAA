/**
 * @file maquina.cc 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase máquina 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include <fstream>
#include "maquina.h"

/**
 * @brief Constructor de la clase máquina
 * 
 * @param kFileName 
 * @param kInputFileName 
 * @param kOutputFile 
 * @param vector_length 
 * @param number_of_registers 
 */
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

/**
 * @brief Método que ejecuta la máquina
 * 
 * @param kFileName 
 */
void Maquina::printState(const std::string& kFileName) {
  if (kFileName != "No file") {
    std::ofstream file;
    file.open(kFileName, std::ios::app);
    file << "PC: " << (pc_ + 1) << std::endl;
    file << "--------------------------------" << std::endl;
    file << "Instrucción ejecutada: " << alu_->printInstruction() << std::endl;
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
  } else {
    std::cout << "PC: " << (pc_ + 1) << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Instrucción ejecutada: " << alu_->printInstruction() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Memoria de datos: " << std::endl;
    std::cout << data_memory_.printMemory();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Cinta de entrada: " << std::endl;
    std::cout << input_tape_.printTape() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Cinta de salida: " << std::endl;
    std::cout << output_tape_.printTape();
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::endl;
  }
}