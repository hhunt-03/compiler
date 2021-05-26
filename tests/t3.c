int i;
int j;
int k;
int m;

int main() {
    read(i, j, k, m);
    print(i, j, k, m);
    printlines(1);
    print((i^j) * k + m, m + k * (i^j));
    printlines(1);
    printspaces(8);
    printlines(1);
    print(i, j, k, m);
    printlines(1);
}
