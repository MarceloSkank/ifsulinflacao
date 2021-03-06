#include "inflacao.h"

float maxData[2023];


void readfile() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("data.txt", "r");
    if (fp == NULL)
        exit(0);

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, ";");
        int ano = atoi(token);

        token = strtok(NULL, ";");
        float valor = atof(token);

        maxData[ano] = valor;

    }


    fclose(fp);
    if (line)
        free(line);
}

float calculateInflation(int anoInicial, int anoFinal) {
    float inflacao = 0;
    
    inflacao = ((maxData[anoFinal] - maxData[anoInicial]) / maxData[anoInicial]);

    printf("Inflacao: %f\n", inflacao);
    return inflacao;
}


float calculaPreco(float preco, int anoFinal, int anoInicial) {

    return (preco * (calculateInflation(anoFinal, anoInicial))) + preco;
}