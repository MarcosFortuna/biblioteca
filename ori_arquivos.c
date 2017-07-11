#include <stdio.h>
#include <stdlib.h>


void fecharArquivo(File **arquivo){
      fclose(*arquivo);
      **arquivo= NULL;
}

void abrirArquivo(File **arquivo, char modo, const char *nome_arquivo){
     switch(modo){
         case'L': {*arquivo =fopen(nome_arquivo,rb); // l para leitura
                     if(*arquivo){
                        printf("!ERRO, Arquivo não foi aberto);
                        exit(-1);
                     }
                     break;}
         case'E': {*arquivo = fopen(nome_arquivo,wb); // somente escrita
                     if(*arquivo){
                        printf("!ERRO, Arquivo não foi aberto);
                        exit(-1); 
                     }
                     break;}       
         case'A': {*arquivo = fopen(nome_arquivo,ab); // Ambos: leitura e escrita
                     if(*arquivo){
                        printf("!ERRO, Arquivo não foi aberto);
                        exit(-1); 
                     }
                     break;}
         }                  
}          
