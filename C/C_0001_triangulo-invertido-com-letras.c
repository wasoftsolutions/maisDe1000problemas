/*
Objetivo: receber uma palavra do usuário e imprimir na tela um triângulo invertido construído com sequências de letras da palavra
          intercalando espaços entre as letras. Cada linha do triângulo deve terminar com uma letra e não com um espaço

Entrada: string dada pelo usuário

Saída: triângulo invertido de letras intercaladas com espaços

Algoritmo:
  1) criar uma nova palavra análoga à palavra dada, porém, com um espaço entre cada letra
  2) imprimir na tela a palavra espaçada (obtida na etapa 1)
  3) retirar a ultima letra e o último espaço da palavra espaçada
  4) imprimir na tela a versão reduzida da palavra espaçada (obtida na etapa 2)
  5) repetir as etapas 3 e 4 até que só reste a primeira letra da palavra espaçada

Estratégia:
  1) usar um ponteiro e alocação de memória para guardar a palavra com espaços
  2) usar o caractere de terminação '\0' para reduzir a palavra com espaços
  3) usar um loop para imprimir na tela (espaços iniciais) + (palavra espaçada reduzida)
*/

//bibliotecas de C
#include <stdio.h>
#include <stdlib.h>

//cabeçalho das funções auxiliares
int tamanho_da_palavra(char *palavra);
void criar_palavra_com_espacos(char *palavra, char *palavra_espacada, int t);
void reduzir_palavra_com_epacos(char *palavra_espacada, int t, int n);
void imprimir_espacos(int n);

//função principal
int main(){
  char palavra[100];                                        //definir a string que vai guardar a palavra com no máximo 100 caracteres
  int n;                                                    //interio que vai guardar o tamanho da palavra

  scanf("%s", palavra);                                     //ler entrada do usuário
  n = tamanho_da_palavra(palavra);                          //contar número de letras da palavra

  char *palavra_espacada;                                   //definir ponteiro que vai marcar o início da palavra com espaços
  int t = 2 * n;                                            //tamanho da palavra com espaços, incluindo o caractere de terminação '\0'

  palavra_espacada = calloc(t, sizeof(char));               //alocar espaço na memória para guardar a palavra com espaços
  criar_palavra_com_espacos(palavra, palavra_espacada, t);  //criar a palavra com espaços

  for (int i = 0; i < n; i++) {                             //loop para eliminar letra por letra (e espaços) da palavra espaçada e incluir novos espaços iniciais
    reduzir_palavra_com_epacos(palavra_espacada, t, i);     //eliminar ultima letra e espaço associado
    imprimir_espacos(i);                                    //imprimir espaços iniciais
    printf("%s\n", palavra_espacada);                       //imprimir a palavra reduzida
  }

  return 0;
}

//função que calcula o número de letras da palavra
int tamanho_da_palavra(char *palavra){
  int i = 1, n = 0;                                         //definir i como condição do loop e n guardar o número de letras da palavra
  
  while(i)                                                  //loop para contar o número de letras da palavra
    if (palavra[n++] == '\0')                               //verificar se o n-ésimo elemento da palavra é o caractere de terminação '\0'
      i = 0;                                                //se o n-ésimo elemento for igual a '\0' entao i = 0 e o loop é terminado

  return n - 1;                                             //descontar o último incremento feito por n++ dentro do loop
}

//função que reescreve a palavra incluindo espaços entre as letras
void criar_palavra_com_espacos(char *palavra, char *palavra_espacada, int t){
  for (int i = 0; i < t; i++) {                             //loop para escrever cada elemento da palavra com espaços
    if (i % 2 & i != 0)                                     //se i for diferente de 0 e for par, então:
      *palavra_espacada++ = ' ';                            //  o valor do endereço atual de palavra_espacada é preenchido com um espaço e o endereço é incrementado
    else {                                                  //se i for impar, então:
      *palavra_espacada++ = *palavra++;                     //  o valor do endereço atual de palavra_espacada é preenchido com a letra atual de palavra
    }                                                       //  e o endereço é incrementado de ambos, palavra_espaca e palavra, são incrementados
  }

  *palavra_espacada = '\0';                                 //incluir o caractere de terminação '\0' no último endereço de palavra_espacada
}

//função que reescreve a palavra espaçada eliminando a última letra e o espaço anterior a letra
void reduzir_palavra_com_epacos(char *palavra_espacada, int t, int n){
    *(palavra_espacada + (t - 2 * n)) = '\0';               //colocar o caractere de terminação '\0' duas posições abaixo da atual
}                                                           // isso reduz um espaço e uma letra de palavra_espacada

//função que imprime n espaços
void imprimir_espacos(int n){
  for (int i = 0; i < n; i++)                               //loop para criar n espaços
    printf("%c", ' ');                                      //imprimir espaço
}