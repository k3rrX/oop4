#include <iostream>
#include <cmath>

using namespace std;

double const_pi = 3.14159265358979323846;

class point {
public:
    double a;
    double b;
    
    point() {
        a = 0;
        b = 0;
    }
    
    point(double x, double y) {
        a = x;
        b = y;
    }
};

class five_shape {
public:
    point center_point;
    double radius_value;
    point points_array[5];
    
    five_shape() {
        center_point = point(0, 0);
        radius_value = 0;
        calculate_points();
    }
    
    five_shape(double x, double y, double r) {
        center_point = point(x, y);
        radius_value = r;
        calculate_points();
    }
    
    void calculate_points() {
        for (int i = 0; i < 5; i++) {
            double angle = 2.0 * const_pi * i / 5.0;
            points_array[i].a = center_point.a + radius_value * cos(angle);
            points_array[i].b = center_point.b + radius_value * sin(angle);
        }
    }
    
    double get_area() {
        return 0.25 * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * radius_value * radius_value;
    }
    
    void show() {
        cout << "Five shape points: ";
        for (int i = 0; i < 5; i++) {
            cout << "(" << points_array[i].a << "," << points_array[i].b << ") ";
        }
        cout << endl;
    }
};

class six_shape {
public:
    point center_point;
    double radius_value;
    point points_array[6];
    
    six_shape() {
        center_point = point(0, 0);
        radius_value = 0;
        calculate_points();
    }
    
    six_shape(double x, double y, double r) {
        center_point = point(x, y);
        radius_value = r;
        calculate_points();
    }
    
    void calculate_points() {
        for (int i = 0; i < 6; i++) {
            double angle = 2.0 * const_pi * i / 6.0;
            points_array[i].a = center_point.a + radius_value * cos(angle);
            points_array[i].b = center_point.b + radius_value * sin(angle);
        }
    }
    
    double get_area() {
        return 1.5 * sqrt(3.0) * radius_value * radius_value;
    }
    
    void show() {
        cout << "Six shape points: ";
        for (int i = 0; i < 6; i++) {
            cout << "(" << points_array[i].a << "," << points_array[i].b << ") ";
        }
        cout << endl;
    }
};

class eight_shape {
public:
    point center_point;
    double radius_value;
    point points_array[8];
    
    eight_shape() {
        center_point = point(0, 0);
        radius_value = 0;
        calculate_points();
    }
    
    eight_shape(double x, double y, double r) {
        center_point = point(x, y);
        radius_value = r;
        calculate_points();
    }
    
    void calculate_points() {
        for (int i = 0; i < 8; i++) {
            double angle = 2.0 * const_pi * i / 8.0;
            points_array[i].a = center_point.a + radius_value * cos(angle);
            points_array[i].b = center_point.b + radius_value * sin(angle);
        }
    }
    
    double get_area() {
        return 2.0 * sqrt(2.0) * radius_value * radius_value;
    }
    
    void show() {
        cout << "Eight shape points: ";
        for (int i = 0; i < 8; i++) {
            cout << "(" << points_array[i].a << "," << points_array[i].b << ") ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Program for shapes" << endl;
    cout << "==================" << endl << endl;
    
    // Create shapes
    five_shape shape1(0, 0, 5.0);
    six_shape shape2(2, 2, 3.0);
    eight_shape shape3(-1, -1, 4.0);
    
    // Show shapes
    cout << "Shape 1:" << endl;
    shape1.show();
    cout << "Area: " << shape1.get_area() << endl << endl;
    
    cout << "Shape 2:" << endl;
    shape2.show();
    cout << "Area: " << shape2.get_area() << endl << endl;
    
    cout << "Shape 3:" << endl;
    shape3.show();
    cout << "Area: " << shape3.get_area() << endl << endl;
    
    // Total area
    double total = shape1.get_area() + shape2.get_area() + shape3.get_area();
    cout << "Total area: " << total << endl << endl;
    
    // Test with different radius
    cout << "Test with different radius:" << endl;
    six_shape shape4(0, 0, 10);
    cout << "Six shape with radius 10:" << endl;
    shape4.show();
    cout << "Area: " << shape4.get_area() << endl << endl;
    
    // Manual input test
    cout << "Enter parameters for five shape (x y radius): ";
    double x, y, r;
    cin >> x >> y >> r;
    
    five_shape shape5(x, y, r);
    cout << "Created shape:" << endl;
    shape5.show();
    cout << "Area: " << shape5.get_area() << endl;
    
    cout << endl << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    
    return 0;
}
