#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel pelas strings

int registro() //fun��o responsavel por cadastrar os usuarios
{
	//inicio de cria��o de variaveis
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //finalo da cria��o de variaveis
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
    scanf("%s", cpf);
    
    strcpy(arquivo,cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file= fopen(arquivo,"w");//cria o arquivo 
    fprintf(file,cpf);//salvo o valor da variavel
    fclose(file);// fecha o arquivo
    
    file=fopen(arquivo,"a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file," ");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,".");
    fclose(file);
    
    system("pause");
    
    
    
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consutado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	  printf("N�o foi encontrado\n");
	}
	
    while(fgets(conteudo,200,file) !=NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio:");
    	printf("%s",conteudo);
    	printf("\n\n");
    	
	}
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	
	printf("Qual o CPF do usu�rio que vai ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
}
int main()
    {
	int opcao=0;//Definindo a variaveis
	int rep=1;//Repeti��o do sistema
	
	for(rep=1;rep=1;)
	{
	 
	 system("cls");
	 
	 setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	 printf("###  Cart�rio da Ebac  ###\n\n");//Inicio do menu
	 printf("Escolha a op��o desejada no menu:\n\n");
	 printf("\t1 - Resgistrar usu�rios.\n");
	 printf("\t2 - Consultar usu�rios cadastrados.\n");
	 printf("\t3 - Deletar usu�rios cadastrados.\n\n");
	 printf("\t4 - Sair do sistema.\n\n");
	 printf("Op��o:");// fim do menu
	
	 scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	 system("cls");//limpar a tela
	 
	 switch(opcao) // inicio de deci��es do usuario
	 {
	 	case 1:
		 registro();
		 break;
		 
		case 2:
		 consultar();
		 break;
		 
		case 3:
		 deletar();
	 	 break;
	 	 
	 	case 4:
	 	printf("Obrigado por utilizar o sistema!\n");
	 	return 0;
	 	break;
	 		
	 	 
	 	default:
		 printf("Essa op��o n�o est� disponivel!\n");
	 	 system("pause");
	 	 break;
	 }
	
    }
}
