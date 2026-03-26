#include <stdio.h>

// Incluindo um define para ter os valroes de linhas e colunas de forma global
#define LINHAS 10
#define COLUNAS 10


int main(){
    char cabecalhoSuperior[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Na parte superior das colunas, ficara as letras, para facilitar que coluna esta olhando
    char cabecalhoLateral[COLUNAS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Na parte esquerda das linhas, ficara os numeros, para facilitar que linha esta olhando
    int tabuleiro[LINHAS][COLUNAS]; // Criação do tabuleiro
    int navHorizontal[3] = {3,3,3}, navVertical[3] = {3,3,3}, navDiagonal[3] = {3,3,3}; // Criação dos navios
    int index = 0; // Para mostrar as colunas antes do codigo de FOR
    int linhaH, colunaH, linhaV, colunaV, diagonal1, diagonal2; //Declaração das variaveis que vão controlar a inclusão dos navios

    //CRIANDO O TABULEIRO, COLOCANDO TODOS OS VALORES DA MATRIZ COMO 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //MOSTRANDO O TABULEIRO ZERADO
    printf("##########   TABULEIRO DA BATALHA NAVAL   ##########\n\t"); // Texto de apresentação
    do{
        printf("%c\t", cabecalhoSuperior[index++]); // Imprimindo toda a Array colunas, para que fique na parte superior do código, utilizando o (index++) ele faz o incremento após mostrar o valor para seguir o looping
    } while(index < 10);
    
    index = 0;


    for(int i = 0; i < 10; i++){ // Mostrando agora o tabuleiro de fato
        printf("\n%c\t" ,cabecalhoLateral[i]); // No inicio da tabela vai mostrar o numero da linha "0-9"
        for(int j = 0; j < 10; j++){
            printf("%d\t" ,tabuleiro[i][j]); // Aqui que vai ser mostrado os valores que estão dentro do tabuleiro, nesse caso, vazio
        }
    }

    //COLOCANDO OS NAVIOS
    linhaH = 5, colunaH = 0; // Essas coodernadas vão controlar a inclusão do navio da Horizontal (Vertical fixa, Coluna Variavel)
    linhaV = 7, colunaV = 9; // Essas coodernadas vão controlar a inclusão do navio da Vertical (Vertical Variavel, Coluna Fixa)
    diagonal1 = 0; // Essas Coodernadas vão controlar a inclusão do navio na diagonal principal;
    diagonal2 = 7;// Essas Coodernadas vão controlar a inclusão do navio na diagonal secundaria;

    // Controle de erro, para caso, o valor dado no campos, irão sobrepor a matriz dada, ou seja, o navio não cabe no espaço que foi dado a ele
    if((colunaH + 3 > 10) || (linhaV + 3 > 10) || diagonal1 + 3 > 10 || diagonal2 + 3 > 10 ){
        printf("\nO Navio não cabe no espaço que foi alocado para ele, altere as posições e tente novamente\n");
        return 0;
    }



    for(int i = 0; i < 3; i++){
        if(tabuleiro[linhaH][colunaH+i] == 0){  // inclusão do navio horizontal
            tabuleiro[linhaH][colunaH + i] = navHorizontal[i];
        }
            else{ // Mensagem de erro, para caso tente colocar o navio, onde ja tem um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;
            }

        if(tabuleiro[linhaV+i][colunaV] == 0){  // inclusão do navio horizontal
            tabuleiro[linhaV+i][colunaV] = navVertical[i];
        }
            else{ // Mensagem de erro, para caso tente colocar o navio, onde ja tem um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;
            }
        if(tabuleiro[diagonal1+i][diagonal1+i] == 0){ // Inclusão do navio da diagonal primaria
                tabuleiro[diagonal1+i][diagonal1+i] = navDiagonal[i];
            }
            else{ // Mensagem de erro, para caso tente colocar o navio, onde ja tem um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;                
            }
        if(tabuleiro[diagonal2+i][(COLUNAS-1)-diagonal2-i] == 0 ){ // Inclusão do navio da diagonal secundaria
            tabuleiro[diagonal2+i][(COLUNAS-1)-diagonal2-i] = navDiagonal[i];
        }
            else{ // Mensagem de erro, para caso tente colocar o navio, onde ja tem um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;                
            } 
    }

    //MOSTRANDO O TABULEIRO ATUALIZADO COM OS NAVIOS
    printf("\n##########   TABULEIRO DA BATALHA NAVAL   ##########\n\t"); // Texto de apresentação
    do{
        printf("%c\t", cabecalhoSuperior[index++]); // Imprimindo toda a Array colunas, para que fique na parte superior do código, utilizando o (index++) ele faz o incremento após mostrar o valor para seguir o looping
    } while(index < 10); 


    for(int i = 0; i < 10; i++){ // Mostrando agora o tabuleiro de fato
        printf("\n%c\t" ,cabecalhoLateral[i]); // No inicio da tabela vai mostrar o numero da linha "0-9"
        for(int j = 0; j < 10; j++){
            printf("%d\t" ,tabuleiro[i][j]); // Aqui que vai ser mostrado os valores que estão dentro do tabuleiro, nesse caso, vazio
        }
    }

    return 0;
}
