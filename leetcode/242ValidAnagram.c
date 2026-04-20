#include <stdbool.h>
#include <string.h>

bool isAnagram(char * s, char * t) {
    int n1 = strlen(s);
    int n2 = strlen(t);

    if(n1 != n2) return false;

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(s[i] == t[j]) {
                t[j] = ' ';
                break;
            }
        }
    }

    for(int i = 0; i < n2; i++) {
        if(t[i] != ' ') return false;
    }

    return true;
}
