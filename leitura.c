/*
    Esse código recebe um arquivo da B3 contendo a lista de todos os instrumentos negociados
    (acessavel em   www.b3.com.br/pt_br/market-data-e-indices/servicos-de-dados/market-data/historico/mercado-a-vista/series-historicas/)
    e devolve um arquivo "Bolsa.csv" com informações do Código, Tipo, NomeResumido, Preço de Fechamento, Quantidade, Preço de Exercicio e Vencimento de cada ativo
    
    O código funciona lendo o arquivo linha por linha e atribuindo os valores com base na sua posição no texto
    
    EXEMPLO:
    O input:
        012022050502A1AP34      010ADVANCE AUTODRN          R$  000000000634200000000063570000000006342000000000634600000000063570000000000000000000000000000003000000000000000004000000000000025385000000000000009999123100000010000000000000BRA1APBDR001110
    Retorna:    
        A1AP34; VISTA; ADVANCE AUTO; 63,57; 4; 0,00; 99991231
    
    
    código escrito por www.github.com/GabrielLima60
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

struct _dados {
    char Codigo[13];
    char Tipo[6];
    char NomeResumido[13];
    char Fechamento[12];
    char FechamentoDEC[3];
    char Quantidade[19];
    char PrecoExercicio[12];
    char PrecoExercicioDEC[3];
    char Vencimento[9];
};


void gravarArquivo(struct _dados dados){                           

    FILE *gravar = fopen("Bolsa.csv","a");
    
    int Quantidade = atoi(dados.Quantidade);
    
    int Fechamento = atoi(dados.Fechamento);
    int FechamentoDEC = (atoi(dados.FechamentoDEC)); 
    int PrecoExercicio = atoi(dados.PrecoExercicio);
    int PrecoExercicioDEC = (atof(dados.PrecoExercicioDEC));
    
    fprintf(gravar, "%s;", dados.Codigo);
    fprintf(gravar, " %s;", dados.Tipo);    
    fprintf(gravar, " %s;", dados.NomeResumido);
    fprintf(gravar, " %i,", Fechamento);
    fprintf(gravar, "%02d;", FechamentoDEC);
    fprintf(gravar, " %i;", Quantidade);
    fprintf(gravar, " %i,", PrecoExercicio);
    fprintf(gravar, "%02d;", PrecoExercicioDEC);
    fprintf(gravar, " %s\n\n", dados.Vencimento);
    
    fclose(gravar);
}

void atribuirDados(char linha[247]){
    
    struct _dados dados;
        
    char TipoMercado[4];
            
    strncpy(dados.Codigo, &linha[12], 12);
        dados.Codigo[12] = '\0';
        for (int indice = 11; indice > 0; indice--){
            if (dados.Codigo[indice] == ' '){
                
            }
            else{
                dados.Codigo[indice +1] = '\0';
                break;
            }
        }    
    strncpy(TipoMercado, &linha[24], 3);
        TipoMercado[3] = '\0';
        
    strncpy(dados.NomeResumido, &linha[27], 12);
        dados.NomeResumido[12] = '\0';
        for (int indice = 11; indice > 0; indice--){
            if (dados.NomeResumido[indice] == ' '){
                
            }
            else{
                dados.NomeResumido[indice +1] = '\0';
                break;
            }
        }    
    strncpy(dados.Fechamento, &linha[109], 10);
        dados.Fechamento[10] = '\0';
        
    strncpy(dados.FechamentoDEC, &linha[119], 2);
        dados.FechamentoDEC[2] = '\0';
        
    strncpy(dados.Quantidade, &linha[152], 18);
        dados.Quantidade[18] = '\0';
        
    strncpy(dados.PrecoExercicio, &linha[188], 10);
        dados.PrecoExercicio[10] = '\0';
        
    strncpy(dados.PrecoExercicioDEC, &linha[198], 2);
        dados.PrecoExercicioDEC[2] = '\0'; 
        
    strncpy(dados.Vencimento, &linha[202], 8);
        dados.Vencimento[8] = '\0';


    if (strcmp(TipoMercado, "010") == 0)
        strcpy(dados.Tipo, "VISTA");

    else if (strcmp(TipoMercado, "020") == 0)
        strcpy(dados.Tipo, "FRAC");

    else if (strcmp(TipoMercado, "070") == 0)
        strcpy(dados.Tipo, "CALL");

    else if (strcmp(TipoMercado, "080") == 0)
        strcpy(dados.Tipo, "PUT");

    dados.Tipo[5] = '\0';
    
    
    if (strstr(dados.Codigo,"BOVESPA")) {
        
    }
        
    else {
        gravarArquivo(dados);
    }
}



int main(int argc, char **argv) {
    
    FILE *myFile = fopen(argv[1],"r");             

    char character = '\0';
    char linha[247];

    while (!feof(myFile)) { 

        for (int position = 0; position < 246; position++) {        
            fscanf(myFile, "%c", &character);
            if(character != '\n')
                linha[position] = character;
            else
                linha[position] = '\0';
        }
        
        atribuirDados(linha);
    }
    fclose(myFile);
}


