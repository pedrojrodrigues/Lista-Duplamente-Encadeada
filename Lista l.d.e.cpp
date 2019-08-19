#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <locale.h>

struct no{
	int codigo;
	char nm[50];
	char instru[50];
	char music[50];
	char vocali[50];
	struct no *prox, *ante;
};
typedef struct no Nos;
Nos *inicio, *ultimoNo;
int cod;
char nome[50], ins[50], mu[50], voc[50];

void listar(Nos *n);
void inserirInicio(Nos *n);
void cadastro(Nos *n);
void inserirMeio(Nos *n);
void inserirFim(Nos *n);
void busca();
int buscar(Nos *n);
void remover(Nos *n);
void cadastroRemover();
void removerFim(Nos *n);
int tamanhoLista(Nos *n);
void removerMeio(Nos *n);

int main(int argc, char *argv[]) {
	system("color b");
	int op;

	while(op!=5){
		system ("cls");
		printf("\t_____________________________________________________________\n");
		printf("\t-------------------- Cadastro De Banda ----------------------\n");
		printf("\n\t\t(1)-Inserir\n");
		printf("\t\t(2)-Pesquisar\n");
		printf("\t\t(3)-Lista de Cadastros\n");
		printf("\t\t(4)-Remover\n");
		printf("\t\t(5)-Sair\n");

		printf("\n\t\tSelecione a opcao que deseja: ");
		fflush(stdin);
		scanf("%i", &op);

		if (op==1){
			cadastro(inicio);
		}
		if (op==2){
			busca();
		}
		if(op==3){
			listar(inicio);
		}
		if(op==4){
			cadastroRemover();
		}
		if (op==5){
			break;
		}
		system ("cls");
	}

	return 0;

}

void listar(Nos *n){
	int cont=0;
	Nos *noatual;
	noatual = n;
	system("cls");
	printf("\t_____________________________________________________________\n");
	printf("\t-------------------- Cadastro De Banda ----------------------\n");
	tamanhoLista(n);
	if (noatual == NULL){
		printf ("\n\t\tA lista esta vazia.\n\t");
		system ("pause");
		return;
	}
	while (noatual != NULL){
		printf("\n\t\t%d. Senha: %d, Banda: %s, Instrumento: %s, Musica: %s, Vocalista: %s\n\n", cont, noatual->codigo, noatual->nm, noatual->instru, noatual->music, noatual->vocali);
		noatual = noatual->prox;
		cont++;
	}
	printf("\t_____________________________________________________________\n");
	printf("\tPressione ENTER para continuar.\n\t");
	system("pause");
}

void inserirInicio(Nos *n){

	Nos *novo = (Nos*) malloc(sizeof(Nos));// Criaçao de um novo nó.
	novo->codigo = cod;//Passagem de novos dados para o novo nó. Inserido na funçao cadastro.
	strcpy(novo->nm, nome);//
	strcpy(novo->instru, ins);//
	strcpy(novo->music, mu);//
	strcpy(novo->vocali, voc);//

	if (inicio != NULL){//Funçao para adicionar um novo nó na lista, caso ja exista um nó na mesma. Tornando esse novo nó o inicio.
		inicio->ante = novo;//O inicio anterior aponta para o novo nó.
	}
	novo->ante = NULL;//Caso nao tenha nenhum nó na lista ainda, essa parte irá se encarregar de inserir um. O anterior do novo nó aponta pra nulo.
	novo->prox = inicio;//O novo nó proximo  aponta pra inicio.
	inicio = novo;//Por fim, inicio aponta para o novo nó, tornando-o novo inicio.

//	novo->prox = inicio;
//	inicio = novo;
}

