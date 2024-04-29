//  ██████╗ ██████╗ ██████╗              
// ██╔═══██╗██╔══██╗╚════██╗             
// ██║   ██║██████╔╝ █████╔╝             
// ██║   ██║██╔═══╝ ██╔═══╝              
// ╚██████╔╝██║     ███████╗             
//  ╚═════╝ ╚═╝     ╚══════╝             
                                      
// ██████╗  ██████╗  ██╗██████╗          
// ╚════██╗██╔═████╗███║╚════██╗         
//  █████╔╝██║██╔██║╚██║ █████╔╝         
//  ╚═══██╗████╔╝██║ ██║ ╚═══██╗         
// ██████╔╝╚██████╔╝ ██║██████╔╝         
// ╚═════╝  ╚═════╝  ╚═╝╚═════╝          
                                      
// ██████╗ ██╗████████╗████████╗ ██████╗ 
// ██╔══██╗██║╚══██╔══╝╚══██╔══╝██╔═══██╗
// ██║  ██║██║   ██║      ██║   ██║   ██║
// ██║  ██║██║   ██║      ██║   ██║   ██║
// ██████╔╝██║   ██║      ██║   ╚██████╔╝
// ╚═════╝ ╚═╝   ╚═╝      ╚═╝    ╚═════╝ 
                                      



#include <iostream>
#include <fstream>
using namespace std;
class Vector {
private:
    int *list;
    int size;
    int capacity;

public:
    Vector() : list(nullptr), size(0), capacity(0) {}

    Vector(int *A, int size) : size(size), capacity(size) {
        list = new int[capacity];
        for (int i = 0; i < size; ++i) {
            list[i] = A[i];
        }
    }

    Vector(const string& fileName) : list(nullptr), size(0), capacity(0) {
        ifstream file(fileName);
        int val;
        while (file >> val) {
            pushRear(val);
        }
        file.close();
    }

    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        list = new int[capacity];
        for (int i = 0; i < size; ++i) {
            list[i] = other.list[i];
        }
    }

    ~Vector() {
        delete[] list;
    }

    void pushFront(int val) {
        if (size == capacity) {
            expand();
        }
        for (int i = size; i > 0; --i) {
            list[i] = list[i - 1];
        }
        list[0] = val;
        size++;
    }

    void pushFront(const Vector& other) {
        for (int i = other.size - 1; i >= 0; --i) {
            pushFront(other.list[i]);
        }
    }

    void pushRear(int val) {
        if (size == capacity) {
            expand();
        }
        list[size++] = val;
    }

    void pushRear(const Vector& other) {
        for (int i = 0; i < other.size; ++i) {
            pushRear(other.list[i]);
        }
    }

    void expand() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < size; ++i) {
            cout << list[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    void printToFile(const string& fileName) const {
        ofstream file(fileName);
        file << "[";
        for (int i = 0; i < size; ++i) {
            file << list[i];
            if (i < size - 1) {
                file << ", ";
            }
        }
        file << "]" << std::endl;
        file.close();
    }

    int popFront() {
        if (size == 0) {
            return -1; // or throw an exception
        }
        int val = list[0];
        for (int i = 0; i < size - 1; ++i) {
            list[i] = list[i + 1];
        }
        size--;
        return val;
    }

    int popRear() {
        if (size == 0) {
            return -1; // or throw an exception
        }
        int val = list[size - 1];
        size--;
        return val;
    }

    int popAt(int loc) {
        if (loc < 0 || loc >= size) {
            return -1; // or throw an exception
        }
        int val = list[loc];
        for (int i = loc; i < size - 1; ++i) {
            list[i] = list[i + 1];
        }
        size--;
        return val;
    }

    int find(int val) const {
        for (int i = 0; i < size; ++i) {
            if (list[i] == val) {
                return i;
            }
        }
        return -1;
    }

    void inOrderPush(int val) {
        // Implement if needed
    }
};

int main() {

    cout << "Ross Ditto" << endl;
    cout << "4/28/24" << endl;
    cout << "Spring 2024" << endl << endl;
    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    // [25, 20, 18, 18, 20, 25]

    int A[] = {11, 25, 33, 47, 51};
    Vector v2(A, 5);
    v2.print();
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    v2.pushRear(63);
    v2.print();
    // [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);
    v1.print();
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    int x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 33, 47, 51, 63]
    cout << x << endl;
    // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 33]
    cout << x << endl;
    // 47

    x = v2.popAt(3);
    v2.print();
    // [9, 11, 25, 33, 47, 51, 63]
    cout << x << endl;
    // 27

    x = v2.find(51);
    cout << x << endl;
    // 5

    x = v2.find(99);
    cout << x << endl;
    // -1

    Vector v3(v1);
    v3.print();
    // [18, 20, 25, 9, 11, 25, 33]

    v3.pushFront(v2);
    v3.print();
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    Vector v4("input.dat");
    v4.pushRear(v3);
    v4.print();
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12,
    // 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  return 0;
}

