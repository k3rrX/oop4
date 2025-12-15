#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <concepts>
#include <stdexcept>
#include <algorithm>

// Концепт для скалярного типа
template<typename T>
concept Scalar = std::is_scalar_v<T>;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Шаблон точки
template<Scalar T>
class Point {
private:
    T x, y;
public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    
    T getX() const { return x; }
    T getY() const { return y; }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Базовый шаблонный класс фигуры
template<Scalar T>
class Figure {
protected:
    std::vector<std::unique_ptr<Point<T>>> vertices;
    
public:
    virtual ~Figure() = default;
    
    virtual Point<T> getCenter() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readFromStream(std::istream& is) = 0;
    virtual operator double() const = 0; // площадь
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.printVertices(os);
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.readFromStream(is);
        return is;
    }
    
    virtual bool operator==(const Figure& other) const = 0;
};

// Пятиугольник (правильный)
template<Scalar T>
class Pentagon : public Figure<T> {
private:
    Point<T> center;
    T radius;
    
    void calculateVertices() {
        this->vertices.clear();
        for (int i = 0; i < 5; i++) {
            double angle = 2.0 * M_PI * i / 5.0;
            T x = center.getX() + radius * std::cos(angle);
            T y = center.getY() + radius * std::sin(angle);
            this->vertices.push_back(std::make_unique<Point<T>>(x, y));
        }
    }
    
public:
    Pentagon() : center(0, 0), radius(0) {
        calculateVertices();
    }
    
    Pentagon(T cx, T cy, T r) : center(cx, cy), radius(r) {
        calculateVertices();
    }
    
    Point<T> getCenter() const override {
        return center;
    }
    
    void printVertices(std::ostream& os) const override {
        os << "Pentagon vertices: ";
        for (const auto& v : this->vertices) {
            os << *v << " ";
        }
    }
    
    void readFromStream(std::istream& is) override {
        T cx, cy, r;
        if (is >> cx >> cy >> r) {
            center = Point<T>(cx, cy);
            radius = r;
            calculateVertices();
        }
    }
    
    operator double() const override {
        return 0.25 * std::sqrt(5.0 * (5.0 + 2.0 * std::sqrt(5.0))) * radius * radius;
    }
    
    bool operator==(const Figure<T>& other) const override {
        const Pentagon* pent = dynamic_cast<const Pentagon*>(&other);
        if (!pent) return false;
        return center == pent->center && radius == pent->radius;
    }
};

// Шестиугольник (правильный)
template<Scalar T>
class Hexagon : public Figure<T> {
private:
    Point<T> center;
    T radius;
    
    void calculateVertices() {
        this->vertices.clear();
        for (int i = 0; i < 6; i++) {
            double angle = 2.0 * M_PI * i / 6.0;
            T x = center.getX() + radius * std::cos(angle);
            T y = center.getY() + radius * std::sin(angle);
            this->vertices.push_back(std::make_unique<Point<T>>(x, y));
        }
    }
    
public:
    Hexagon() : center(0, 0), radius(0) {
        calculateVertices();
    }
    
    Hexagon(T cx, T cy, T r) : center(cx, cy), radius(r) {
        calculateVertices();
    }
    
    Point<T> getCenter() const override {
        return center;
    }
    
    void printVertices(std::ostream& os) const override {
        os << "Hexagon vertices: ";
        for (const auto& v : this->vertices) {
            os << *v << " ";
        }
    }
    
    void readFromStream(std::istream& is) override {
        T cx, cy, r;
        if (is >> cx >> cy >> r) {
            center = Point<T>(cx, cy);
            radius = r;
            calculateVertices();
        }
    }
    
    operator double() const override {
        return 1.5 * std::sqrt(3.0) * radius * radius;
    }
    
    bool operator==(const Figure<T>& other) const override {
        const Hexagon* hex = dynamic_cast<const Hexagon*>(&other);
        if (!hex) return false;
        return center == hex->center && radius == hex->radius;
    }
};

// Восьмиугольник (правильный)
template<Scalar T>
class Octagon : public Figure<T> {
private:
    Point<T> center;
    T radius;
    
    void calculateVertices() {
        this->vertices.clear();
        for (int i = 0; i < 8; i++) {
            double angle = 2.0 * M_PI * i / 8.0;
            T x = center.getX() + radius * std::cos(angle);
            T y = center.getY() + radius * std::sin(angle);
            this->vertices.push_back(std::make_unique<Point<T>>(x, y));
        }
    }
    
public:
    Octagon() : center(0, 0), radius(0) {
        calculateVertices();
    }
    
    Octagon(T cx, T cy, T r) : center(cx, cy), radius(r) {
        calculateVertices();
    }
    
    Point<T> getCenter() const override {
        return center;
    }
    
