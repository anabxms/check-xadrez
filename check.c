#include <stdio.h>
#include <stdlib.h>

int check(char tabuleiro[8][8]);

int main(void)
{

    char tabuleiro[8][8];

    int checkmate = check(tabuleiro);

    if (checkmate) {
        printf("XEQUE");
    } else {
        printf("NAO XEQUE");
    }
    
}

void registraTabuleiro(char matriz[8][8]) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

}

void achaPosicao(char matriz[8][8], int *x_rei, int *y_rei) {

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            
            if (matriz[x][y] == 'K') {
                *x_rei = x;
                *y_rei = y;
            }

        }
    }

}

int temPeca(char posicao_matriz, char peca_inimigo){

    if (posicao_matriz == peca_inimigo) {
        return 1;
    }

    return 0;

}

int peao(char tabuleiro[8][8], int x_rei, int y_rei) {

    if (x_rei == 0) {
        return 0;
    } else if(temPeca(tabuleiro[x_rei-1][y_rei-1], 'p')){
        return 1;
    } else if (temPeca(tabuleiro[x_rei-1][y_rei+1], 'p')){
        return 1;
    }  else if (temPeca(tabuleiro[x_rei+1][y_rei-1], 'p')){
        return 1;
    }  else if (temPeca(tabuleiro[x_rei+1][y_rei+1], 'p')){
        return 1;
    } 
    
    return 0;
}

int torre_rainha(char tabuleiro[8][8], char peca[5], int x_rei, int y_rei) {

    int protegido = 0;

    // direito 
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei+1][y_rei], peca[i]);
    }

    if (!protegido){
        for (int x = x_rei; x < 8; x++) {
            if (tabuleiro[x][y_rei] == 't' || tabuleiro[x][y_rei] == 'q') {
                return 1;
            }
        }
    }

    // esquerdo
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei-1][y_rei], peca[i]);
    }

    if (!protegido){
        for (int x = 0; x < x_rei; x++) {
            if (tabuleiro[x][y_rei] == 't' || tabuleiro[x][y_rei] == 'q') {
                return 1;
            }
        }
    }

    // cima
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei][y_rei-1], peca[i]);
    }

    if (!protegido){
        for (int y = 0; y < y_rei; y++) {
            if (tabuleiro[x_rei][y] == 't' || tabuleiro[x_rei][y] == 'q') {
                return 1;
            }
        }
    }

    // baixo
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei][y_rei+1], peca[i]);
    }

    if (!protegido){
        for (int y = y_rei; y < 8; y++) {
            if (tabuleiro[x_rei][y] == 't' || tabuleiro[x_rei][y] == 'q') {
                return 1;
            }
        }
    }

    return 0;

}

