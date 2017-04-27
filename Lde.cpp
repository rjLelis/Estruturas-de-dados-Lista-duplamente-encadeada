#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//Estrutura da lde
struct lde_funcionario{
	int codigo,idade;
	char nome[50],cargo[20];
	float salario;
	struct lde_funcionario *prox,*ant;
}*prim,*ult,*aux;

//Assinaturas das funções
void inclusao(int codigo,int idade,char nome[],float salario,char cargo[]);//Inclusao de um funcionario
void exclusao(int codigo);//exclusao de um funcionario pelo codigo
void listagem();//Listagem do(s) elemento(s) (Crescente)
void listagemdec();//Listagem do(s) elemento(s) (Decrescente)
int cont_estagiario();//Contador de estagiario
int cont_idade();//Contador de funcioarios que tem idade entre 20 e 30 anos
int soma_idade(float sal);//Soma das idades dos funcionarios que tem o salario maior que o fornecido

//programa principal
main() {
	int op = 0,codigo,idade;
	char nome[50],cargo[20];
	float salario;
	do{
		puts("1 - inclusao");
		puts("2 - listagem");
		puts("3 - exclusao");
		puts("4 - listagem ao contrario");
		puts("5 - Contador de estagiarios");
		puts("6 - Contagem de idade entre 20 e 30 anos");
		puts("7 - Soma das idades de funcionarios com salario maior que o fornecido");
		puts("0 - sair");
		cout << ">>> ";
		cin >> op;
		switch(op){
			case 0://Finalizando o programa
				puts("O PROGRAMA ESTA SENDO FINALIZADO...");
				break;
			case 1://Inclusao
				cout << "Digite o CODIGO do funcionario: ";
				cin >> codigo;fflush(stdin);
				cout << "Digite o NOME do funcionario: ";
				gets(nome);fflush(stdin);
				cout << "Digite o CARGO do funcionario: ";
				gets(cargo);fflush(stdin);
				cout << "Digite a IDADE do funcionario: ";
				cin >> idade;fflush(stdin);
				cout << "Digite o SALARIO do funcionario: ";
				cin >> salario;fflush(stdin);
				inclusao(codigo,idade,nome,salario,cargo);
				break;
			case 2:// Listegem crescente
				listagem();
				break;
			case 3:// Exclusao
				cout << "Digite o CODIGO do funcionario para ser excluido: ";
				cin >> codigo;
				exclusao(codigo);
				break;
			case 4:// Listagem decrescente
				listagemdec();
				break;
			case 5:// Função para contar quantos "estagiarios" tem na lista
				cout << "A quantidade de estagiarios e de: " << cont_estagiario() << "\n";
				break;
			case 6:// Função para contar quantos funcionarios tem idade entre 20 e 30 anos
				cout << cont_idade() << " funcionario(s) tem idade entre 20 e 30 anos\n";
				break;	
			case 7:// Função para somar a idade dos funcionarios com salario maior que o fornecido
				cout << "digite um salario: ";
				cin >> salario;
				cout << "A soma da idade dos funcionarios com o salario acima do informado e de: " << soma_idade(salario) << "\n";	
				break;
			default:
				puts("Opcao invalida!");
		}
	}while(op != 0);
	cout << "PROGRAMA FINALIZADO";
}

//Inclusao
void inclusao(int codigo,int idade,char nome[],float salario,char cargo[]){
	aux = (struct lde_funcionario *) malloc(sizeof(struct lde_funcionario));
	if(prim == NULL){//Se a lista não existir
		prim = aux;
		prim->ant = NULL;
	} else{//Se a lista existir
		ult->prox = aux;
		aux->ant = ult;
	}
	ult = aux;//Todo elemento recem adicionado é automaticamento o ultimo
	//Atribuição dos elementos
	ult->codigo = codigo;
	ult->idade = idade;
	strcpy(ult->nome,nome); 
	strcpy(ult->cargo,cargo);
	ult->salario = salario;
	ult->prox = NULL;
	puts("Inclusao realizada!");
}

//Exclusao
void exclusao(int codigo){
	int achei = 0;
	aux = prim;//Iniciando a busca
	while(aux != NULL && achei == 0){
		if(aux->codigo == codigo){
			if(aux == prim){
				if(prim == ult){
					prim = ult = NULL;
				} else{
					prim = prim->prox;
					prim->ant = NULL;
				}
			} else if(aux == ult){
				ult = ult->ant;
				ult->prox = NULL;
			} else{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
			achei = 1;
			free(aux);
		} else{
			aux = aux->prox;
		}
	}
	if(achei == 0){
		puts("Funcionario inexistente na lista!");
	}else{
		puts("Exclusao realizada!");
	}
}

//Listagem crescente
void listagem(){
	aux = prim;//inicializando a varredura
	cout << "---------- FUNCIONARIOS ----------\n";
	while(aux != NULL){
		cout <<"Codigo: "<< aux->codigo <<"\nNome: " << aux->nome  << "\nIdade: " << aux->idade << "\nCargo: " << aux->cargo << "\nSalario: " << aux->salario << "\n";
		cout << "--------------------------------- \n";
		aux = aux->prox;
	}
}

//Listagem decrecente
void listagemdec(){
	aux = ult;
	cout << "---------- FUNCIONARIOS ----------\n";
	while(aux != NULL){
		cout <<"Codigo: "<< aux->codigo <<"\nNome: " << aux->nome  << "\nIdade: " << aux->idade << "\nCargo: " << aux->cargo << "\nSalario: " << aux->salario << "\n";
		cout << "--------------------------------- \n";
		aux = aux->ant;
	}
}

//Contador de estagiário
int cont_estagiario(){
	int cont = 0;
	aux = prim;
	while(aux != NULL){
		if(strcmp(aux->cargo,"estagiario") == 0){
			cont++;
		}
		aux = aux->prox;
	}
	return cont;
}

//Contador de funcioarios que tem idade entre 20 e 30 anos 
int cont_idade(){
	int cont = 0;
	aux = prim;
	while(aux != NULL){
		if(aux->idade >= 20 && aux->idade <=30){
			cont++;
		}
		aux = aux->prox;
	}
	return cont;
}

//Soma das idades dos funcionarios que tem o salario maior que o fornecido
int soma_idade(float sal){
	int cont = 0;
	aux = prim;
	while(aux != NULL){
		if(aux->salario > sal){
			cont += aux->idade;
		}
		aux = aux->prox;
	}
	return cont;
}
