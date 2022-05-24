#include <stdio.h>
#include <stdlib.h>

void inicio(){
    system("cls");
    printf("Jogo da Velha\n");
    printf("\n");
    printf("1. Jogar\n");
    printf("2. Ver Ranking\n");
    printf("3. Ver Creditos\n");
    printf("4. Sair\n");
    printf("\n");
    printf("Escolha uma opcao: ");
}

void mododejogo(){
    system("cls");
    printf("Escolha um modo de jogo\n");
    printf("\n");
    printf("1. Dois jogadores\n");
    printf("2. Jogador x Computador\n");
    printf("\n");
    printf("Escolha uma opcao: ");
}

void tabuleiro(char casas2[3][3]){
    system("cls");
    printf("%c | %c | %c\n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", casas2[2][0], casas2[2][1], casas2[2][2]);
}

int main(void){
    bool r = true;
    FILE *file; //Ranking

    struct ranking{
        int jogador_x;
        int jogador_o;
        int velha_mp;
        int jogador;
        int computador;
        int velha_jc;
    };

    struct ranking rank;
    rank.jogador_o = 0;
    rank.jogador_x = 0;
    rank.velha_mp = 0;
    rank.jogador = 0;
    rank.computador = 0;
    rank.velha_jc = 0;

    while (r == true){
        file = fopen("rank.txt", "w");
        fprintf(file,"Ranking\n\nModo Multiplayer:\n- Jogador X: %d\n- Jogador O: %d\n- Velha: %d\n\nModo Jogador x Computador\n- Jogador: %d\n- Computador: %d\n- Velha: %d", rank.jogador_x, rank.jogador_o, rank.velha_mp, rank.jogador, rank.computador, rank.velha_jc);
        fclose(file);

        int escolha, modo;

        inicio();
        scanf("%d", &escolha);
        printf("%d", escolha);
        
        if(escolha==1){
            /* Jogar */
            mododejogo();
            scanf("%d", &modo);
            printf("%d", modo);
            if(modo==1){
                /* Modo Multiplayer */
                char casas[3][3] = {
                    {'1','2','3'},
                    {'3','2','1'},
                    {'1','2','3'}};

                char res;
                int cont_jogadas, l, c, i, j;
                int vez = 0;

                do{
                    cont_jogadas = 1;
                    for (i = 0; i <= 2; i++){
                        for (j = 0; j <= 2; j++){
                            casas[i][j] = ' ';
                        }
                        
                    }
                    
                    do{
                        tabuleiro(casas);
                        if(vez%2==0){
                            printf("Jogador X\n");
                        }else{
                            printf("Jogador O\n");
                        }
                        
                        printf("Digite a linha: ");
                        scanf("%d", &l);
                        printf("Digite a coluna: ");
                        scanf("%d", &c);
                        if (l<1 || c<1 || l>3 || c>3){
                            l=0;
                            c=0;
                        }else if(casas[l-1][c-1] != ' '){
                            l=0;
                            c=0;
                        }else{
                            if(vez%2==0){
                                casas[l-1][c-1] = 'X';
                            }else{
                                casas[l-1][c-1] = 'O';
                            }
                            vez++;
                            cont_jogadas++;
                        }
                        
                        if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){
                            cont_jogadas = 11;
                        }

                        if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){
                            cont_jogadas = 13;
                        }
                        
                    }while (cont_jogadas<=9);
                    tabuleiro(casas);
                    if(cont_jogadas==10){
                        printf("O jogo deu velha, ninguem ganhou\n");
                        rank.velha_mp++;
                    }
                    if(cont_jogadas==11){
                        printf("O jogador X ganhou\n");
                        rank.jogador_x++;
                    }
                    if(cont_jogadas==13){
                        printf("O jogador O ganhou\n");
                        rank.jogador_o++;
                    }
                    printf("Deseja jogar dnv? [S-N]\n");
                    scanf("%s", &res);
                }while(res=='s');
            }
            if(modo==2){
                /* Modo Jogador x Comppuador */
                char casas[3][3] = {
                    {'1','2','3'},
                    {'3','2','1'},
                    {'1','2','3'}};

                char res;
                int cont_jogadas, l, c, i, j, s;
                int vez = 0;

                do{
                    cont_jogadas = 1;
                    for (i = 0; i <= 2; i++){
                        for (j = 0; j <= 2; j++){
                            casas[i][j] = ' ';
                        }
                        
                    }
                    
                    do{
                        tabuleiro(casas);
                        if(vez%2==0){
                            printf("Jogador X\n");
                            printf("Digite a linha: ");
                            scanf("%d", &l);
                            printf("Digite a coluna: ");
                            scanf("%d", &c);
                        }else{
                            printf("Jogador O\n");
                            s = (rand() % 2)+(1);
                            if(s==1){
                                l = (rand() % 3)+(1);
                                c = (rand() % 3)+(1);
                            }else{
                                if(casas[0][0] == 'X' || casas[0][1] == 'X'){
                                    l = 0;
                                    c = 2;
                                }
                                if(casas[1][0] == 'X' || casas[1][1] == 'X'){
                                    l = 1;
                                    c = 2;
                                }
                                if(casas[2][0] == 'X' || casas[2][1] == 'X'){
                                    l = 2;
                                    c = 2;
                                }
                                if(casas[0][0] == 'X' || casas[1][0] == 'X'){
                                    l = 2;
                                    c = 0;
                                }
                                if(casas[0][1] == 'X' || casas[1][1] == 'X'){
                                    l = 2;
                                    c = 1;
                                }
                                if(casas[0][2] == 'X' || casas[1][2] == 'X'){
                                    l = 2;
                                    c = 2;
                                }
                                if(casas[0][0] == 'X' || casas[1][1] == 'X'){
                                    l = 2;
                                    c = 2;
                                }
                                if(casas[0][2] == 'X' || casas[1][1] == 'X'){
                                    l = 2;
                                    c = 0;
                                }
                            }
                        }
                        
                        if (l<1 || c<1 || l>3 || c>3){
                            l=0;
                            c=0;
                        }else if(casas[l-1][c-1] != ' '){
                            l=0;
                            c=0;
                        }else{
                            if(vez%2==0){
                                casas[l-1][c-1] = 'X';
                            }else{
                                casas[l-1][c-1] = 'O';
                            }
                            vez++;
                            cont_jogadas++;
                        }
                        
                        if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){
                            cont_jogadas = 11;
                        }
                        if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){
                            cont_jogadas = 11;
                        }

                        if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){
                            cont_jogadas = 13;
                        }
                        if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){
                            cont_jogadas = 13;
                        }
                        
                    }while (cont_jogadas<=9);
                    tabuleiro(casas);
                    if(cont_jogadas==10){
                        printf("O jogo deu velha, ninguem ganhou\n");
                        rank.velha_jc++;
                    }
                    if(cont_jogadas==11){
                        printf("O jogador X ganhou\n");
                        rank.jogador++;
                    }
                    if(cont_jogadas==13){
                        printf("O jogador O ganhou\n");
                    }
                    printf("Deseja jogar dnv? [S-N]\n");
                    scanf("%s", &res);
                }while(res=='s');
            }
            if(modo!=1 && modo!=2){
                system("cls");
                printf("Opcao invalida, tente novamente\n\n");
                system("pause");
            }
        }
        if(escolha==2){
            /* Ver Ranking */
            system("cls");
            file = fopen("rank.txt", "r");
            char frase[100];
            while(fgets(frase, 100, file) != NULL){
                printf("%s", frase);
            }
            fclose(file);
            printf("\n\n");
            system("pause");
        }
        if(escolha==3){
            /* Ver Créditos */
            system("cls");
            printf("Creditos\n\n");
            printf("Equipe de Desenvolvedores:\n");
            printf("- Everton Nunes Ramalho Neto\n");
            printf("- Jose Nilton Oliveira Netto\n");
            printf("- Pedro Lucas de Souza Nobrega\n");
            printf("- Ricardo de Oliveira Sardinha Junior\n\n");
            system("pause");
        }
        if(escolha==4){
            /* Sair */
            r = false;
            system("cls");
        }
    }
}
