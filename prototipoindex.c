#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ed,id;
}index;
void indexPrototipo(char **nome_arquivo){
	Lista *dados,*aux,*aux2,*anterior; // pegar uma lista de uma lista de blocos
	File *Arquivo;
	int i=0,c=0,j=0;
	char *vet=(char *) malloc((strlen(*nome_arquivo)+10)*(sizeof(char)));
	index *indices,troca;
	Arquivo=fopen(**nome_arquivo,'rb');
	if(Arquivo == NULL){
		puts("ERRO! Arquivo");
		return 0;
	}
    dados = pegarlista();
    fclose(Arquivo);
    aux=dados;    
    while(aux!= NULL){
          c++;
    	/*aux = dados;
        anterior = dados;
    	while(aux!=NULL ){
    		aux2 = aux->prox;
    		if(aux->lista->bloco->idgeral >(aux2)->lista->bloco->idgeral){
    			aux->prox = aux2 ->prox;
    			aux2->prox = aux;
    			anterior -> aux2;
    		}
    		aux = aux->prox;
    		aux2 =aux2->prox;
    		anterior = anterior->prox;
    	}
    	dados= dados->prox;
        */
    }
    indices = malloc(c*(sizeof(indices)));
    aux=dados;
    while(aux!=NULL){
    	indices[i].id = aux->lista->bloco->idgeral;
    	indices[i].ed = i++;
    	i++;
    	aux = aux->prox;
    }
    for(i = 0; i<c; i++){
		for(j = 0; j<c-1; j++){
			if(indices[j],id > indices[j + 1].id){
				troca.id = indices[j].id;
				troca.ed = indices[j].ed;
				indices[j].id = indices[j+1].id;
				indices[j].ed = indices[j+1].ed;
				indices[j+1].id = troca.id;
				indices[j+1].ed =troca.ed;
			}
		}
	}
    vet=strcopy(*nome_arquivo,"index.bin");
    Arquivo = fopen(vet,'wb');
    if(Arquivo == NULL){
		puts("ERRO! Arquivo");
		return 0;
	}
	for(i=0;i<c;i++)
		fwrite(indices[i],sizeof(int),sizeof(index),Arquivo);
	fclose(Arquivo);
}
