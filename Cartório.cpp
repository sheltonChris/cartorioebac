#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel pelas strings

int registro() //função responsavel por cadastrar os usuarios
{
	//inicio de criação de variaveis
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //finalo da criação de variaveis
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
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
	  printf("Não foi encontrado\n");
	}
	
    while(fgets(conteudo,200,file) !=NULL)
    {
    	printf("\nEssas são as informações do usuário:");
    	printf("%s",conteudo);
    	printf("\n\n");
    	
	}
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	
	printf("Qual o CPF do usuário que vai ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
}
int main()
    {
	int opcao=0;//Definindo a variaveis
	int rep=1;//Repetição do sistema
	
	for(rep=1;rep=1;)
	{
	 
	 system("cls");
	 
	 setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	 printf("###  Cartório da Ebac  ###\n\n");//Inicio do menu
	 printf("Escolha a opção desejada no menu:\n\n");
	 printf("\t1 - Resgistrar usuários.\n");
	 printf("\t2 - Consultar usuários cadastrados.\n");
	 printf("\t3 - Deletar usuários cadastrados.\n\n");
	 printf("\t4 - Sair do sistema.\n\n");
	 printf("Opção:");// fim do menu
	
	 scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	 system("cls");//limpar a tela
	 
	 switch(opcao) // inicio de decições do usuario
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
		 printf("Essa opção não está disponivel!\n");
	 	 system("pause");
	 	 break;
	 }
	
    }
}