void cadastro(Nos *n){

	system("color b");
	int opc;
	char ver;

	while(opc!=4){
		system ("cls");
		printf("\t_____________________________________________________________\n");
		printf("\t-------------------- Cadastro De Banda ----------------------\n");
		printf("\n\t\t(1)-Inserir No Inicio\n");
		printf("\t\t(2)-Inserir No Meio\n");
		printf("\t\t(3)-Inserir No Final\n");
		printf("\t\t(4)-Sair\n");

		printf("\n\t\tSelecione a opcao que deseja: ");
		fflush(stdin);
		scanf("%i", &opc);

		if (opc==1){

			system ("cls");

			do{
				system("cls");
				printf("\t_____________________________________________________________\n");
				printf("\t-------------------- Cadastro De Banda ----------------------\n");

				printf("\n\t\tDigite sua Senha: ");
				scanf("%d", &cod);
				printf("\n\t\tDigite o nome da Banda: ");
				fflush(stdin);
				scanf("%[^\n]s", &nome);
				printf("\n\t\tDigite o Instrumentro a ser cadastrado: ");
				fflush(stdin);
				scanf("%[^\n]s", &ins);
				printf("\n\t\tDigite o nome da Musica: ");
				fflush(stdin);
				scanf("%[^\n]s", &mu);
				printf("\n\t\tDigite o nome do Vocalista: ");
				fflush(stdin);
				scanf("%[^\n]s", &voc);
				inserirInicio(inicio);
				system ("cls");
				printf("\t_____________________________________________________________\n");
				printf("\t-------------------- Cadastro De Banda ----------------------\n");

				printf("\n\t\tDeseja inserir mais algum cadastro na lista?");
				printf("\n\t\tSim(S) ou Nao(N): ");
				fflush(stdin);
				scanf("%[^\n]s", &ver);
				system("cls");

			}while((ver=='S')||(ver=='s'));

			listar(inicio);
		}
		if (opc==2){
			inserirMeio(inicio);
		}
		if (opc==3){
			if(inicio==NULL){
				printf("\n\t\tlista vazia\n\n");
				system("pause");
				return;
			}
			system("cls");
			printf("\t_____________________________________________________________\n");
			printf("\t-------------------- Cadastro De Banda ----------------------\n");
			printf("\n\t\tDigite a senha: ");
			scanf("%d", &cod);
			printf("\n\t\tDigite o nome da banda: ");
			fflush(stdin);
			scanf("%[^\n]s", &nome);
			printf("\n\t\tDigite o nome do instrumento: ");
			scanf("%s", &ins);
			printf("\n\t\tDigite o nome da Musica: ");
			fflush(stdin);
			scanf("%[^\n]s", &mu);
			printf("\n\t\tDigite o nome do Vocalista: ");
			fflush(stdin);
			scanf("%[^\n]s", &voc);
			inserirFim(inicio);
			printf("\n\n");

			listar(inicio);

		}
		if (opc==4){
			break;
		}

		system ("cls");
	}
}

void inserirMeio(Nos *n){

	int cont, psc;//Variáveis para posiçao e contagem.
	
	listar(inicio);//Exibir lista no menu.
	printf("\n\t\tDeseja inserir em qual posicao de 1 a %d: ", tamanhoLista(n));//Aqui é feito o uso da funçao 'tamanhoLista' para saber quantos nos tem na lista.
	scanf("%d", &psc);//Inserir a posiçao em que deseja posicionar o novo no.

	if(psc>0 && psc<=tamanhoLista(n)){//Se a variável 'psc' for maior que 0 e menor igual ao 'tamanhoLista', porderá ser feito um novo cadastro.
		printf("\n\t\tdigite sua Senha:");//Realizaçao do cadastro.
		scanf("%d",&cod);
		printf("\n\t\tdigite o nome da banda:");
		fflush(stdin);
		scanf("%[^\n]s", &nome);
		printf("\n\t\tdigite o nome do instrumento:");
		fflush(stdin);
		scanf("%[^\n]s", &ins);
		printf("\n\t\tdigite o nome da Musica:");
		fflush(stdin);
		scanf("%[^\n]s", &mu);
		printf("\n\t\tdigite o nome do Vocalista:");
		fflush(stdin);
		scanf("%[^\n]s", &voc);

		if(psc== 1){//Se 'psc' for igual à 1, o programa irá chamar a funçao 'inserirInicio' para inserir no inicio.
			inserirInicio(n);
		}else{//Caso 'psc' seja maior que 1, entrará em outra condiçao.
			Nos *atual = n, *ant;//Variáveis ponteiros do tipo Nos. Onde 'atual' aponta para inicio.
			Nos *novo = (Nos*) malloc(sizeof(Nos));//criado um novo nó do tipo e tamanho Nos.
			cont = 1;//contador
			while(cont < psc){//Condição criada para percorrer a lista até chegar na posição desejada.
				ant = atual;//ant aponta pro atual.
				atual = atual->prox;//atual aponta para o próximo.
				cont++;//incremento mais 1 à cont.
			}

			//novo->prox = atual;
			//ant->prox = novo;

			novo->codigo = cod;//inserindo os novos dados no nó.
			strcpy(novo->nm, nome);//..
			strcpy(novo->instru, ins);//..
			strcpy(novo->music, mu);//..
			strcpy(novo->vocali, voc);//..
			novo->ante = n;//O novo nó anterior aponta para inicio.
			novo->prox = n->prox;//O novo nó proximo aponta para inicio proximo.
			n->prox = novo;//O inicio proximo aponta para o novo nó. Assim posicionando-o no meio da lista. 
		}
	}else{//Caso não consiga achar o meio, dará comando invalido.
		printf("\tInvalido\n\n");
	}

}

