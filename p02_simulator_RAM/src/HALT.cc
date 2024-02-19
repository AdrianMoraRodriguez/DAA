/**
 * @file HALT.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación Halt
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "HALT.h"

/**
 * @brief Operación de halt
 * 
 */
void HALT::operate() const {
  exit(EXIT_SUCCESS);
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void HALT::isValid() const {
  //everything is valid in the halt
}