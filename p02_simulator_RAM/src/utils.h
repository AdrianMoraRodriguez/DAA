#include <string>
#include <vector>
#include <iostream>
#include <map>

#pragma once

bool onlyNumbers(std::string str) {
  try {
    std::stoi(str);
    return true;
  } catch (std::invalid_argument& e) {
    return false;
  }
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

std::string getTypeOfAccess(std::string& operand, const std::map<std::string, int>& kLabels) {
  if (operand.find("*") != std::string::npos) {
    operand = removeCharacters(operand, '*');
    return "indirect";
  } else if (operand.find("=") != std::string::npos) {
    operand = removeCharacters(operand, '=');
    return "constant";
  } else if (onlyNumbers(operand)) {
    return "direct";
  } else if (kLabels.at(operand) >= 0) {
    operand = std::to_string(kLabels.at(operand));
  }
  return "error";
}

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

std::string instructionToLowerCase(std::string instruction) {
  std::string auxiliar;
  for (int i = 0; i < instruction.size(); i++) {
    auxiliar += tolower(instruction[i]);
  }
  return auxiliar;
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