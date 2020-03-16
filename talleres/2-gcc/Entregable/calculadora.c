#include <stdio.h>
#include <mathOwnLib.h>

int main(){
  printf("Prueba del metodo sumar\n");
  printf("Operandos %.2f y %.2f, resultado %.2f\n\n", 12.0, 2.0, sumar(12.0, 2.0));

  printf("Prueba del metodo restar\n");
  printf("Operandos %.2f y %.2f, resultado %.2f\n\n", 12.0, 2.0, restar(12.0, 2.0));

  printf("Prueba del metodo multiplicar\n");
  printf("Operandos %.2f y %.2f, resultado %.2f\n\n", 12.0, 2.0, multiplicar(12.0, 2.0));

  printf("Prueba del metodo dividir\n");
  printf("Operandos %.2f y %.2f, resultado %.2f\n\n", 12.0, 2.0, dividir(12.0, 2.0));

  printf("Prueba del metodo raizCuadrada\n");
  printf("Operandos %.2f, resultado %.2f\n", 12.0, raizCuadrada(12.0));
}