void inserirFim(Nos *n){

	ultimoNo = inicio;//O 'ultimoNo' que é um  ponteiro do tipo Nos global, aponta para inicio.
	while (ultimoNo->prox != NULL){//Nessa condiçao 'ultimoNo' irá percorrer a lista até chegar no ultimo nó.
		ultimoNo = ultimoNo->prox;
	}

	Nos *novoNo = (Nos*) malloc(sizeof(Nos));//Criado um novo nó do mesmo tipo de Nos.
	novoNo->codigo = cod;//Passagem dos novos dados para o nó 'novoNo'.
	strcpy(novoNo->nm, nome);//
	strcpy(novoNo->instru, ins);//
	strcpy(novoNo->music, mu);//
	strcpy(novoNo->vocali, voc);//

	novoNo->ante = ultimoNo;//O 'novoNo' anterior aponta para o 'ultimoNo', que é o ultimo da lista.
	novoNo->prox = NULL;//O 'novoNo' proximo aponta para NULL(nulo).
	ultimoNo->prox = novoNo;//'ultimoNo' proximo,que antes apontava para NULL, agora aponta para 'novoNo'.

//	novoNo->prox = NULL;
//	ultimoNo->prox = novoNo;

}

int buscar(Nos *n, char nome[50]){
	int achou=0;

	while (n != NULL){
		if (strcmp(n->nm, nome)==0){
			achou = achou+1;
		}
		n = n->prox;
	}
	return achou;

}

void busca(){

	Nos *n = inicio;
	int cont=0;
	printf("\n\n\tDigite o nome da banda que deseja procurar: ");
	fflush(stdin);
	scanf("%[^\n]s", &nome);

	if(buscar(inicio, nome)==0){
		printf("\tNao Achou");
	}else{
		while (n != NULL){
		if (strcmp(n->nm, nome)==0){
			printf("\n\t\t%d. Senha: %d, Banda: %s, Instrumento: %s, Musica: %s, Vocalista: %s\n\n", cont, n->codigo, n->nm, n->instru, n->music, n->vocali);
		}
		n = n->prox;
		}
		system("pause");
	}
}

void remover(Nos *n){

	Nos *aux;//Criação de um ponteiro auxiliar do tipo Nos.

	if (n == NULL){//Essa condiçao verifica se a lista esta vazia.
		printf ("\n\t\tA Lista esta vazia.\n\t\t");
		system ("pause");
		return;
	}

	if (inicio->prox == NULL){//Já essa, verifica se a lista só tem um nó. Caso tenha somente um, ela aplicará o free em inicio e em seguida apontar para nulo, assim removendo o nó. 
		free (inicio);
		inicio = NULL;
		printf("\t\tRemovido com sucesso\n\t\t");
		system("pause");
		return;
	}
	aux = inicio->prox;//Caso tenha mais de 1 nó na lista, a funçao fará uso do ponteiro aux. 'aux' aponta para inicio proximo.
	aux->ante = NULL;//Em seguida o aux anterior aponta para nulo.
	free (inicio);// Daí é aplicado free no inicio, pois o ponteiro aux ja fez referencia do inicio proximo. 
	inicio = aux;//Inicio aponta para aux, tornando se o inicio.

	/*aux = inicio->prox;
	free(inicio);
	inicio=aux;*/

	printf("\t\tRemovido com sucesso\n\t\t");
	system ("pause");
}

