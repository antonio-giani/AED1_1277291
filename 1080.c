/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 31/08/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.
Dificuldade : Nenhum
Uso de IA   : Não usei
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int x, maior, posicao, i;

    for (i = 1; i <= 100; i++) {
        scanf("%d", &x);
        if (i == 1 || x > maior) {
            maior = x;
            posicao = i;
        }
    }

    printf("%d\n%d\n", maior, posicao);

    return 0;
}