int firstBadVersion(int n) {
    int esq = 1;
    int dir = n;

    while(esq < dir) {
        int meio = esq + (dir - esq) / 2;
        if(meio >= 1) {
            return meio;
        }
        esq = meio + 1;
    }

    return esq;
}
