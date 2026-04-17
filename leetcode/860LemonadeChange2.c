#include<stdbool.h>
bool lemonadeChange(int *bills, int billsSize)
{
    int cinco = 0, dez = 0, vinte = 0;
    for (int i = 0; i < billsSize; i++) {
    if (bills[i] == 5) {
        cinco++;
    } else if (bills[i] == 10) {
        if (cinco == 0) {
            return false;
        }
        dez++;
        cinco--;
    } else {
        if (dez > 0 && cinco > 0) {
            dez--;
            cinco--;
        } else if (cinco >= 3) {
            cinco -= 3;
        } else {
            return false;
        }
    }
}
return true;
}