/**
 * @file maquina_ram_hard.cc 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la máquina RAM con un modo de depuración más avanzado 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "maquina_ram_hard.h"

/**
 * @brief Constructo de la clase MaquinaRAMHard
 * 
 * @param kFileName 
 * @param kInputFileName 
 * @param kOutputFile 
 * @param vector_length 
 * @param number_of_registers 
 */
MaquinaRAMHard::MaquinaRAMHard(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile,int vector_length ,int number_of_registers) {
  data_memory_ = DataMemory(number_of_registers, vector_length);
  program_memory_ = ProgramMemory();
  input_tape_ = InputTape();
  input_tape_.loadTape(kInputFileName);
  output_tape_.loadTape(kOutputFile);
  program_memory_.loadProgram(kFileName, &pc_, &data_memory_, &output_tape_, &input_tape_, &lines_executed_);
  input_file_ = kInputFileName;
  output_file_ = kOutputFile;
}

/**
 * @brief Método que ejecuta la máquina RAM
 * 
 */
void MaquinaRAMHard::Run() {
  std::cout << "Quieres depurar por pantalla? (s/n): ";
  std::string answer;
  std::cin >> answer;
  std::string debug_file = "debug_info.txt";
  while (true) {
    try {
      alu_ = program_memory_.getInstruction(pc_);
      if (alu_->getOperationName() == "HALT" && answer == "s") {
        printState();
      } else if (alu_->getOperationName() == "HALT" && answer == "n") {
        printState(debug_file);
      }
      alu_->operate();
      lines_executed_++;
      if (answer == "s") {
        std::string myString = "";
        do {
          std::cout << "Enter para continuar" << std::endl;
          std::getline(std::cin, myString);
        } while (myString.length() != 0);
        printState();
      } else if (answer == "n") {
        printState(debug_file);
      }
    } catch (const char* e) {
      std::cerr << "Error en la línea " << (pc_ + 1)  << ": " << e << std::endl;
      std::cout << "Número de instrucciones ejecutadas: " << lines_executed_ << std::endl;
      exit(EXIT_FAILURE);
    } catch (const std::string e) {
      std::cerr << "Error en la línea " << (pc_ + 1) << ": " << e << std::endl;
      exit(EXIT_FAILURE);
    } catch (...) {
      std::cerr << "Error desconocido en la línea " << (pc_ + 1) << std::endl;
      std::cout << "Número de instrucciones ejecutadas: " << lines_executed_ << std::endl;
      exit(EXIT_FAILURE);
    }
    pc_++;
    if (pc_ >= program_memory_.getProgramSize()) {
      break;
    }
  }
  std::cout << "Número de instrucciones ejecutadas: " << lines_executed_ << std::endl;
}