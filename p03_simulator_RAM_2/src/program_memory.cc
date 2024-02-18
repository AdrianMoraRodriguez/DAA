/**
 * @file program_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de programa
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "program_memory.h"
#include "utils.h"

ALU* generateInstruction(std::vector<std::string> kOperation,int* pc, DataMemory* data_memory, OutputTape* output_tape, InputTape* input_tape, const std::string& kTypeOfAccess, const std::string& kTypeOfVectorAccess,int* lines_executed ) {
  std::string instruction = instructionToLowerCase(kOperation[0]);
  int operand = 0;
  int position_in_vector = 0;
  if (kOperation.size() > 1) {
    operand = std::stoi(kOperation[1]);
  }
  if (kOperation.size() > 2) {
    position_in_vector = std::stoi(kOperation[2]);
  }
  if (instruction == "add") {
    ALU* instruction_made = new ADD(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "sub") {
    ALU* instruction_made = new SUB(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "mul") {
    ALU* instruction_made = new MUL(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "div") {
    ALU* instruction_made = new DIV(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "jump") {
    ALU* instruction_made = new JUMP(data_memory);
    instruction_made->loadPC(pc);
    instruction_made->loadNewPosition(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "jgtz") {
    ALU* instruction_made = new JGTZ(data_memory);
    instruction_made->loadPC(pc);
    instruction_made->loadNewPosition(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "jzero") {
    ALU* instruction_made = new JZERO(data_memory);
    instruction_made->loadPC(pc);
    instruction_made->loadNewPosition(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "store") {
    ALU* instruction_made = new STORE(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "load") {
    ALU* instruction_made = new LOAD(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "read") {
    ALU* instruction_made = new READ(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadInputTape(input_tape);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "write") {
    ALU* instruction_made = new WRITE(data_memory);
    instruction_made->loadOperand(operand);
    instruction_made->loadPositionInVector(position_in_vector);
    instruction_made->loadDataReader(kTypeOfAccess);
    instruction_made->loadOutputTape(output_tape);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
  if (instruction == "halt") {
    ALU* instruction_made = new HALT(data_memory);
    instruction_made->loadOperationName(instruction);
    instruction_made->loadLinesExecuted(lines_executed);
    instruction_made->loadTypeOfVectorAccess(kTypeOfVectorAccess);
    return instruction_made;
  }
   ALU* instruction_made = new UNKNOW(data_memory);
   instruction_made->loadOperationName(instruction);
   return instruction_made;
}

std::string preProcessInstruction(std::string instruction) {
  std::string auxiliar;
  for (int i = 0; i < instruction.size(); i++) {
    if (instruction[i] == ' ' || instruction[i] == '\r' || instruction[i] == '\n' || instruction[i] =='\t') continue;
    auxiliar += instruction[i];
  }
  return auxiliar;
}
/**
 * @brief Load the program from a file.
 * 
 * @param kFilename 
 */
void ProgramMemory::loadProgram(const std::string& kFilename, int* pc, DataMemory* data_memory, OutputTape* output_tape, InputTape* input_tape, int* lines_executed) {
  std::ifstream file(kFilename);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el fichero " << kFilename << std::endl;
    exit(1);
  }
  std::string line;
  while (std::getline(file, line)) {
    std::string aux = preProcessInstruction(line);
    if (aux.size() == 0) continue; 
    if (aux[0] == '#') continue;
    if (aux[0] == '\r') continue;
    if (aux[0] == '\n') continue;
    if (aux == "\t") continue;
    program_.push_back(line);
  }
  file.close();
  //si encontramos una palabra al principio de la línea con dos puntos, es una etiqueta, por lo que se guarda
  for (int i = 0; i < program_.size(); i++) {
    //Primero, hacemos un split de la línea con separador " "
    std::string delimiter = ":";
    std::string label = program_[i].substr(0, program_[i].find(delimiter));
    if (label.size() == program_[i].size()) continue;
    createLabel(removeTabsAndReturns(label), i);
    //quitar la etiqueta de la línea y dejar la instrucción como pirmiera palabra
    program_[i] = program_[i].substr(program_[i].find(delimiter) + 1, program_[i].size());
  }
  makeInstructions(pc, data_memory, output_tape, input_tape, lines_executed);
}

void ProgramMemory::makeInstructions(int* pc, DataMemory* data_memory, OutputTape* output_tape, InputTape* input_tape, int* lines_executed) {
  for (int i = 0; i < program_.size(); i++) {
    std::vector<std::string> instruction_parts = prepareCommand(program_[i]);
    std::string type_of_access = "";
    std::string type_of_vector_access = "direct";
    if (instruction_parts.size() > 1) {
      type_of_access = getTypeOfAccess(instruction_parts[1], labels_);
    }
    if (instruction_parts.size() > 2) {
      type_of_vector_access = getTypeOfAccess(instruction_parts[2], labels_);
    }
    try {
    ALU* instruction = generateInstruction(instruction_parts, pc, data_memory, output_tape, input_tape, type_of_access, type_of_vector_access, lines_executed);
    instructions_.push_back(instruction);
    } catch (const char* e) {
      std::cerr << "Error en la línea " << i << ": " << e << std::endl;
      exit(1);
    }
  }
}

/**
 * @brief Create a label.
 * 
 * @param kLabel 
 * @param line_number 
 */
void ProgramMemory::createLabel(const std::string& kLabel, int line_number) {
  labels_[kLabel] = line_number;
}


void ProgramMemory::checkOperation(const std::vector<std::string>& kOperation, const std::string& type_of_access) {
  if (kOperation[0] == "store" && type_of_access == "constant") {
    throw "No se puede almacenar en una dirección de memoria constante";
  } else if (kOperation[0] == "read" && type_of_access == "constant") {
    throw "No se puede cargar a una dirección de memoria constante";
  } else if (kOperation[0] == "jump" && type_of_access == "constant") {
    throw "No se puede saltar a una dirección de memoria constante";
  } else if (kOperation[0] == "write" && kOperation[1] == "0" && type_of_access == "direct") {
    throw "No se puede escribir desde la dirección 0";
  }
}