#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#define MAXIMO 1000
struct Scontato{
	char nome[50];
	char numero[20];
	char email[50];
	bool disponivel;
}typedef contato;

void novoContato(int numero, contato registros[], int tamanho);
int excluirContato(void);
void editarContato(contato registros[]);
void listarContatos(contato registros[], int tamanho);
int sair(contato registros[], int tamanho);
void inicio(contato registros[], int tamanho);
int menu(contato registros[], int tamanho);
void tornarDisponiveis(contato registros[], int tamanho);
int verificarItemVazio(contato registros[], int tamanho);
void mensagem(char mensagem[], int tamanho);
int tamanhoString(char mensagem[]);
void buscaString(contato registros[], char nomeBusca[], int tamanho);
int main(){
    setlocale(LC_ALL, "Portuguese");
	
	contato *registros;
	int tamanho = 0;
	registros = (contato*)malloc((tamanho + 1) * sizeof(contato));

    inicio(registros, tamanho);
    return 0;
}
void inicio(contato registros[], int tamanho){

    int opcao;
    printf(" *********  *********  *********  ***      **  ********   *********\n");
    printf(" *********  *********  *********  ****     **  *********  *********\n");
    printf(" **     **  **         **         ** **    **  **     **  **     **\n");
    printf(" *********  **   ****  *******    **  **   **  **     **  *********\n");
    printf(" *********  **   ****  *******    **   **  **  **     **  *********\n");
    printf(" **     **  **     **  **         **    ** **  **     **  **     **\n");
    printf(" **     **  *********  *********  **     ****  *********  **     **\n");
    printf(" **     **  *********  *********  **      ***  ********   **     **\n\n");
    

    printf("Olá, sou sua agenda. Escolha uma dessas opções para continuar(ou não haha): \n\n");
    printf("1 - Menu / 2 - Encerrar\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);


    switch(opcao){
        case 1:
            system("cls");
            menu(registros, tamanho);
            break;
        case 2:
            printf("\nAté mais!!\n");
            exit(0);
        default:
             system("cls");
             printf("-- A OPÇÃO INSERIDA É INVÁLIDA, TENTE NOVAMENTE --\n\n");
             inicio(registros, tamanho);
    }

}
int menu(contato registros[], int tamanho){

    int opcao;
    
	char mensagemMenu[] = "****    Menu    ****";
    int tamanhoMensagem = tamanhoString(mensagemMenu);
	printf("\n");
	mensagem(mensagemMenu, tamanhoMensagem);
	printf("\n");
    printf("1 - Novo Contato\n");
    printf("2 - Excluir Contato\n");
    printf("3 - Editar Contato\n");
    printf("4 - Listar Contatos\n");
    printf("5 - Sair\n");
    printf("\nDigite a opção desejada: ");
    scanf("%i", &opcao);

    system("cls");

    switch(opcao){
        case 1:
            novoContato(opcao, registros, tamanho);
            break;
        case 2:
            excluirContato();
            break;
        case 3:
            editarContato(registros);
            break;
        case 4:
            listarContatos(registros, tamanho);
            break;
        case 5:
            sair(registros, tamanho);
            break;
        default:
            printf("-- A OPÇÃO INSERIDA É INVÁLIDA, TENTE NOVAMENTE --\n");
            menu(registros, tamanho);
            break;
    }


}

void novoContato(int numero, contato registros[], int tamanho){
	char mensagemSucesso[] = " Contato Incluído com Sucesso!";
	char mensagemInicio[] = "**********   Incluir Contato   **********";
	int tamanhoMensagem = tamanhoString(mensagemInicio);
	mensagem(mensagemInicio, tamanhoMensagem);	 
	
	
	printf("Digite o Nome do contato: ");
	scanf("%s", registros[tamanho].nome);
	
	printf("Digite o Número do contato: ");
	scanf("%s", registros[tamanho].numero);
	
	printf("Digite o email do contato: ");
	scanf("%s", registros[tamanho].email);
	
    system("cls");

    tamanhoMensagem = tamanhoString(mensagemSucesso);
	mensagem(mensagemSucesso, tamanhoMensagem);
	tamanho++;
	registros = (contato*) realloc(registros, (tamanho + 1) * sizeof (contato));
	menu(registros, tamanho);
      
}

int excluirContato(void){
    printf("Uma pena que você não tem o que excluir\n");
	//menu(00, contato contatos[1]);
	return 0;
}

void editarContato(contato registros[]){
	char mensagemInicio[] = "**********   Editar Contato   **********";
	int tamanhoMensagem = tamanhoString(mensagemInicio);
	mensagem(mensagemInicio, tamanhoMensagem);	 
	char nomeBusca[50];
	int tamanho;
	printf("Digite pelo menos parte do nome do contato: ");
	scanf("%49s", nomeBusca);
	tamanho = tamanhoString(nomeBusca);
	buscaString(registros, nomeBusca, tamanho);
	//menu(registros);
	
}

void listarContatos(contato registros[], int tamanho){
    
    char inicio[50] = " 		Lista De Contatos 	";
    char final[50] = "*************************************************";
    int tamanhoMensagem = tamanhoString(inicio);
    contato registroTemp;
    int i, j;
	
	
	for (i=1; i < tamanho; i++){
    	registroTemp = registros[i];
    	j=i-1;
		 
	    while(toupper(registroTemp.nome[0]) < toupper(registros[j].nome[0])){
	        registros[j+1] = registros[j];
	        j--;
	    }
   		registros[j+1] = registroTemp;
}
	mensagem(inicio, 49);
	for(i=0; i < tamanho; i++){
		if(!registros[i].disponivel){
			printf(" %d. ", i);
			printf("Nome: %s | ", registros[i].nome);
			printf("Numero: %s | ", registros[i].numero);
			printf("Email: %s ", registros[i].email);
			printf("\n");
		}
	}
	printf("%s\n", final);
	
	menu(registros, tamanho);
}

int sair(contato registros[], int tamanho){
    int opcaoSair;

    printf("\nDeseja sair da Agenda?\n");
    printf("1 - Sim / 2 - Não\n");
    scanf("%d", &opcaoSair);

    if(opcaoSair == 1){
    	printf("\n -- ATÉ MAIS!!! --\n");
    	exit(0);
	} else if(opcaoSair == 2) {
		system("cls");
		menu(registros, tamanho);
	}else{
        printf("\n-- OPÇÃO INVÁLIDA --\n");
    	sair(registros, tamanho);
	}
}
void tornarDisponiveis(contato registros[], int tamanho){
	int i;
	for(i=0; i < tamanho; i++){
		registros[i].disponivel = true;
	}
}
int verificarItemVazio(contato registros[], int tamanho){
	int index = NULL;

	for(index = 0; index < tamanho; index++){
		if(registros[index].disponivel){
			return index;
		}
	}
	return index;
}
void mensagem(char mensagem[], int tamanho){
	int i;
	for(i=0; i < tamanho; i++){
		printf("-");
	}
	printf("\n%s\n", mensagem);
	
	for(i=0; i < tamanho; i++){
		printf("-");
	}
	printf("\n");
}
int tamanhoString(char mensagem[]){
	int tamanho = 0;
	
	while(mensagem[tamanho] != '\0'){
		tamanho++;
	}
	return tamanho;
}
void buscaString(contato registros[],char nomeBusca[], int tamanho){
	int i, j, cont;
	for(i = 0; i < MAXIMO; i++){
		j = 0;
		if(!registros[i].disponivel){
			while(tolower(registros[i].nome[j]) == tolower(nomeBusca[j]) && j < tamanho ){
				j++;
				if(j == tamanho){
					printf("Código: %i | Nome: %s \n", i, registros[i].nome);
				}
			}
		}
	}
}