    void printVertices(std::ostream& os) const override {
        os << "Octagon vertices: ";
        for (const auto& v : this->vertices) {
            os << *v << " ";
        }
    }
    
    void readFromStream(std::istream& is) override {
        T cx, cy, r;
        if (is >> cx >> cy >> r) {
            center = Point<T>(cx, cy);
            radius = r;
            calculateVertices();
        }
    }
    
    operator double() const override {
        return 2.0 * std::sqrt(2.0) * radius * radius;
    }
    
    bool operator==(const Figure<T>& other) const override {
        const Octagon* oct = dynamic_cast<const Octagon*>(&other);
        if (!oct) return false;
        return center == oct->center && radius == oct->radius;
    }
};

// Шаблонный динамический массив
template<class T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t capacity;
    size_t size_;
    
    void resize(size_t new_capacity) {
        std::shared_ptr<T[]> new_data(new T[new_capacity]);
        
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = std::move(data[i]); // перемещение
        }
        
        data = std::move(new_data);
        capacity = new_capacity;
    }
    
public:
    Array() : data(nullptr), capacity(0), size_(0) {}
    
    Array(size_t initial_capacity) : capacity(initial_capacity), size_(0) {
        data = std::shared_ptr<T[]>(new T[capacity]);
    }
    
    ~Array() = default;
    
    void push_back(const T& value) {
        if (size_ >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size_++] = value;
    }
    
    void push_back(T&& value) {
        if (size_ >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size_] = std::move(value);
        size_++;
    }
    
    void remove(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        
        for (size_t i = index; i < size_ - 1; i++) {
            data[i] = std::move(data[i + 1]);
        }
        size_--;
    }
    
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    size_t size() const { return size_; }
    
    void clear() {
        size_ = 0;
    }
    
    double totalArea() const {
        double total = 0;
        for (size_t i = 0; i < size_; i++) {
            total += static_cast<double>(*data[i]);
        }
        return total;
    }
    
    void printAll() const {
        for (size_t i = 0; i < size_; i++) {
            std::cout << "Figure " << i + 1 << ":\n";
            std::cout << "  " << *data[i] << "\n";
            std::cout << "  Center: " << data[i]->getCenter() << "\n";
            std::cout << "  Area: " << static_cast<double>(*data[i]) << "\n\n";
        }
    }
};

int main() {
    std::cout << "=== LABORATORY WORK 4 - TEMPLATE CLASSES ===\n";
    std::cout << "=== PENTAGON, HEXAGON, OCTAGON ===\n\n";
    
    try {
        // Пример работы с шаблоном для базового типа
        std::cout << "=== Test 1: Array<Figure<double>*> ===\n";
        Array<std::shared_ptr<Figure<double>>> figures;
        
        // Добавляем фигуры
        figures.push_back(std::make_shared<Pentagon<double>>(0, 0, 5.0));
        figures.push_back(std::make_shared<Hexagon<double>>(2, 2, 3.0));
        figures.push_back(std::make_shared<Octagon<double>>(-1, -1, 4.0));
        
        // Выводим информацию
        figures.printAll();
        std::cout << "Total area: " << figures.totalArea() << "\n\n";
        
        // Удаляем фигуру
        figures.remove(1);
        std::cout << "After removing figure at index 1:\n";
        figures.printAll();
        
        // Пример работы с конкретным типом наследника
        std::cout << "\n=== Test 2: Direct usage of Hexagon<int> ===\n";
        Hexagon<int> hex(0, 0, 10);
        std::cout << "Hexagon area: " << static_cast<double>(hex) << "\n";
        std::cout << "Center: " << hex.getCenter() << "\n";
        hex.printVertices(std::cout);
        std::cout << "\n";
        
        // Пример ввода фигуры
        std::cout << "\n=== Test 3: Input Pentagon ===\n";
        std::cout << "Enter center_x center_y radius for Pentagon: ";
        Pentagon<double> pent_input;
        std::cin >> pent_input;
        std::cout << "Pentagon area: " << static_cast<double>(pent_input) << "\n";
        std::cout << "Center: " << pent_input.getCenter() << "\n";
        
        // Пример работы Array с конкретным типом
        std::cout << "\n=== Test 4: Array<Hexagon<float>> ===\n";
        Array<std::shared_ptr<Hexagon<float>>> hexagons;
        hexagons.push_back(std::make_shared<Hexagon<float>>(0.0f, 0.0f, 2.0f));
        hexagons.push_back(std::make_shared<Hexagon<float>>(1.0f, 1.0f, 1.5f));
        
        for (size_t i = 0; i < hexagons.size(); i++) {
            std::cout << "Hexagon " << i + 1 << " area: " 
                      << static_cast<double>(*hexagons[i]) << "\n";
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    // Пауза для Windows
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(); // очищаем буфер
    std::cin.get();
    
    return 0;
}
