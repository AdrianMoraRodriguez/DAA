/**
 * @file maquina_ram_soft.cc 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la máquina RAM con un modo depuración simplificado (muestra líneas ejecutadas) 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "maquina_ram_soft.h"

/**
 * @brief Constructor de la clase MaquinaRAMSoft
 * 
 * @param kFileName 
 * @param kInputFileName 
 * @param kOutputFile 
 * @param vector_length 
 * @param number_of_registers 
 */
MaquinaRAMSoft::MaquinaRAMSoft(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile,int vector_length ,int number_of_registers) {
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
void MaquinaRAMSoft::Run() {
  while (true) {
    try {
      alu_ = program_memory_.getInstruction(pc_);
      alu_->operate();
      lines_executed_++;
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