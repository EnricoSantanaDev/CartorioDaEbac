#include <stdio.h>   //biblioteca de comunicaçao com o usuario
#include <stdlib.h>  //biblioteca de alocaçao de espaço de memoria
#include <locale.h> //bibliotecea de alocaçao de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar da string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");

	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); // responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); //abre o arquivo do banco de dados
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");

	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o arquivo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o Cpf a ser deletado: ");

	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Cpf não foi encontrado no sistema!. \n");
		system("pause");
	}
	
}


int main()       //inicio da função principal
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	    system("cls");
	
	     setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	     printf("\nSeja bem-vindo ao cartório da Ebac \n\n"); //inicio do menu
	     printf("Escolha a opção desejada do menu: \n\n");
	     printf("\t1 - Registrar nomes \n");
	     printf("\t2 - Consulta de nomes \n");
	     printf("\t3 - Deletar nomes \n");
	     printf("\t4 - Sair do sistema \n");
	     printf("Opção: ");  //fim do menu
	
	     scanf("%d", &opcao); //armazenando a escolha do usuario na variavel opçao
	
 	     system("cls");
 	     
	
	     if(opcao==1) //inicio da seleçao 
	     {
	    	registro();
		   
     	 }
	     if(opcao==2)
	     {
		    consulta();
      	 }
	     if(opcao==3)
         {
    	    deletar();
       	 }
       	 if(opcao==4)
         {
           printf("Obrigado por utilizar o sistema!\n");
           return 0;
           break;
		 }
     	 if(opcao>=5 || opcao<=0)
	     {
	   	    printf("Essa opçao não está disponivel!\n");
	   	    system("pause");
      	 } //fim da seleçao
      	 

}
}
