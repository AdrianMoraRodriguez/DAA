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


MaquinaRAM::MaquinaRAM(const std::string& kFileName, int number_of_registers) {
  data_memory_ = DataMemory(number_of_registers);
  program_memory_ = ProgramMemory();
  program_memory_.loadProgram(kFileName);
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
  //Intentar convertir el string a un número, si no se puede, es que no es un número
  try {
    std::stoi(str);
    return true;
  } catch (std::invalid_argument& e) {
    return false;
  }
}

void MaquinaRAM::Run() {
  while (true) {
    std::string instruction = program_memory_.getInstruction(pc_);
    std::vector<std::string> instruction_parts = split(instruction, ' ');
    for (int i = 0; i < instruction_parts.size(); i++) {
      std::cout << "Parte " << i << ": " << instruction_parts[i] << std::endl;
    }
    std::string auxiliar;
    instruction_parts[0] = instructionToLowerCase(instruction_parts[0]);
    
    if (instruction_parts[1].find("*") != std::string::npos) {
      for (int i = 0; i < instruction_parts[1].size(); i++) {
        if (instruction_parts[1][i] != '*') {
          auxiliar += instruction_parts[1][i];
        }
      }
      instruction_parts[1] = auxiliar;
      data_memory_.SetNewDataReader("indirect");
      data_memory_.SetNewDataWritter("indirect");
    } else if (instruction_parts[1].find("=") != std::string::npos) {
      for (int i = 0; i < instruction_parts[1].size(); i++) {
        if (instruction_parts[1][i] != '=') {
          auxiliar += instruction_parts[1][i];
        }
      }
      instruction_parts[1] = auxiliar;
      if (instruction_parts[0] == "store") {
        std::cerr << "Error en la línea" << (pc_ + 1)  << ": No se puede almacenar en una dirección de memoria constante" << std::endl;
      } else if (instruction_parts[0] == "read") {
        std::cerr << "Error en la línea" << (pc_ + 1)  << ": No se puede cargar de una dirección de memoria constante" << std::endl;
      }
      data_memory_.SetNewDataWritter("constant");
      data_memory_.SetNewDataReader("constant");
    } else if (onlyNumbers(instruction_parts[1])) {
      data_memory_.SetNewDataReader("direct");
      data_memory_.SetNewDataWritter("direct");
    } else {
      std::cerr << "Error en la línea " << (pc_ + 1)  << ": tipo de operando no encontrado" << std::endl;
    }

    if (instruction_parts[0] == "load") {
      data_memory_.Load(std::stoi(instruction_parts[1]), std::stoi(instruction_parts[2]));
    } else if (instruction_parts[0] == "store") {
      data_memory_.Load(std::stoi(instruction_parts[1]), std::stoi(instruction_parts[2]));
    } else if (instruction_parts[0] == "read") {
      data_memory_.Read(std::stoi(instruction_parts[1])); //TODO Falta poner un parámetro que va a ser de la lectura de la entrada de datos
    } else if (instruction_parts[0] == "write") {
      std::cout << data_memory_.Read(std::stoi(instruction_parts[1])) << std::endl; //TODO De momento así luego volcar al fichero indicado como salida
    } else if (instruction_parts[0] == "add") {
      alu_ = new ADD();
      data_memory_.Load(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
    } else if (instruction_parts[0] == "sub") {
      alu_ = new SUB();
      data_memory_.Load(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
    } else if (instruction_parts[0] == "mul") {
      alu_ = new MUL();
      data_memory_.Load(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
    } else if (instruction_parts[0] == "div") {
      alu_ = new DIV();
      data_memory_.Load(0, alu_->operate(data_memory_.getr0(), data_memory_.Read(std::stoi(instruction_parts[1]))));
    } else if (instruction_parts[0] == "halt") {
      program_flow_ = new HALT();
      program_flow_->jump(pc_,0);
    } else if (instruction_parts[0] == "jzero") {
      program_flow_ = new JZERO();
      program_flow_->jump(pc_,program_memory_.getLablePosition(instruction_parts[1]), data_memory_.getr0());
    } else if (instruction_parts[0] == "jgtz") {
      program_flow_ = new JGTZ();
      program_flow_->jump(pc_,program_memory_.getLablePosition(instruction_parts[1]), data_memory_.getr0());
    } else if (instruction_parts[0] == "jump") {
      program_flow_ = new JUMP();
      program_flow_->jump(pc_,program_memory_.getLablePosition(instruction_parts[1]));
    } else {
      std::cerr << "Error en la línea " << (pc_ + 1)  << ": instrucción no encontrada" << std::endl;
      std::cerr << "Instrucción: " << instruction_parts[0] << std::endl;
    }
    pc_++;
    if (pc_ >= program_memory_.getProgramSize()) {
      break;
    }
  }
}