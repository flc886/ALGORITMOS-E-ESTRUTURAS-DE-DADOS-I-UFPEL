int mySqrt(int x) {

    int i = 1;
    int ans = 0;

    while (i <= x) {

        if (i <= x / i) {
            ans = i;
        } else {
            break;
        }

        i++;
    }

    return ans;
}