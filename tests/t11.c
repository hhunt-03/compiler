int numbers[30];
int count;
int i;
int j;
int temp;

void readNums() {
    read(count);
    i = 0;
    while (i < count) {
        read(numbers[i]);
        i = i + 1;
    }
}

void sort() {
    i = 1;
    while (i < count) {
        j = i-1;
        temp = numbers[i];
        while ([j >= 0] && [numbers[j] < temp]) {
            numbers[j+1] = numbers[j];
            j = j - 1;
        }
        numbers[j+1] = temp;
        i = i + 1;
    }
}

void printNums() {
    printlines(2);
    for (i = 0; i < count; i = i+1) {
        print(numbers[i]);
    }
    printlines(1);
}


int main() {
    readNums();
    sort();
    printNums();
}
