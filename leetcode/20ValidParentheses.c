#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char * s){
    int n = strlen(s);
    char *pilha = malloc(n * sizeof(char));
    int topo = -1;

    for(int i = 0; i < n; i++){
        char c = s[i];

        if(c == '(' || c == '[' || c == '{') {
            pilha[++topo] = c;
        }
        else {
            if(topo < 0) {
                free(pilha);
                return false;
            }

            char aberto = pilha[topo--];
            if((c == ')' && aberto != '(') || (c == ']' && aberto != '[') || (c == '}' && aberto != '{')) {
                free(pilha);
                return false;
            }
        }
    }

    free(pilha);
    return topo == -1;
}
