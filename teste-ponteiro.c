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
  	FILE *arqagenda = fopen("agenda.dat", "wb+");
	fwrite (&tamanho, sizeof(contato), 1, arqagenda);
	fwrite (lista, sizeof(contato), tamanho, arqagenda);
	fclose(arqagenda);
	
	arqagenda = fopen("agenda.dat", "wb+");
  if (arqagenda == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  	int result = fread (&tamanho, sizeof(contato), 1, arqagenda);
  	result = fread (lista, sizeof(contato), tamanho, arqagenda);

  	fclose(arqagenda);
  	int i;
  	for(i = 0; i < tamanho; i++){
  		printf("%d - %s\n",i, lista[i].nome);
	  }
  return 0;
}
