int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum(n - 1);
}

int sumFirstN(int n) {
    int ans = sum(n);
    return ans;
}
