#!/bin/bash

# Rango completo de enteros de 32 bits
INT_MIN=-2147483648
INT_MAX=2147483647

# Función para generar un número aleatorio en el rango INT_MIN a INT_MAX
generate_random_number() {
  echo $((RANDOM * RANDOM * RANDOM % (INT_MAX - INT_MIN + 1) + INT_MIN))
}

# Asociar una lista para mantener los números únicos
declare -A unique_numbers
count=0

# Generar 100 números únicos
while [ ${#unique_numbers[@]} -lt 100 ]; do
  num=$(generate_random_number)
  if [ -z "${unique_numbers[$num]}" ]; then
    unique_numbers[$num]=1
    count=$((count + 1))
  fi
done

# Convertir la lista de números en una cadena separada por espacios
ARG=$(echo ${!unique_numbers[@]})

# Exportar la variable ARG para que esté disponible en el entorno del shell actual
export ARG
