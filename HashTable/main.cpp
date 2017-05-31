#include <iostream>
#include <string>
#include <vector>


#define HashParam1 37
#define HashParam2 79
#define Rehash 0.75

class HashTable {
    struct node {
        node(const std::string &data)
                :_data(data), _isDeleted(false) {}
        std::string _data;
        bool _isDeleted;
    };

public :
    HashTable(int capacity = 8)
            :_capacity(capacity), _size(0), _map(_capacity, nullptr) {}

    ~HashTable() = default;

    bool add(const std::string &data);

    bool remove(const std::string &data);

    bool has(const std::string &data);

private :
    int hash_a(const std::string &data, const int m);

    int hash_b(const std::string &data, const int m);

    void rehash();

    int _capacity;
    int _size;
    std::vector<node *> _map;
};

bool HashTable::add(const std::string &data) {
    if (_size / _capacity >= Rehash) {
        rehash();
    }
    int hash1 = hash_a(data, _capacity);
    int hash2 = hash_b(data, _capacity);
    size_t i = 0;
    int deletedNodeIndex = -1;
    while (_map[hash1] != nullptr && i < _capacity) {
        if (_map[hash1]->_data == data && !_map[hash1]->_isDeleted) {
            return false;
        }
        if (_map[hash1]->_isDeleted && deletedNodeIndex < 0) {
            deletedNodeIndex = hash1;
        }
        hash1 = (hash1 + hash2) % _capacity;
        ++i;
    }
    if (deletedNodeIndex >= 0) {
        _map[deletedNodeIndex]->_data = data;
        _map[deletedNodeIndex]->_isDeleted = false;
    } else {
        _map[hash1] = new node(data);
    }
    ++_size;
    return true;
}

bool HashTable::remove(const std::string &data) {
    int hash1 = hash_a(data, _capacity);
    int hash2 = hash_b(data, _capacity);
    size_t i = 0;
    while (_map[hash1] != nullptr && i < _capacity) {
        if (_map[hash1]->_data == data && !_map[hash1]->_isDeleted) {
            _map[hash1]->_isDeleted = true;
            --_size;
            return true;
        }
        hash1 = (hash1 + hash2) % _capacity;
        ++i;
    }
    return false;
}

bool HashTable::has(const std::string &data) {
    int hash1 = hash_a(data, _capacity);
    int hash2 = hash_b(data, _capacity);
    size_t i = 0;
    while (_map[hash1] != NULL && i < _capacity) {
        if (_map[hash1]->_data == data && !_map[hash1]->_isDeleted) {
            return true;
        }
        hash1 = (hash1 + hash2) % _capacity;
        ++i;
    }
    return false;
}

int HashTable::hash_a(const std::string &data, const int m) {
    int result = 0;
    for (size_t i = 0; i < data.length(); ++i) {
        result = (result * HashParam1 + data[i]) % m;
    }
    return result;
}

int HashTable::hash_b(const std::string &data, const int m) {
    int result = 0;
    for (size_t i = 0; i < data.length(); ++i) {
        result = (result * HashParam2 + data[i]) % m;
    }
    return ((result << 1) + 1) % m;
}

void HashTable::rehash() {
    int newSize = _capacity << 1;
    std::vector<node *> newMap(newSize, nullptr);
    for (size_t i = 0; i < _capacity; ++i) {
        if (_map[i] != nullptr && !_map[i]->_isDeleted) {
            std::string data = _map[i]->_data;
            int currentHash = hash_a(data, newSize);
            int otherHash = hash_b(data, newSize);
            size_t j = 0;
            while (newMap[currentHash] != nullptr && j < newSize) {
                currentHash = (currentHash + otherHash) % newSize;
                ++j;
            }
            newMap[currentHash] = new node(data);
        }
    }
    _map = newMap;
    _capacity = newSize;
}

int main() {
    char c;
    std::string str;
    HashTable table;
    while (std::cin >> c >> str) {
        bool result;
        switch (c) {
            case '+':
                result = table.add(str);
                break;
            case '-':
                result = table.remove(str);
                break;
            case '?':
                result = table.has(str);
                break;
            default:
                result = false;
                break;
        }
        std::cout << ((result) ? "OK" : "FAIL") << "\n";
    }
    return 0;
}