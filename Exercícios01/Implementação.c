#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  int valor;
  
  struct No**filhos;
  int quantFilhos;/* data */
}No;

No* criarNo (int valor){
  No* novo = (No*) malloc (sizeof(No));
  novo-> valor = valor;
  novo -> filhos = NULL;
  novo -> quantFilhos = 0;

  return novo;
}

void inserirFilho (No *pai, No*filho){
  pai -> quantFilhos++;
  pai -> filhos = realloc(
    pai -> filhos,
    pai -> quantFilhos * sizeof(No*)
  );

  pai -> filhos [pai -> quantFilhos -1]= filho;
}

int contarNOs (No*raiz) {
  if (raiz==NULL)
  return 0;
  
  int total = 1;

  for (int i = 0; i<raiz -> quantFilhos; i++) {
    total+= contarNos(raiz->filhos[i]);
  
  }

  return total;
}

int altura (No*raiz){
  if (raiz == NULL)
    return 0;
int maior = 0;
for (int i = 0; i< raiz ->quantFilhos; i++){
  int h = altura (raiz -> filhos [i]);
  if (h > maior)
    maior = h;
}
return maior+1;
}
