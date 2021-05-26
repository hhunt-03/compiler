int n;

int fact() {
    if (n <= 1) {
        return 1;
    }
    n = n - 1;
    return (n+1) * fact();
}

int main() {
    read(n);
    print(fact());
}
