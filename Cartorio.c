#include <stdio.h>  //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao (biblioteca de idiomas)
#include <string.h> //biblioteca de strings

								//Inicio das funcoes do Menu
							
int registro() //aqui nos criamos a segunda tela do aplicativo, conforme coloquei nas minhas anotacoes, nao tem problema ir antes do int main, pois o sistema sempre vai rodar o int main primeiro.
{
								//Inicio criacao de variaveis (strings)
							
	char arquivo[11];
	char cpf[11]; //aqui criamos a string, para o computador ler as letras dos nome.
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
								//Fim da Criacao de variaveis (strings)
								
							
							
								//Inicio da Funcao Registro de Usuario
							
	printf("Digite o CPF que deseja Cadastrar: ");
	scanf("%s", cpf); //%s e usado para strings
	
	strcpy(arquivo, cpf); //copia o valor da strings, nesse caso o arquivo ta copiando o valor do cpf
	
	FILE *file; //aqui estamos criando o arquivo no banco de dados.
	file = fopen(arquivo, "w"); //essa linha tambem e responsavel pela criacao do arquivo
	fprintf(file, cpf); //aqui estamos salvando o valor da variavel, escrevendo ela no banco de dados.	
	fclose(file); //ta fechando o arquivo que abrimos
	
	file = fopen(arquivo, "a"); //aqui estamos abrindo o arquivo e atualizando(add) coisas novas a um arquivo ja aeistente
	fprintf(file, ","); //aqui estamos dando espacamento nas informacoes que vao ser salvas
	fclose(file);
	
	printf("Digite o nome que deseja Cadastrar: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //estamos novamente abrei o arquivo e add informacoes a ele
	fprintf(file,nome); //dando o comando para que a variavel nome seja escrita dentro desse arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //colocando espacamento 
	fclose(file);
	
	printf("Digite o soobrenome que deseja Cadastrar: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //colocando espacamento novamente //colocando espacamento novamente
	fclose(file);
	
	printf("Digite o cargo ocupado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
								//Fim da funcao Registro de Usuario
}


int consulta()
{	
								//Inicio da Criacao de Variaveis
	
	char cpf[11]; //como estamos em novos colchetes, a variavel criada nao existe aqui, entao tem que criar variaveis novas
	char conteudo[500];
	
								//Fim da Criacao de Variaveis
							
							
								//Inicio da Funcao Conlsutar Usuario
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file; //aqui estamo dizendo para o computador, olha, pega o arquivo que chama file ai.
	file = fopen(cpf, "r"); //abre o file pela variavekl cpf e leia ele (o "r" vem do ingles read, que siginifica ler).
	
	if(file == NULL)
	{
		printf("\n\n\nUsuario Inexistente!\n\n\n");
	}
	
	while(fgets(conteudo, 500, file) != NULL) //aqui estamos dizendo ao computador que "enquanto ele estiver escrevendo na variavel (ou no string conteudo), ate 500 valores nesse caso e, enquanto isso for diferente de nulo, quando for nulo nao precisa trazer, acabou.
	{
		printf("\n\n\nEssas sao as informacoes do Usuario: ");
		printf("%s", conteudo); //esse aqui ptinf ta um pouco diferente, mas basicamente siginifica, computador, mostra na tela do usuario as informacoes salvas na variavel conteudo (foram salvas no while).
		printf("\n\n\n\n\n");
	}
	
	system("pause");
	
								//Fim da Funcao Consultar Usuario
		
}

int deletar()
{
								//Inicio da Criacao de Variaveis
	
	char cpf[11]; //criando novamente a string cpf, nossa variavel primary key
	
								//Fim da Criacao de Variaveis
	
	
								//Inicio da Funcao Deletar Usuario
	
	printf("Digite o CPF do usario que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf); //a funcao "remove", ja faz com que o computador entenda que tem que entrar nos arquivos do file e deletar o cpf desejado.
	
	FILE *file; //aqui novamente estamos dizendo ao computador, abre a "pasta" file, e leia os arquivos que tem nela
	file = fopen(cpf, "r"); //abre o arquivo pelo numero da string cpf, e leia esse arquivo.
		
	if(file == cpf)
	{
		printf("\n\n\nUsuario Deletado!\n\n\n");
		system ("pause");
	}
	
	else
		printf("\n\n\nUsuario Inexistente!\n\n\n");
		
		
	system("pause");
	
								//Fim da Funcao Deletar Usuario
	
}
							
								//Fim das Funcoes do Menu
						
						
						
								//Inicio do Menu(codigo Principal)
int main()
{
								//Inicio da Criacao de Variaveis
	
	int menu=0;  //definindo variaveis
	int x=1;
	char senha[10] = "a";
	int comparacao;
	
	printf("\tCARTORIO DA EBAC\n\n");
	printf("Login de Administrador!\n\nDigite a sua Senha: ");
	scanf("%s", senha);	
	
	comparacao = strcmp(senha, "admin");
	
	if(comparacao == 0) //Aqui estamos colocando uma senha para ter acesso ao sistema.
	{
		system("cls");
													
								//Fim da Criacao de Variaveis
							
							
								//Inicio da Funcao de Repeticao (laco de Repeticao)
							
		for(x=1;x=1;) //variavel criada para que o software sempre volte para o menu (loop infinito).
		{
		
			system("cls"); //apagando informacoes da tela
	
	
			setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
			printf("\tCARTORIO DA EBAC\n\n"); //inicio do menu
			printf("Escolha a opcao desejada do menu:\n\n");
			printf("1 - Registrar Nomes\n");
			printf("2 - Consultar Nomes\n");
			printf("3 - Deletar Nomes\n");
			printf("4 - Sair do sistema\n\n\n\n\n\n");
			printf("Escolha a opcao desejada: ");  //fim do menu
	
			scanf("%d", &menu); //armazenando a escolha do usuario
	
			system("cls"); //apagando coisas desnecessarias da tela
			
		
								//Inicio da Selecao do Menu
		
			switch(menu)
			{
				case 1:	//dizendo para o computador que caso seja essa opcao, realizar isso
				registro();
				break; //serve para finalizar a opcao no switch case
			
				case 2: //dizendo para o computador que caso seja essa opcao, realizar isso
				consulta();
				break;
			
				case 3: //dizendo para o computador que caso seja essa opcao, realizar isso
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o Sistema!\n\n\n\n\n\n");
				return 0;
				break;
				
				default:
				printf("Opcao Invalida! Tente de novo!\n\n\n\n\n\n\n");
				system("pause");
				break;					
			}
	
								//Fim da Selecao do Menu

		}
	
								//Fim da Funcao de Repeticao (Laco de Repeticao)
	}
	
	else
		printf("\tSenha Invalida!\n\n\n\n\n\n");
}
								//Fim do Menu(codigo principal)
