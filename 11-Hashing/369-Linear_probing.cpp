#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LinearProbeTable {
private:
    vector<int> table;
    int capacity;
    int current_size;
    const int EMPTY = -1;
    const int DELETED = -2;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    LinearProbeTable(int cap = 10) {
        capacity = cap;
        current_size = 0;
        table.assign(capacity, EMPTY);
    }

    bool insert(int key) {
        if (current_size == capacity) {
            return false;
        }

        int index = hashFunction(key);

        while (table[index] != EMPTY && table[index] != DELETED) {
            if (table[index] == key) {
                return false;
            }
            index = (index + 1) % capacity;
        }

        table[index] = key;
        current_size++;
        return true;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start_index = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == start_index) {
                break;
            }
        }
        return false;
    }

    bool deleteKey(int key) {
        int index = hashFunction(key);
        int start_index = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                current_size--;
                return true;
            }
            index = (index + 1) % capacity;
            if (index == start_index) {
                break;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            if (table[i] == EMPTY) {
                cout << "EMPTY\n";
            } else if (table[i] == DELETED) {
                cout << "DELETED\n";
            } else {
                cout << table[i] << "\n";
            }
        }
    }
};

int main() {
    LinearProbeTable lpTable(10);

    lpTable.insert(5);
    lpTable.insert(15);
    lpTable.insert(25);
    lpTable.insert(35);

    cout << "Hash Table after insertions:\n";
    lpTable.display();

    cout << "\nSearching for 15: " << (lpTable.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (lpTable.search(100) ? "Found" : "Not Found") << endl;

    lpTable.deleteKey(15);
    cout << "\nHash Table after deleting 15:\n";
    lpTable.display();

    return 0;
}