#!/bin/bash

# Verificar que se proporciono el nombre del archivo
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

#obtener la cadena de caracteres
cadena="$1"

#Crear los tres archivos
touch "${cadena}.cc"  "${cadena}.h"