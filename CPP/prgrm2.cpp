#include<iostream>

class student {
private:
    int rollno;
    char name[20];

public:
    void read() {
        std::cout << "Enter the roll no: ";
        std::cin >> rollno;
        std::cout << "Enter the name: ";
        std::cin >> name;
    }

    void display() {
        std::cout << "Roll no: " << rollno << std::endl;
        std::cout << "Name: " << name << std::endl;
    }
};

class marks : public student {
private:
    int m1, m2, total;

public:
    void read1() {
        std::cout << "Enter marks for two subjects: ";
        std::cin >> m1 >> m2;
        total = m1 + m2;
    }

    void display1() {
        std::cout << "Marks 1: " << m1 << std::endl;
        std::cout << "Marks 2: " << m2 << std::endl;
        std::cout << "Total: " << total << std::endl;
    }
};

int main() {
    marks obj;
    obj.read();
    obj.read1();
    obj.display();
    obj.display1();

    return 0;
}

