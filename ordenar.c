#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM 6


typedef struct{
	int Valores[MAX_MEM];
	int Status[MAX_MEM];
}Dados;

void Seleciona(FILE *, Dados *, int *);

int main(void){
	Dados Registros;
	FILE *Fluxo;
	int i, Qtd_Particoes = 0;

	for(i=0;i<MAX_MEM;i++){
		Registros.Status[i] = 1;
	}
	// Abrir Arquivo
	Fluxo = fopen("Entrada.ori","rb");
	if(Fluxo == NULL){
		printf("Erro ao abrir o arquivo para leitura - Entrada.ori.\n");
		exit(-1);
	}
	for(i=0;i<MAX_MEM;i++)
		fread(&(Registros.Valores[i]),sizeof(int), 1 , Fluxo);
	Seleciona(Fluxo, &Registros, &Qtd_Particoes);
	printf("SAIU DA FUNÇÃO\n");
	fclose(Fluxo);
	return 0;
}


void Seleciona(FILE *Fluxo, Dados *Registros, int *Qtd_Particoes){
	FILE *FluxoSaida;
	int i, Menor, Temp, Qtd_Congelados = MAX_MEM;
	char Nome[8] ={'0','0','0','.','o','r','i','\0'};
	while(!feof(Fluxo)){
		// ----- Mudar isso Depois
		if(Nome[2] == '9'){
			if(Nome[1] == '9'){
				Nome[0]++;
				Nome[1] = '0';
				Nome[2] = '0';
			}else{
				Nome[2] = '0';
				Nome[1]++;
			}
		}else
			Nome[2]++;
		if(Nome[0] == '9')
			break;
		// -----------------
		//Abrir Arquivo de Saída
		printf("Nome Aqr - %s\n", Nome);
		FluxoSaida = fopen(Nome,"wb");
		if(FluxoSaida == NULL){
			printf("Erro de Alocação.\n");
			exit(-1);
		}
		for(i=0;i < MAX_MEM;i++){
			//printf("Valor para o vetor indice %d\n\n", i);
			//printf("ClienteID = %d\n", Registros->Valores[i]);
		}
		
		while(Qtd_Congelados){
			
			// Pegar o primeiro menor não congelado
			for(i=0;i < MAX_MEM;i++)
				if(Registros->Status[i])
					break;
			Menor = i;
			//printf("Menor inicialmente recebeu - %d\n", Menor);
			
			
			// Pegar o menor
			for(i = 0; i < MAX_MEM ; i++){
				if(Registros->Valores[i] < Registros->Valores[Menor] && Registros->Status[i]){
					Menor = i;
					//printf("Menor foi alterador para - %d\n", Menor);
				}
			}
			
			
			
			// Escrever no Arquivo
			Temp = Registros->Valores[Menor];
			//printf("Temp recebeu - %d\n", Registros->Valores[Menor]);
			fwrite(&(Registros->Valores[Menor]), sizeof(int), 1 , FluxoSaida);
			printf("%d ", Registros->Valores[Menor]);
			//Verificar fim de arquivo
			if(!feof(Fluxo)){
				fread(&(Registros->Valores[Menor]),sizeof(int), 1, Fluxo);
				if(Registros->Valores[Menor] < Temp){
					Registros->Status[Menor] = 0;
					Qtd_Congelados--;
				}
			}else{
				Qtd_Congelados--;
				Registros->Status[Menor] = 0;
			}
				
		}
		//Fechar Partição
		fclose(FluxoSaida);
		//Descongelar
		
		for(i=0;i<MAX_MEM;i++)
			Registros->Status[i] = 1;
		Qtd_Congelados = MAX_MEM;
	}	
}
