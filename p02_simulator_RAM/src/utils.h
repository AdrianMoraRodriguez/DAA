#include <string>
#include <vector>
#include <iostream>
#include <map>

#pragma once

/**
 * @brief Comprueba si una cadena de caracteres es un número
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool onlyNumbers(std::string str) {
  try {
    std::stoi(str);
    return true;
  } catch (std::invalid_argument& e) {
    return false;
  }
}

/**
 * @brief Elimina un caracter de una cadena de caracteres
 * 
 * @param str 
 * @param character 
 * @return std::string 
 */
std::string removeCharacters(std::string str, char character) {
  std::string auxiliar;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != character) {
      auxiliar += str[i];
    }
  }
  return auxiliar;
}

/**
 * @brief Get the Type Of Access object
 * 
 * @param operand 
 * @param kLabels 
 * @return std::string 
 */
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
    return "indiferent";
  }
  return "error";
}

/**
 * @brief Divide una cadena de caracteres en partes
 * 
 * @param str 
 * @param delimiter 
 * @return std::vector<std::string> 
 */
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
  for (int i = 0; i < parts.size(); i++) {
    if (parts[i] == "") {
      parts.erase(parts.begin() + i);
      i--;
    }
  }
  return parts;
}

/**
 * @brief Convierte una instrucción a minúsculas
 * 
 * @param instruction 
 * @return std::string 
 */
std::string instructionToLowerCase(std::string instruction) {
  std::string auxiliar;
  for (int i = 0; i < instruction.size(); i++) {
    auxiliar += tolower(instruction[i]);
  }
  return auxiliar;
}

/**
 * @brief Elimina los tabuladores y los retornos de carro de una cadena de caracteres
 * 
 * @param str 
 * @return std::string 
 */
std::string removeTabsAndReturns(std::string str) {
  std::string auxiliar;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '\t' && str[i] != '\r') {
      auxiliar += str[i];
    }
  }
  return auxiliar;
}

/**
 * @brief Prepara una instrucción para ser procesada
 * 
 * @param instruction 
 * @return std::vector<std::string> 
 */
std::vector<std::string> prepareCommand(std::string instruction) {
  instruction = removeTabsAndReturns(instruction);
  std::vector<std::string> instruction_parts = split(instruction, ' ');
  instruction_parts[0] = instructionToLowerCase(instruction_parts[0]);
  return instruction_parts;
}