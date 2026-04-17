#include<stdbool.h>
bool lemonadeChange(int *bills, int billsSize)
{
    int cinco = 0, dez = 0, vinte = 0;
    for (int i = 0; i <= billsSize; i++) {
        if (bills[i] == 5) {
            cinco++;
        }
        if (bills[i] == 10){
            dez++;
            if (cinco == 0){
                return 0;
            }
            else{
                cinco--;
            }
        }
        if  (bills[i] == 20) {
            vinte++;
            if ((5 * cinco) + (10 * dez) < 15){
                return 0;
            }
            else{
                int troco = 15;
                while (dez > 0 && troco >= 10){
                    dez--;
                    troco = troco -10;
                }
                while (troco > 0){
                    cinco--;
                    troco = troco - 5;
                }
            }
        }
    }
    return 1;
}