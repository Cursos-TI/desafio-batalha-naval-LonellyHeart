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
    int linhaH, colunaH, linhaV, colunaV, diagonalLinha1, diagonalLinha2, diagonalColuna1, diagonalColuna2; //Declaração das variaveis que vão controlar a inclusão dos navios
    int habilidade; // A habilidade que sera usada 1 - cone, 2 - cruz, 3 - Octaedro
    int centroLinha = 5, centroColuna = 2; // A coordernada principal, da onde a habilidade sera iniciada, sendo criada como matriz, com os dois pontos LINHA e COLUNA

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
    diagonalLinha1 = 0, diagonalColuna1 = 7; // Essas Coodernadas vão controlar a inclusão do navio na diagonal principal;
    diagonalLinha2 = 7, diagonalColuna2 = 8;// Essas Coodernadas vão controlar a inclusão do navio na diagonal secundaria;

    // Controle de erro, para caso, o valor dado no campos, irão sobrepor a matriz dada, ou seja, o navio não cabe no espaço que foi dado a ele
    if((colunaH + 3 > 10) || (linhaV + 3 > 10) || diagonalLinha1 + 3 > 10 || diagonalLinha2 + 3 > 10 || (diagonalColuna1 + 3 > 10) || (diagonalColuna2 - 3 < 0)){
        printf("\nO Navio não cabe no espaço que foi alocado para ele, altere as posições e tente novamente\n");
        return 0;
    }



    for(int i = 0; i < 3; i++){
        if(tabuleiro[linhaH][colunaH+i] == 0){  // inclusão do navio horizontal
            tabuleiro[linhaH][colunaH + i] = navHorizontal[i];
        }
            else{ // Mensagem de erro, para caso tente colocar o navio, para o caso de ja ter um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;
            }

        if(tabuleiro[linhaV+i][colunaV] == 0){  // inclusão do navio horizontal
            tabuleiro[linhaV+i][colunaV] = navVertical[i];
        }
            else{ // Mensagem de erro, para caso tente colocar o navio, para o caso de ja ter um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;
            }
        if(tabuleiro[diagonalLinha1+i][diagonalColuna1+i] == 0){ // Inclusão do navio da diagonal primaria
                tabuleiro[diagonalLinha1+i][diagonalColuna1+i] = navDiagonal[i];
            }
            else{ // Mensagem de erro, para caso tente colocar o navio, para o caso de ja ter um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;                
            }
        if(tabuleiro[diagonalLinha2+i][diagonalColuna2-i] == 0 ){ // Inclusão do navio da diagonal secundaria
            tabuleiro[diagonalLinha2+i][diagonalColuna2-i] = navDiagonal[i];
        }
            else{ // Mensagem de erro, para caso tente colocar o navio, para o caso de ja ter um navio
                printf("\nEsta havendo uma sobreposição dos navios, corriga e rode o progama novamente...\n");
                printf("Fechando..\n");
                return 0;                
            }
    }

    //MOSTRANDO O TABULEIRO ATUALIZADO COM OS NAVIOS (SEM HABILIDADES)
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

    habilidade = 3; // esse ponto é só para inserir qual habilidade sera usada, poderia ser no começo do codigo, diretamente na iniciliazação, mas preferir deixar nessa parte.
    //              1 - cone, 2 - cruz, 3 - Octaedro
    // as areas afetadas pela habilidade ficarão com o numero 5, e os navios atigindos ficarão com o numero 8
    switch(habilidade){

        // CASE 1 é referente ao Cone
        case 1:
            for(int i = 0; i <= 4; i++){ // controla a "altura" do cone (linhas abaixo do centro)

                // largura cresce conforme i aumenta
                for(int j = -i; j <= i; j++){

                    int novaLinha = centroLinha + i;
                    int novaColuna = centroColuna + j;

                    // Garante que não saia do tabuleiro
                    if(novaLinha >= 0 && novaLinha < 10 && novaColuna >= 0 && novaColuna < 10){

                        if(tabuleiro[novaLinha][novaColuna] == 3){
                            tabuleiro[novaLinha][novaColuna] = 8; // Se já existe um navio (3), marca como atingido (8)
                        } 
                        else {
                            tabuleiro[novaLinha][novaColuna] = 5; // Senão, é somente uma água atingidade (5).
                        }
                    }
                }
            }
            break;


        // CASE 1 é referente à CRUZ
        case 2:

            // Parte vertical da cruz
            for(int i = -3; i <= 3; i++){
                int novaLinha = centroLinha + i;
                int novaColuna = centroColuna;

                // Verifica limites do tabuleiro
                if(novaLinha >= 0 && novaLinha < 10){

                    if(tabuleiro[novaLinha][novaColuna] == 3){
                        tabuleiro[novaLinha][novaColuna] = 8; // Se já existe um navio (3), marca como atingido (8)
                    } else {
                        tabuleiro[novaLinha][novaColuna] = 5; // Senão, é somente uma água atingidade (5).
                    }
                }
            }

            // Parte horizontal da cruz
            for(int j = -3; j <= 3; j++){
                int novaLinha = centroLinha;
                int novaColuna = centroColuna + j;

                // Verifica limites do tabuleiro
                if(novaColuna >= 0 && novaColuna < 10){

                    if(tabuleiro[novaLinha][novaColuna] == 3){
                        tabuleiro[novaLinha][novaColuna] = 8; // Se já existe um navio (3), marca como atingido (8)
                    } else {
                        tabuleiro[novaLinha][novaColuna] = 5; // Senão, é somente uma água atingidade (5).
                    }
                }
            }
            break;


        // CASE 3 é referente ao Octaedro
        case 3: {

            int raio = 2; // Esse é o valor que deve ser alterado, para um octaedro maior

            for(int i = -raio; i <= raio; i++){
                for(int j = -raio; j <= raio; j++){

                    // controle do aumento do octaedro
                    if( (i + j <= raio) && (i + j >= -raio) &&
                        (i - j <= raio) && (i - j >= -raio) ){

                        int novaLinha = centroLinha + i;
                        int novaColuna = centroColuna + j;

                        // Verifica limites do tabuleiro
                        if(novaLinha >= 0 && novaLinha < 10 && novaColuna >= 0 && novaColuna < 10){

                            if(tabuleiro[novaLinha][novaColuna] == 3){
                                tabuleiro[novaLinha][novaColuna] = 8; // Se já existe um navio (3), marca como atingido (8)
                            } else {
                                tabuleiro[novaLinha][novaColuna] = 5; // Senão, é somente uma água atingidade (5).
                            }
                        }
                    }
                }
            }

            break;
        }

        // No caso não é usuario que ira inserir o valor, então é pouco provavel de dar erro, mas vou incluir o default    
        default:
            printf("\nHabilidade inválida!\n");
            break;
    }

        //MOSTRANDO O TABULEIRO ATUALIZADO COM OS NAVIOS (COM HABILIDADES)
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
