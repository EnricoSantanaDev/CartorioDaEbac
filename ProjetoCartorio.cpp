#include <stdio.h> //biblioteca de comunicaocao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsavel pelas strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria arquivo 
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite  o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");   //colocando a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");

	
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);

    remove(cpf);
     
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
    {
    	printf("O CPF digitado n�o pertence a um usuario cadastrado.\n\n");
    		system("pause");
	}

}

int main()
{
	int opcao=0; //deifinindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
 setlocale(LC_ALL, "Portuguese");   //colocando a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n");   // inicio do menu do site
	printf("Escolha a op��o desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n");
	
	printf("Op��o:"); //fim do menu
	
	scanf("%d", &opcao);  //armazenando escolha do usuario
	
	system("cls");
	
	switch(opcao)  //inicio da sele�ao
	{
		case 1:
			registro();
			break;
			
		case 2:
			consulta();
			break;
			
		case 3:
			deletar();
			break;
			
		case 4:
			printf("Obrigado por usar o sitema!");
			return 0;
			break;
			
		default:
		printf("Op��o n�o existe!"); //fim da sele�ao
		system("pause");
	}
}
}

