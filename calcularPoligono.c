#include <stdio.h>
#include <math.h>
//math.h só para utilizar a funcao fabs()

struct ponto
{
    float x;
    float y;
};

float areaTriangulo(struct ponto pontoA, struct ponto pontoB, struct ponto pontoC) {
    //calcula a area do trangulo especifico
    return  0.5 * ((pontoA.x * (pontoB.y - pontoC.y)) + (pontoB.x * (pontoC.y - pontoA.y)) + (pontoC.x * (pontoA.y - pontoB.y)));;
}

float calcularArea(FILE *fr) {
    //Define a variavel do calculo final da area (area Total)
    float areaT = 0;

    //Caso não consiga ler o arquivo informa o usuario e sai da função retornando codigo 2
    if (fr == NULL)
    {
        printf("problema ao ler arquivo");
        return 2;
    }

    //Define a variavel onde sera armazenada a quantidade de pontos informada no arquivo de entrada
    int quantidade;

    //Lê o arquivo de entrada para definir a quantidade de pontos 
    fscanf(fr, "%d", &quantidade);

    //Se a quantidade de pontos for menor que 3 (poligono impossivel) informa o usuario e sai da funcao
    if (quantidade < 3)
    {
        printf("A quantiade de vertices é menor que 3, impossibilitando o calculo");
        return 1;
    }

    //Caso dê tudo certo, lê linha por lionha armazenando cada ponto em uma struct
    else {

        //casos de teste
        /* printf("%d\n", quantidade); */

        //define uma quantidade ""dinamica"" de structs baseada na quantidade informada
        struct ponto pontos[quantidade];
        for (int i = 0; i < quantidade; i++)
        {
            fscanf(fr, "%f", &pontos[i].x);
            fscanf(fr, "%f", &pontos[i].y);
            //printf usado para casos de teste
            /* printf("%f  %f\n", pontos[i].x, pontos[i].y); */
        }

        //Separa o poligono em varios triangulos mandando-os cada vez para a funcao para calcular a area e adicionando o calculo na area total do poligono 
        for (int i = 1; i < quantidade - 1; i++)
        {
            areaT += areaTriangulo(pontos[0], pontos[i], pontos[i+1]);
        }
        return areaT;
    }
}


 
int main()
{   
    FILE *fr;
    fr = fopen("DadosEntrada.txt", "r");
    rewind(fr);
    printf("A area do poligono eh %.3f", fabs(calcularArea(fr))); 
    return 0;
}

