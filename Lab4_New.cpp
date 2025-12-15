#include <iostream>

int main() {
    // Просто складываем числа
    int a = 10;
    int b = 20;
    int c = 30;
    
    std::cout << "Numbers: " << a << " " << b << " " << c << "\n";
    
    int sum = a + b + c;
    std::cout << "Sum: " << sum << "\n";
    
    // Умножение
    std::cout << "Enter number: ";
    int user_num;
    std::cin >> user_num;
    
    int result = user_num * 2;
    std::cout << "Double: " << result << "\n";
    
    return 0;
}
