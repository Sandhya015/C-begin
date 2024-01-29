#include <iostream>

class frequency {
private:
    int a[10], n, i, ele, freq;

public:
    void read();
    void find_freq();
    void display();
};

void frequency::read() {
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    std::cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        std::cin >> a[i];
    std::cout << "Enter the search element: ";
    std::cin >> ele;
}

void frequency::find_freq() {
    freq = 0;
    for (i = 0; i < n; i++)
        if (a[i] == ele)
            freq++;
}

void frequency::display() {
    if (freq > 0)
        std::cout << "Frequency = " << freq;
    else
        std::cout << "Element not found";
}

int main() {
    frequency f;
    f.read();
    f.find_freq();
    f.display();

    // Note: Standard C++ does not provide a direct replacement for _getch().
    // If you need single-character input, you may need to explore platform-specific or third-party solutions.

    return 0;
}

