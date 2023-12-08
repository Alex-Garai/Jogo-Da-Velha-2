#include <stdio.h>

//Projeto Jogo Da Velha 2.
//Trabalho para faculdade de Ciencias da Computação PUC-GO.
//Realizado por Alexandre Lopes.


//Registro do jogo da velha, ele armazena os 9 tabuleiros e o jogador que ganhou o Jogo.
struct JogoDaVelha 
{
    char Ganhador;
    char tabuleiro[9];
};


//Inicializando o tabuleiro
void inicializarTabuleiro(struct JogoDaVelha *jogo) {
    int i;
    for (i = 0; i < 9; i++) {
        jogo->tabuleiro[i] = ' ';
    }
}


//Imprimindo todos os tabuleiros
void imprimirTabuleiros(const struct JogoDaVelha *jogos) {
    for (int i = 0; i < 9; i++) {
        
            printf("Jogo %d:\n", i + 1);
            printf("0 1 2\n");
            printf("\n");
            for (int j = 0; j < 9; j++) {
                printf("%c", jogos[i].tabuleiro[j]);
                if (j % 3 == 2) {
                    printf("\n");
                    if (j < 8) {
                    printf("------\n");
                    }
                } else {
                printf("|");
                }
            }
        printf("\n\n");
    }
}


//Verificação do Ganhador
int verificarVencedor(const struct JogoDaVelha *jogo, int indice, char jogador) {
    if ((jogo[indice].tabuleiro[0] == jogador && jogo[indice].tabuleiro[1] == jogador && jogo[indice].tabuleiro[2] == jogador) ||
        (jogo[indice].tabuleiro[3] == jogador && jogo[indice].tabuleiro[4] == jogador && jogo[indice].tabuleiro[5] == jogador) ||
        (jogo[indice].tabuleiro[6] == jogador && jogo[indice].tabuleiro[7] == jogador && jogo[indice].tabuleiro[8] == jogador) ||
        (jogo[indice].tabuleiro[0] == jogador && jogo[indice].tabuleiro[3] == jogador && jogo[indice].tabuleiro[6] == jogador) ||
        (jogo[indice].tabuleiro[1] == jogador && jogo[indice].tabuleiro[4] == jogador && jogo[indice].tabuleiro[7] == jogador) ||
        (jogo[indice].tabuleiro[2] == jogador && jogo[indice].tabuleiro[5] == jogador && jogo[indice].tabuleiro[8] == jogador) ||
        (jogo[indice].tabuleiro[0] == jogador && jogo[indice].tabuleiro[4] == jogador && jogo[indice].tabuleiro[8] == jogador) ||
        (jogo[indice].tabuleiro[2] == jogador && jogo[indice].tabuleiro[4] == jogador && jogo[indice].tabuleiro[6] == jogador)) {
        return 1;
    }

    return 0;
}

int main() {
    struct JogoDaVelha jogos[9];
    int posicao, jogoAtual;
    char jogador = 'X';
    
    //Regras e Intrusções do Jogo para o jogador
    printf("Bem vindo ao Jogo Da Velha 2!!! \n");
    printf("O jogo consiste em 9 jogos da velha ocorrendo simultaneamente entre dois jogadores. \n");
    printf("O jogador que ganhar um dos 9 jogos da velha primeiro, ganha o Jogo Da Velha 2! Boa Sorte. \n");
    printf("\n");
    printf("\n");

    //Inicialização dos tabuleiros
    for (int i = 0; i < 9; i++) 
    {
        inicializarTabuleiro(&jogos[i]);
    }

    //Loop principal do jogo
    while (1) {
        //Imprimir todos os tabuleiros
        imprimirTabuleiros(jogos);
        
        //Solicitar o jogo desejado
        printf("Jogador %c, escolha o jogo (1 a 9): ", jogador);
        scanf("%d", &jogoAtual);
        jogoAtual--; // Ajusta para índice do vetor
        
        //Verificar se o índice do jogo é válido
        if (jogoAtual < 0 || jogoAtual >= 9) {
            printf("Jogo invalido. Tente novamente.\n");
            continue;
        }
        
        //Solicitar a jogada do jogador
        printf("Jogador %c, informe a posicao desejada, de 0 até 8: ", jogador);
        scanf("%d", &posicao);
        
        //Verificar se a posição está válida
        if (posicao >= 0 && posicao < 9 && jogos[jogoAtual].tabuleiro[posicao] == ' ') {
            // Atualizar o tabuleiro com a jogada do jogador
            jogos[jogoAtual].tabuleiro[posicao] = jogador;
            
            // Verificar se o jogador venceu
            if (verificarVencedor(jogos, jogoAtual, jogador)) {
                // Imprimir todos os tabuleiros Novamente
                imprimirTabuleiros(jogos);
                jogos[jogoAtual].Ganhador = jogador;
                printf("Jogador %c venceu no Jogo %d!\n", jogos[jogoAtual].Ganhador);
                break; // Terminar o jogo
            }
            
            //Trocar para o próximo jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Posicao invalida. Tente novamente.\n");
        }
    }
    return 0;
}