void removerFim(Nos *n){
	Nos *no = n;

	if(no==NULL){//Verifica se a lista esta vazia.
		printf("\tLista vazia");
		return;
	}
	if(no-> prox==NULL){//Caso só tenha um nó, aplicará free no inicio. O mesmo esquema do remover no inicio.
		free (inicio);
		inicio = NULL;
		printf("\t\tRemovido com sucesso\n\t");
		system("pause");
		return;
	}

	while(no ->prox != NULL){//Esse laço faz com que chegue no final da lista, caso tenha mais de 1 nó.
		no = no-> prox; //paro no ultimo nó da lista
	}

	no->ante->prox = NULL;// Já no ultimo nó, o nó anterior de 'no' aponta para nulo. prox aponta para nulo.
	free (no);//Em seguida é aplicado o free em 'no'.

	printf("\t\tRemovido\n\t\t");
	system("pause");
	listar(inicio);//Lista os cadastros para verificaçao.
}

int tamanhoLista(Nos *n){

	int cont=1;
	n = inicio;
	while (n != NULL){
		cont++;
		n = n->prox;
	}
	return cont;
}

void removerMeio(Nos *n){

	int cont = 0;//Contador.
	int t, op;// Variáveis do tipo inteiro.

	if (n==NULL){//Verifica se a lista esta vazia.
		printf("\tLista Vazia");
		return;
	}
	t = tamanhoLista(n);//'t' recebe o tamanho da lista.
	if (t < 3){//Verifica se a lista tem menos de 3 nós.
		return;
	}

	listar(inicio);//Lista os cadastros.
	printf("\n\t\tDigite o cadastro que deseja excluir: ");// Pergusta qual cadastro deseja remover, que esteja no meio.
	scanf("%d", &op);
	n = inicio;//'n' aponta para inicio.
	while (n != NULL){//Laço para percorrer a lista.
		cont++;// Incremento na variável cont.
		n = n->prox;//'n' que tem o referencial de inicio, aponta para n proximo. Assim caminhando pela lista.
		if (cont==op){//Condiçao que verifica se o contador(cont) é igual à opçao(op) escolhida.
			n->prox->ante = n->ante;//Caso seja igual, O anterior do proximo de 'n' aponta para o anterior de 'n'.
			free(n->ante->prox);//Em seguida, o nó proximo do anterior de 'n' recebe um free para liberar espaço.
			n->ante->prox = n->prox;//Por ultimo, O proximo do anterior de 'n' aponta para o proximo de 'n'.
			printf("\t\tExcluido com sucesso\n\n\t");
			system("pause");
			break;
		}
	}

	//ant->prox = depois;
	//free(n);
	//n = NULL;
}

void cadastroRemover(){

	system("color b");
	int opc;

	while(opc!=4){
		system ("cls");
		printf("\t_____________________________________________________________\n");
		printf("\t--------------------- Cadastro De Banda ---------------------\n");
		printf("\n\t\t(1)-Remover No Inicio\n");
		printf("\t\t(2)-Remover No Meio\n");
		printf("\t\t(3)-Remover No Final\n");
		printf("\t\t(4)-Sair\n");

		printf("\n\t\tSelecione a opcao que deseja: ");
		fflush(stdin);
		scanf("%i", &opc);

		if (opc==1){
			remover(inicio);

		}
		if(opc==2){
			removerMeio(inicio);
		}
		if (opc==3){
			removerFim(inicio);

		}
		if (opc==4){
			break;
		}

		system ("cls");
	}
}