int bispo_rainha(char tabuleiro[8][8], char peca[5], int x_rei, int y_rei) {

    int protegido = 0;
    char pecas_adv[5] = "ptcqk";

    // movimento diagonal esquerda superior
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei-1][y_rei-1], peca[i]);
        protegido += temPeca(tabuleiro[x_rei-1][y_rei-1], pecas_adv[i]);
    }

    if(!protegido){
 
        for (int i = 1; x_rei-i >= 0 && y_rei - i >= 0; i++) {
            if (tabuleiro[x_rei-i][y_rei-i] == 'b' || tabuleiro[x_rei-i][y_rei-i] == 'q') {
                return 1;
            }
        } 
    
    }
    
    // movimento diagonal direita superior
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei-1][y_rei+1], peca[i]);
        protegido += temPeca(tabuleiro[x_rei-1][y_rei-1], pecas_adv[i]);
    }

    if(!protegido){
 
        for (int i = 1; x_rei-i >= 0 && y_rei - i >= 0; i++) {
            if (tabuleiro[x_rei-i][y_rei+i] == 'b' || tabuleiro[x_rei-i][y_rei+i] == 'q') {
            return 1;
        }
        } 
    
    }

    // movimento diagonal esquerda inferior
    for (int i = 0; i < 5; i++){
        protegido += temPeca(tabuleiro[x_rei+1][y_rei-1], peca[i]);
        protegido += temPeca(tabuleiro[x_rei-1][y_rei-1], pecas_adv[i]);
    }

    if(!protegido){
 
        for (int i = 1; x_rei-i >= 0 && y_rei - i >= 0; i++) {
            if (tabuleiro[x_rei+i][y_rei-i] == 'b' || tabuleiro[x_rei+i][y_rei-i] == 'q') {
            return 1;
            }
        } 
    
    }

    // movimento diagonal direita inferior
    for (int i = 1; x_rei+i <8 && y_rei+i < 8; i++) {
        for (int j = 0; j < 5; j++){
            protegido += temPeca(tabuleiro[x_rei+i][y_rei+i], peca[j]);
            protegido += temPeca(tabuleiro[x_rei+i][y_rei+i], pecas_adv[j]);
        }
    }

    if(!protegido){

        for (int i = 1; x_rei+i <8 && y_rei+i < 8; i++) {
            if (tabuleiro[x_rei+i][y_rei+i] == 'b' || tabuleiro[x_rei+i][y_rei+i] == 'q') {
            return 1;
            }
        } 
    
    }

    return 0;
}

int cavalo(char tabuleiro[8][8], int x_rei, int y_rei) {

    if (tabuleiro[x_rei+1][y_rei+2]  == 'c') {
        return 1;
    } else if (tabuleiro[x_rei+1][y_rei-2]  == 'c') {
        return 1;
    } else if (tabuleiro[x_rei-1][y_rei+2] == 'c') {
        return 1;
    } else if (tabuleiro[x_rei-1][y_rei-2] == 'c') {
        return 1;
    } else if (tabuleiro[x_rei+2][y_rei+1] == 'c') {
        return 1;
    } else if (tabuleiro[x_rei-2][y_rei+1] == 'c') {
        return 1;
    } else if (tabuleiro[x_rei+2][y_rei-1] == 'c') {
        return 1;
    } else if (tabuleiro[x_rei-2][y_rei-1] == 'c') {
        return 1;
    }

    return 0;

}

int rei(char tabuleiro[8][8], int x_rei, int y_rei) {

    if (tabuleiro[x_rei+1][y_rei] == 'k') {
        return 1;
    } else if (tabuleiro[x_rei-1][y_rei]  == 'k') {
        return 1;
    } else if (tabuleiro[x_rei][y_rei+1] == 'k') {
        return 1;
    } else if (tabuleiro[x_rei][y_rei+1] == 'k') {
        return 1;
    } else if (tabuleiro[x_rei-1][y_rei-1] == 'k') {
        return 1;
    } else if (tabuleiro[x_rei-1][y_rei+1] == 'k') {
        return 1;
    } else if (tabuleiro[x_rei+1][y_rei-1] == 'k') {
        return 1;
    } else if (tabuleiro[x_rei+1][y_rei+1] == 'k') {
        return 1;
    }

    return 0;

}


int check(char tabuleiro[8][8]){

    char pecas[5] = "PTCBQ";
    int check = 0;

    registraTabuleiro(tabuleiro);
    
    int x_rei, y_rei;
    achaPosicao(tabuleiro, &x_rei, &y_rei);

    int checkPeao = peao(tabuleiro, x_rei, y_rei);
    int checkTorreRainha = torre_rainha(tabuleiro, pecas, x_rei, y_rei);
    int checkBispoRainha = bispo_rainha(tabuleiro, pecas, x_rei, y_rei);
    int checkCavalo = cavalo(tabuleiro, x_rei, y_rei);
    int checkRei = rei(tabuleiro, x_rei, y_rei);

    if (checkPeao || checkTorreRainha || checkBispoRainha || checkCavalo || checkRei) {
        check = 1;
    }
               
    if(check){
        return 1;
    } 

    return 0;

}
