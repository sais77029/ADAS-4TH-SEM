#include <stdio.h>
int hashTable[SIZE];
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}
void insert(int key) {
    int index = key % SIZE;
    int i = 1;
    while (hashTable[index] != -1) {
        index = (key % SIZE + i * i) % SIZE;
        i++;
    }
    hashTable[index] = key;
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : Empty\n", i);
    }
}
int main() {
    int n, key;
    init();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
