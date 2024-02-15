/**
 * @file maquina_ram.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la maquina RAM
 * @version 0.1
 * @date 2024-01-30
 * 
 */


#include "maquina_ram.h"

std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> parts;
  std::string part;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == delimiter) {
      parts.push_back(part);
      part = "";
    } else {
      part += str[i];
    }
  }
  parts.push_back(part);
  //quitar las posiciones que son únicamente espacios en blanco
  for (int i = 0; i < parts.size(); i++) {
    if (parts[i] == "") {
      parts.erase(parts.begin() + i);
      i--;
    }
  }
  return parts;
}


MaquinaRAM::MaquinaRAM(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile ,int number_of_registers) {
  data_memory_ = DataMemory(number_of_registers);
  program_memory_ = ProgramMemory();
  program_memory_.loadProgram(kFileName);
  input_tape_ = InputTape(kInputFileName);
  output_tape_.loadTape(kOutputFile);
  alu_ = new ADD();
  program_flow_ = new JUMP();
}


std::string instructionToLowerCase(std::string instruction) {
  std::string auxiliar;
  for (int i = 0; i < instruction.size(); i++) {
    auxiliar += tolower(instruction[i]);
  }
  return auxiliar;
}

bool onlyNumbers(std::string str) {
  try {
    std::stoi(str);
    return true;
  } catch (std::invalid_argument& e) {
    return false;
  }
}

std::string removeTabsAndReturns(std::string str) {
  std::string auxiliar;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '\t' && str[i] != '\r') {
      auxiliar += str[i];
    }
  }
  return auxiliar;
}

std::vector<std::string> prepareCommand(std::string instruction) {
  instruction = removeTabsAndReturns(instruction);
  std::vector<std::string> instruction_parts = split(instruction, ' ');
  instruction_parts[0] = instructionToLowerCase(instruction_parts[0]);
  return instruction_parts;
}

std::string removeCharacters(std::string str, char character) {
  std::string auxiliar;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != character) {
      auxiliar += str[i];
    }
  }
  return auxiliar;
}

void MaquinaRAM::changeMode(std::vector<std::string>& instruction_parts) {
  std::string auxiliar;
  try {
    if (instruction_parts.size() > 1) {
      if (instruction_parts[1].find("*") != std::string::npos) {
        instruction_parts[1] = removeCharacters(instruction_parts[1], '*');
        data_memory_.SetNewDataReader("indirect");
        data_memory_.SetNewDataWritter("indirect");
        program_memory_.checkOperation(instruction_parts, "indirect");
      } else if (instruction_parts[1].find("=") != std::string::npos) {
        instruction_parts[1] = removeCharacters(instruction_parts[1], '=');
        data_memory_.SetNewDataWritter("constant");
        data_memory_.SetNewDataReader("constant");
        program_memory_.checkOperation(instruction_parts, "constant");
      } else if (onlyNumbers(instruction_parts[1])) {
        data_memory_.SetNewDataReader("direct");
        data_memory_.SetNewDataWritter("direct");
        program_memory_.checkOperation(instruction_parts, "direct");
      } else {
        if (program_memory_.getLablePosition(instruction_parts[1]) == -1) {
          std::cerr << "Error en la línea " << (pc_ + 1)  << ": tipo de operando no encontrado" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
    }
  } catch (const char* e) {
    std::cerr << "Error en la línea " << (pc_ + 1)  << ": " << e << std::endl;
    exit(EXIT_FAILURE);
  }
}

void MaquinaRAM::Run() {
  while (true) {
    std::string instruction = program_memory_.getInstruction(pc_);
    std::vector<std::string> instruction_parts = prepareCommand(instruction);
    std::string auxiliar;
    changeMode(instruction_parts);
    try { //TODO Preguntar si es mejor un miembro privado que haga esto o dajarlo así
      if (instruction_parts[0] == "load") {
        data_memory_.load(std::stoi(instruction_parts[1]));
      } else if (instruction_parts[0] == "store") {
        data_memory_.modifyMemory(std::stoi(instruction_parts[1]), data_memory_.getr0());
      } else if (instruction_parts[0] == "read") {
        data_memory_.modifyMemory(std::stoi(instruction_parts[1]), std::stoi(input_tape_.getNextInput()));
      } else if (instruction_parts[0] == "write") {
        output_tape_.writeOutput(std::to_string(data_memory_.Read(std::stoi(instruction_parts[1]))));
      } else if (instruction_parts[0] == "add") {
        alu_ = new ADD();
        data_memory_.modifyMemory(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
      } else if (instruction_parts[0] == "sub") {
        alu_ = new SUB();
        data_memory_.modifyMemory(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
      } else if (instruction_parts[0] == "mul") {
        alu_ = new MUL();
        data_memory_.modifyMemory(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
      } else if (instruction_parts[0] == "div") {
        alu_ = new DIV();
        data_memory_.modifyMemory(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
      } else if (instruction_parts[0] == "jzero") {
        program_flow_ = new JZERO();
        program_flow_->jump(pc_,program_memory_.getLablePosition(instruction_parts[1]), data_memory_.getr0());
      } else if (instruction_parts[0] == "jgtz") {
        program_flow_ = new JGTZ();
        program_flow_->jump(pc_,program_memory_.getLablePosition(instruction_parts[1]), data_memory_.getr0());
      } else if (instruction_parts[0] == "jump") {
        program_flow_ = new JUMP();
        program_flow_->jump(pc_,program_memory_.getLablePosition(instruction_parts[1]));
      } else if (instruction_parts[0] == "halt") {
        program_flow_ = new HALT();
        program_flow_->jump(pc_,0);
      } else {
        std::cerr << "Error en la línea " << (pc_ + 1)  << ": instrucción no encontrada" << std::endl;
        std::cerr << "Instrucción: " << instruction_parts[0] << std::endl;
        output_tape_.writeOutput(std::to_string(data_memory_.Read(0)));
        exit(EXIT_FAILURE);
      }
    } catch (const char* e) {
      std::cerr << "Error en la línea " << (pc_ + 1)  << ": " << e << std::endl;
      exit(EXIT_FAILURE);
    }  
    pc_++;
    if (pc_ >= program_memory_.getProgramSize()) {
      break;
    }
  }
}