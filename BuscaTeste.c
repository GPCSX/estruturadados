/*
	Organização de Estruturas de Arquivos
	Gabriel Pacheco
*/

#include <stdio.h>
#include <string.h>
#pragma pack(1)

typedef struct _Endereco Residencia;

struct _Endereco
{	
	char cidade[72];
	char uf[72];
	char bairro[72];
	char sigla[2];
	char cep[8];
	char logradouro[72];
	char lixo[2];
};


int main(int argc, char**argv)
{
	FILE *f;
	Residencia local;
	int qtd;
	long posicao, inicio, meio, fim;
	long cont = 0;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}
	f = fopen("cep_ordenado.dat","r");
	fseek(f,0,SEEK_END);
	posicao = ftell(f);
	rewind(f);

	printf("Tamanho do Arquivo: %ld\n", posicao);
	printf("Tamanho do Registro: %ld\n", (long)sizeof(Residencia));
	printf("Tamanho do Arquivo em Registros: %ld\n\n\n\n", posicao/sizeof(Residencia));
	
	inicio = 0;
	fim = (posicao/sizeof(Residencia))-1;
	cont=0;

     while(inicio <= fim)
     {	
     	cont++;
         meio = (inicio + fim)/2;
         
         fseek(f, meio * sizeof(Residencia), SEEK_SET);
         
         fread(&e,sizeof(Residencia),1,f);
         
         if(strncmp(argv[1],local.cep,8)==-1){
               fim = meio-1;
         }else if(strncmp(argv[1],local.cep,8)== 1){
               inicio = meio+1;        
         }else{
    			printf("Contador: %ld\n\n", cont);
               return printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",local.logradouro,local.bairro,local.cidade,local.uf,local.sigla,local.cep);

               break;
         }
      
     }   
	rewind(f);
	
	fclose(f);
}

