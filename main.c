#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 Procedimiento Ordenación shell (v[1..n])
incremento := n;
repetir
incremento := incremento div 2;
para i := incremento+1 hasta n hacer
tmp := v[i];
j := i;
seguir := cierto;
mientras j-incremento > 0 y seguir hacer
si tmp < v[j-incremento] entonces
v[j] := v[j-incremento];
j := j-incremento
sino seguir := falso
fin si
fin mientras;
v[j] := tmp
fin para
hasta incremento = 1
fin procedimiento
 */
void inicializar_semilla() {
    srand(time(NULL));
/* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
}
void aleatorio(int v [], int n) {
    int i, m=2*n+1;
    for (i=1; i <= n; i++)
        v[i] = (rand() % m) - n;
    /* se generan números pseudoaleatorio entre -n y +n */

}

void descendente(int v[], int n){
    for (int i = 1; i <= n; i++) {
        v[i]=n+1-i;
    }
}
void ord_shell(int v[], int n) {

    int incremento  = n;
    do {
        incremento = incremento/2;
        for (int i = incremento + 1; i <= n; i++) {
            int tmp = v[i];
            int j = i;
            int seguir = 1;

            while (j - incremento > 0 && seguir) {
                if (tmp < v[j - incremento]) {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                } else {
                    seguir = 0;
                }
            }
            v[j] = tmp;
        }
    } while (incremento > 1);
}
void ord_ins(int v[], int n){
    int x, j;
    for(int i = 2; i <= n; i++){
        x = v[i];
        j = i-1;
        while(j > 0 && v[j]>x){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = x;
    }
}
void listar_vector(int v[], int n){
    int i;
    printf("[");
    for(i=1; i < n; i++){
        printf("%2d,", v[i]);
    }
    printf("%2d]", v[n]);
}
int esOrdenado(int v[], int n){
    for (int i = 2; i < n; ++i) {
        if(v[i]<v[i-1]) return 0;
    }
    return 1;
}
int main() {
    int v[50+1];
    inicializar_semilla();
    descendente(v,50);
    listar_vector(v,50);
    printf("es Ordenado? %d \n", esOrdenado(v,50));
    ord_ins(v, 50);
    listar_vector(v,50);
    printf("es Ordenado? %d \n", esOrdenado(v,50));
    return 0;
}

