#include<stdbool.h>
bool isPalindrome(char* s) {
    int tamanho, i, j;
    tamanho = strlen(s);
    i = 0;
    j = tamanho - 1;
    while (i < j) {
        if(!isalnum(s[i])){
            i++;
        }
        else if (!isalnum(s[j])){
            j--;
        }
        else{
            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}