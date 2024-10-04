#include <iostream>
#include <cctype>

void verificarDisponibilidade(char reserva[10][6], int fileira, int assento, char tipoPassagem) {
    if(tipoPassagem == 'e' && (assento == 0 || assento ==5)) {
        printf("\nAssentos nas fileiras A e F são exclusivos para passagens executivas. Escolha outro assento.");
        return;
    }
    
    if (reserva[fileira - 1][assento] == 'x') {
        printf("\nAssento indisponível, por favor, escolha outro.");
    } else {
        reserva[fileira - 1][assento] = 'x'; // Reserva o assento
        printf("\nAssento reservado com sucesso!");
    }
}

bool boasVindas() {
    char resposta;
    printf("\t==============Ga Airways - FlySafe==============\n");
    printf("Bem-vindo! Este é o sistema de reserva de assentos.\n");
    printf("\t==Legenda do sistema==\n");
    printf("\tDigite S para Sim e N para Não.\n");
    printf("\tDigite E para escolher a classe econômica e X para escolher classe executiva!\n");
    printf("\nDeseja começar a reservar assentos? (s/n): ");
    scanf(" %c", &resposta);

    return (resposta == 's' || resposta == 'S');
}

void visualizarAssentos(char reserva[10][6]) {
    printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
    for (int x = 0; x < 10; x++) {
        if (x != 9) printf("\n\t0%d\t", x + 1);
        else printf("\n\t%d\t", x + 1);
        
        for (int y = 0; y < 6; y++) {
            printf("[%c] ", reserva[x][y]);
            if (y == 2) {
                printf("\t");
            }
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char reserva[10][6] = {
        {'x', ' ', ' ', ' ', ' ', ' '}, // Assento A na fileira 1 já reservado
        {' ', 'x', ' ', 'x', ' ', ' '}, // Assento B e D na fileira 2 já reservado
        {' ', ' ', ' ', 'x', ' ', ' '},
        {'x', ' ', ' ', ' ', ' ', ' '}, // Assento A na fileira 4 já reservado
        {' ', ' ', ' ', ' ', ' ', 'x'}, // Assento F na fileira 6 já reservado
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'x', ' ', ' ', ' ', ' '}, // Assento B na fileira 7 já reservado
        {' ', ' ', ' ', ' ', ' ', ' '},
        {'x', ' ', ' ', ' ', ' ', ' '}, // Assento A na fileira 9 já reservado
        {' ', ' ', ' ', ' ', 'x', 'x'}  // Assento E e F na fileira 10 já reservado
    };
    
    if (!boasVindas()) {
        printf("\nObrigado por sua visita! Até a próxima!");
        return 0;
    }

    char visualizar;
    printf("\nDeseja visualizar os assentos disponíveis? (s/n): ");
    scanf(" %c", &visualizar);

    if (visualizar == 's' || visualizar == 'S') {
        visualizarAssentos(reserva);
    }

    int fileira;
    char poltrona;
    char tipoPassagem;

    while (true) {
        printf("\nSelecione o tipo de passagem (E para econômica, X para executiva): ");
        scanf(" %c", &tipoPassagem);
        tipoPassagem = tolower(tipoPassagem);
        
        if (tipoPassagem != 'e' && tipoPassagem != 'x') {
            printf("\nTipo de passagem inválido. Tente novamente.");
            continue;
        }
        
        printf("\nDigite a fileira (1-10): ");
        scanf("%d", &fileira);
        printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
        scanf(" %c", &poltrona);
        
        int assento = -1;
        
        poltrona = tolower(poltrona);
        
        switch(poltrona) {
            case 'a': assento = 0; break;
            case 'b': assento = 1; break;
            case 'c': assento = 2; break;
            case 'd': assento = 3; break;
            case 'e': assento = 4; break;
            case 'f': assento = 5; break;
            default:
                printf("\nPoltrona inválida. Tente novamente.");
                continue;
        }

        verificarDisponibilidade(reserva, fileira, assento, tipoPassagem);

        // Exibe a matriz de reservas após a reserva
        printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
        for (int x = 0; x < 10; x++) {
            if (x != 9) printf("\n\t0%d\t", x + 1);
            else printf("\n\t%d\t", x + 1);
            
            for (int y = 0; y < 6; y++) {
                printf("[%c] ", reserva[x][y]);
                if (y == 2) {
                    printf("\t");
                }
            }
        }
        printf("\n");

        // Pergunta se o usuário deseja escolher mais um assento
        char continuar;
        printf("\nDeseja escolher mais um assento? (s/n): ");
        scanf(" %c", &continuar);
        
        if (continuar == 'n' || continuar == 'N') {
            printf("\nObrigado pela preferência!");
            break; // Sai do loop e encerra o programa
        }
    }
    return 0;
}
