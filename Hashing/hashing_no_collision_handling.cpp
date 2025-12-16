#include <iostream>
using namespace std;

int hashFunction(int key) {
    return key % 10;  
}

int main() {
    int hashTable[10] = {0};  

    int keys[] = {12, 22, 42, 39};
    int n = sizeof(keys) / sizeof(keys[0]);

   
    for (int i = 0; i < n; i++) {
        int index = hashFunction(keys[i]);
        hashTable[index] = keys[i];
    }


    int keyToSearch = 22;
    int index = hashFunction(keyToSearch);

    if (hashTable[index] == keyToSearch)
        cout << keyToSearch << " found at index " << index;
    else
        cout << keyToSearch << " not found";

    return 0;
}
