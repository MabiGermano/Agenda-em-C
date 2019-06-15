#include <stdio.h>
#include <stdlib.h>

struct Scontato{
  char nome[50];
  char numero[20];
}typedef contato;

int main(void) {
  contato *lista;
  int tamanho = 0;
  lista = (contato*)malloc((tamanho + 1) * sizeof(contato));
  int n = 23;
while(n != 0){
printf("Digite o nome: ");
  scanf("%s", lista[tamanho].nome);
  printf("Digite o numero: ");
  scanf("%s", lista[tamanho].numero);
  printf("...");
  scanf("%i", &n);

  tamanho++;

  lista = (contato*) realloc(lista, (tamanho + 1) * sizeof (contato));

}
  
printf("%i\n", tamanho);

for(int i = 0; i < tamanho+1; i++){
  printf("%s\n",lista[i].nome);
}





  return 0;
}
