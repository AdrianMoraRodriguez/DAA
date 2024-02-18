#include "maquina_ram_soft.h"

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
    }  
    pc_++;
    if (pc_ >= program_memory_.getProgramSize()) {
      break;
    }
  }
  std::cout << "Número de instrucciones ejecutadas: " << lines_executed_ << std::endl;
}