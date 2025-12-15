#include <iostream>
#include <cmath>

int main() {
    std::cout << "Geometry shapes program\n\n";
    
    // Five shape
    double center_x1 = 0;
    double center_y1 = 0;
    double radius1 = 5.0;
    
    std::cout << "Five shape with center (" << center_x1 << "," << center_y1 
              << ") radius " << radius1 << ":\n";
    std::cout << "Points: ";
    
    double points1_x[5];
    double points1_y[5];
    
    for (int i = 0; i < 5; i++) {
        double angle = 2.0 * 3.141592653589793 * i / 5.0;
        points1_x[i] = center_x1 + radius1 * cos(angle);
        points1_y[i] = center_y1 + radius1 * sin(angle);
        std::cout << "(" << points1_x[i] << "," << points1_y[i] << ") ";
    }
    
    double area1 = 0.25 * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * radius1 * radius1;
    std::cout << "\nArea: " << area1 << "\n\n";
    
    // Six shape  
    double center_x2 = 2;
    double center_y2 = 2;
    double radius2 = 3.0;
    
    std::cout << "Six shape with center (" << center_x2 << "," << center_y2 
              << ") radius " << radius2 << ":\n";
    std::cout << "Points: ";
    
    double points2_x[6];
    double points2_y[6];
    
    for (int i = 0; i < 6; i++) {
        double angle = 2.0 * 3.141592653589793 * i / 6.0;
        points2_x[i] = center_x2 + radius2 * cos(angle);
        points2_y[i] = center_y2 + radius2 * sin(angle);
        std::cout << "(" << points2_x[i] << "," << points2_y[i] << ") ";
    }
    
    double area2 = 1.5 * sqrt(3.0) * radius2 * radius2;
    std::cout << "\nArea: " << area2 << "\n\n";
    
    // Eight shape
    double center_x3 = -1;
    double center_y3 = -1;
    double radius3 = 4.0;
    
    std::cout << "Eight shape with center (" << center_x3 << "," << center_y3 
              << ") radius " << radius3 << ":\n";
    std::cout << "Points: ";
    
    double points3_x[8];
    double points3_y[8];
    
    for (int i = 0; i < 8; i++) {
        double angle = 2.0 * 3.141592653589793 * i / 8.0;
        points3_x[i] = center_x3 + radius3 * cos(angle);
        points3_y[i] = center_y3 + radius3 * sin(angle);
        std::cout << "(" << points3_x[i] << "," << points3_y[i] << ") ";
    }
    
    double area3 = 2.0 * sqrt(2.0) * radius3 * radius3;
    std::cout << "\nArea: " << area3 << "\n\n";
    
    // Total area
    double total = area1 + area2 + area3;
    std::cout << "Total area of all shapes: " << total << "\n\n";
    
    // Another six shape
    std::cout << "Another six shape with radius 10:\n";
    double radius4 = 10;
    double area4 = 1.5 * sqrt(3.0) * radius4 * radius4;
    std::cout << "Area: " << area4 << "\n\n";
    
    // User input
    std::cout << "Enter parameters for five shape (center_x center_y radius): ";
    double user_x, user_y, user_r;
    std::cin >> user_x >> user_y >> user_r;
    
    std::cout << "\nUser five shape:\n";
    std::cout << "Points: ";
    for (int i = 0; i < 5; i++) {
        double angle = 2.0 * 3.141592653589793 * i / 5.0;
        double x = user_x + user_r * cos(angle);
        double y = user_y + user_r * sin(angle);
        std::cout << "(" << x << "," << y << ") ";
    }
    
    double user_area = 0.25 * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * user_r * user_r;
    std::cout << "\nArea: " << user_area << "\n\n";
    
    std::cout << "Program finished\n";
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}
