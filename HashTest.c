#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"

typedef struct Palavra {
    char p[30];
}Palavra;

bool comparaChaves(void *key, void *data) {
    log_trace("Entrando em comparaChaves");
    char *chave = (char*)key;
    log_debug("chave: %s", chave);
    Palavra *c = (Palavra*)data;
    log_debug("cliente c: %p", c);
    //log_debug("c->nome: %s", c->nome);
    //log_debug("c->email: %s", c->email);
    //log_debug("%s == %s: %d", chave, c->email, strcmp (chave, c->email));
    log_trace("Saindo de comparaChaves");
    
    return (strcmp (chave, c->p) == 0)?true:false;
}

void printCliente(void *data) {
    Palavra *cliente = (Palavra*)data;
    printf("  %s", cliente->p);
}

int main() {
	FILE *arq;
    arq = fopen("ListaDePalavrasPT.txt", "rt");
    if (arq == NULL)printf("Problemas na CRIACAO do arquivo\n");
    // Read contents from file
    /*
	char texto = fgetc(arq);
    while (texto != EOF)
    {
        printf ("%c", texto);
        texto = fgetc(arq);
    }*/
	
	//printf("%s",arq);
	
	
	log_set_level(LOG_WARN);
    HashStruct hashes;
    initHash(&hashes);
    
	
	
 	//Palavra *cliente = (Palavra*)get(&hashes, c->p, comparaChaves);
 	
	char linha[30];
    while(fgets(linha, sizeof(linha), arq) != NULL) {
    	/* note como não precisamos especificar uma nova linha, o fgets já a inclui na string linha quando a encontra */
        //printf("%s", linha);
        Palavra *c = (Palavra *)malloc(sizeof(Palavra));
    	strcpy(c->p, linha);
    	put(&hashes, c->p, c, comparaChaves);
	}
    /*
 	FILE *pixel;
    pixel = fopen("Pix.txt", "wt");
	if (pixel == NULL)printf("Problemas na CRIACAO do arquivo\n");
    fputs(pixel)
    */
    
    
    //c = (Cliente *)malloc(sizeof(Cliente));
    //strcpy(c->nome,"Maria") ;
    //put(&hashes, c->email, c, comparaChaves);
    
    //c = (Cliente *)malloc(sizeof(Cliente));
    //strcpy(c->nome,"Pedro") ;
    //put(&hashes, c->email, c, comparaChaves);
    
    //c = (Cliente *)malloc(sizeof(Cliente));
    //strcpy(c->nome,"Carla") ;
    //put(&hashes, c->email, c, comparaChaves);
       
    showHashStruct(&hashes, printCliente);
    return 0;
}
