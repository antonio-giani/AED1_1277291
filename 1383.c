/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 31/08/2026
Objetivo    : Fazer um jogo de sudoku em que checa as linhas colunas e blocos 3x3
Dificuldade : Saber como checar os blocos 3x3
Uso de IA   : Usei para checar os blocos 3x3
-------------------------------------------------------------------------- */



#include <stdio.h>

int main() {
    int n, k, i, j, m[9][9];

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
                scanf("%d", &m[i][j]);

        int ok = 1;

        /* confere linhas e colunas */
        for (i = 0; i < 9 && ok; i++) {
            int linha[10] = {0}, coluna[10] = {0};
            for (j = 0; j < 9; j++) {
                int a = m[i][j], b = m[j][i];
                if (a < 1 || a > 9 || linha[a]++ ||
                    b < 1 || b > 9 || coluna[b]++) {
                    ok = 0;
                    break;
                }
            }
        }

        /* confere as regiões 3x3 */
        int r, c;
        for (r = 0; r < 9 && ok; r += 3) {
            for (c = 0; c < 9 && ok; c += 3) {
                int visto[10] = {0};
                for (i = r; i < r + 3 && ok; i++)
                    for (j = c; j < c + 3; j++)
                        if (visto[m[i][j]]++) {
                            ok = 0;
                            break;
                        }
            }
        }

        printf("Instancia %d\n%s\n\n", k, ok ? "SIM" : "NAO");
    }

    return 0;
}