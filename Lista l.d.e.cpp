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

	Nos *novo = (Nos*) malloc(sizeof(Nos));// Cria�ao de um novo n�.
	novo->codigo = cod;//Passagem de novos dados para o novo n�. Inserido na fun�ao cadastro.
	strcpy(novo->nm, nome);//
	strcpy(novo->instru, ins);//
	strcpy(novo->music, mu);//
	strcpy(novo->vocali, voc);//

	if (inicio != NULL){//Fun�ao para adicionar um novo n� na lista, caso ja exista um n� na mesma. Tornando esse novo n� o inicio.
		inicio->ante = novo;//O inicio anterior aponta para o novo n�.
	}
	novo->ante = NULL;//Caso nao tenha nenhum n� na lista ainda, essa parte ir� se encarregar de inserir um. O anterior do novo n� aponta pra nulo.
	novo->prox = inicio;//O novo n� proximo  aponta pra inicio.
	inicio = novo;//Por fim, inicio aponta para o novo n�, tornando-o novo inicio.

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

	int cont, psc;//Vari�veis para posi�ao e contagem.
	
	listar(inicio);//Exibir lista no menu.
	printf("\n\t\tDeseja inserir em qual posicao de 1 a %d: ", tamanhoLista(n));//Aqui � feito o uso da fun�ao 'tamanhoLista' para saber quantos nos tem na lista.
	scanf("%d", &psc);//Inserir a posi�ao em que deseja posicionar o novo no.

	if(psc>0 && psc<=tamanhoLista(n)){//Se a vari�vel 'psc' for maior que 0 e menor igual ao 'tamanhoLista', porder� ser feito um novo cadastro.
		printf("\n\t\tdigite sua Senha:");//Realiza�ao do cadastro.
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

		if(psc== 1){//Se 'psc' for igual � 1, o programa ir� chamar a fun�ao 'inserirInicio' para inserir no inicio.
			inserirInicio(n);
		}else{//Caso 'psc' seja maior que 1, entrar� em outra condi�ao.
			Nos *atual = n, *ant;//Vari�veis ponteiros do tipo Nos. Onde 'atual' aponta para inicio.
			Nos *novo = (Nos*) malloc(sizeof(Nos));//criado um novo n� do tipo e tamanho Nos.
			cont = 1;//contador
			while(cont < psc){//Condi��o criada para percorrer a lista at� chegar na posi��o desejada.
				ant = atual;//ant aponta pro atual.
				atual = atual->prox;//atual aponta para o pr�ximo.
				cont++;//incremento mais 1 � cont.
			}

			//novo->prox = atual;
			//ant->prox = novo;

			novo->codigo = cod;//inserindo os novos dados no n�.
			strcpy(novo->nm, nome);//..
			strcpy(novo->instru, ins);//..
			strcpy(novo->music, mu);//..
			strcpy(novo->vocali, voc);//..
			novo->ante = n;//O novo n� anterior aponta para inicio.
			novo->prox = n->prox;//O novo n� proximo aponta para inicio proximo.
			n->prox = novo;//O inicio proximo aponta para o novo n�. Assim posicionando-o no meio da lista. 
		}
	}else{//Caso n�o consiga achar o meio, dar� comando invalido.
		printf("\tInvalido\n\n");
	}

}

void inserirFim(Nos *n){

	ultimoNo = inicio;//O 'ultimoNo' que � um  ponteiro do tipo Nos global, aponta para inicio.
	while (ultimoNo->prox != NULL){//Nessa condi�ao 'ultimoNo' ir� percorrer a lista at� chegar no ultimo n�.
		ultimoNo = ultimoNo->prox;
	}

	Nos *novoNo = (Nos*) malloc(sizeof(Nos));//Criado um novo n� do mesmo tipo de Nos.
	novoNo->codigo = cod;//Passagem dos novos dados para o n� 'novoNo'.
	strcpy(novoNo->nm, nome);//
	strcpy(novoNo->instru, ins);//
	strcpy(novoNo->music, mu);//
	strcpy(novoNo->vocali, voc);//

	novoNo->ante = ultimoNo;//O 'novoNo' anterior aponta para o 'ultimoNo', que � o ultimo da lista.
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

	Nos *aux;//Cria��o de um ponteiro auxiliar do tipo Nos.

	if (n == NULL){//Essa condi�ao verifica se a lista esta vazia.
		printf ("\n\t\tA Lista esta vazia.\n\t\t");
		system ("pause");
		return;
	}

	if (inicio->prox == NULL){//J� essa, verifica se a lista s� tem um n�. Caso tenha somente um, ela aplicar� o free em inicio e em seguida apontar para nulo, assim removendo o n�. 
		free (inicio);
		inicio = NULL;
		printf("\t\tRemovido com sucesso\n\t\t");
		system("pause");
		return;
	}
	aux = inicio->prox;//Caso tenha mais de 1 n� na lista, a fun�ao far� uso do ponteiro aux. 'aux' aponta para inicio proximo.
	aux->ante = NULL;//Em seguida o aux anterior aponta para nulo.
	free (inicio);// Da� � aplicado free no inicio, pois o ponteiro aux ja fez referencia do inicio proximo. 
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
	if(no-> prox==NULL){//Caso s� tenha um n�, aplicar� free no inicio. O mesmo esquema do remover no inicio.
		free (inicio);
		inicio = NULL;
		printf("\t\tRemovido com sucesso\n\t");
		system("pause");
		return;
	}

	while(no ->prox != NULL){//Esse la�o faz com que chegue no final da lista, caso tenha mais de 1 n�.
		no = no-> prox; //paro no ultimo n� da lista
	}

	no->ante->prox = NULL;// J� no ultimo n�, o n� anterior de 'no' aponta para nulo. prox aponta para nulo.
	free (no);//Em seguida � aplicado o free em 'no'.

	printf("\t\tRemovido\n\t\t");
	system("pause");
	listar(inicio);//Lista os cadastros para verifica�ao.
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
	int t, op;// Vari�veis do tipo inteiro.

	if (n==NULL){//Verifica se a lista esta vazia.
		printf("\tLista Vazia");
		return;
	}
	t = tamanhoLista(n);//'t' recebe o tamanho da lista.
	if (t < 3){//Verifica se a lista tem menos de 3 n�s.
		return;
	}

	listar(inicio);//Lista os cadastros.
	printf("\n\t\tDigite o cadastro que deseja excluir: ");// Pergusta qual cadastro deseja remover, que esteja no meio.
	scanf("%d", &op);
	n = inicio;//'n' aponta para inicio.
	while (n != NULL){//La�o para percorrer a lista.
		cont++;// Incremento na vari�vel cont.
		n = n->prox;//'n' que tem o referencial de inicio, aponta para n proximo. Assim caminhando pela lista.
		if (cont==op){//Condi�ao que verifica se o contador(cont) � igual � op�ao(op) escolhida.
			n->prox->ante = n->ante;//Caso seja igual, O anterior do proximo de 'n' aponta para o anterior de 'n'.
			free(n->ante->prox);//Em seguida, o n� proximo do anterior de 'n' recebe um free para liberar espa�o.
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
