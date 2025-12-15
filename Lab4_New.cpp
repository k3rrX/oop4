#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <concepts>
#include <stdexcept>

// Проверка типа (число или не число)
template<typename T>
concept NumberType = std::is_scalar_v<T>;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Точка на плоскости
template<NumberType T>
class Dot {
private:
    T xx, yy;
public:
    Dot(T a = 0, T b = 0) : xx(a), yy(b) {}
    
    T X() const { return xx; }
    T Y() const { return yy; }
    
    friend std::ostream& operator<<(std::ostream& out, const Dot& d) {
        out << "(" << d.xx << ", " << d.yy << ")";
        return out;
    }
    
    bool same(const Dot& other) const {
        return xx == other.xx && yy == other.yy;
    }
};

// Базовая штука (фигура)
template<NumberType T>
class BaseShape {
protected:
    std::vector<std::unique_ptr<Dot<T>>> corners;
    
public:
    virtual ~BaseShape() = default;
    
    virtual Dot<T> middle() const = 0;
    virtual void showCorners(std::ostream& out) const = 0;
    virtual void getFromInput(std::istream& in) = 0;
    virtual operator double() const = 0;
    
    friend std::ostream& operator<<(std::ostream& out, const BaseShape& s) {
        s.showCorners(out);
        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, BaseShape& s) {
        s.getFromInput(in);
        return in;
    }
    
    virtual bool sameShape(const BaseShape& other) const = 0;
};

// Пять углов
template<NumberType T>
class FiveCorner : public BaseShape<T> {
private:
    Dot<T> middlePoint;
    T sizeR;
    
    void makeCorners() {
        this->corners.clear();
        for (int j = 0; j < 5; j++) {
            double angleVal = 2.0 * M_PI * j / 5.0;
            T xVal = middlePoint.X() + sizeR * std::cos(angleVal);
            T yVal = middlePoint.Y() + sizeR * std::sin(angleVal);
            this->corners.push_back(std::make_unique<Dot<T>>(xVal, yVal));
        }
    }
    
public:
    FiveCorner() : middlePoint(0, 0), sizeR(0) {
        makeCorners();
    }
    
    FiveCorner(T mx, T my, T r) : middlePoint(mx, my), sizeR(r) {
        makeCorners();
    }
    
    Dot<T> middle() const override {
        return middlePoint;
    }
    
    void showCorners(std::ostream& out) const override {
        out << "FiveCorner points: ";
        for (const auto& c : this->corners) {
            out << *c << " ";
        }
    }
    
    void getFromInput(std::istream& in) override {
        T mx, my, r;
        if (in >> mx >> my >> r) {
            middlePoint = Dot<T>(mx, my);
            sizeR = r;
            makeCorners();
        }
    }
    
    operator double() const override {
        return 0.25 * std::sqrt(5.0 * (5.0 + 2.0 * std::sqrt(5.0))) * sizeR * sizeR;
    }
    
    bool sameShape(const BaseShape<T>& other) const override {
        const FiveCorner* fc = dynamic_cast<const FiveCorner*>(&other);
        if (!fc) return false;
        return middlePoint.same(fc->middlePoint) && sizeR == fc->sizeR;
    }
};

// Шесть углов
template<NumberType T>
class SixCorner : public BaseShape<T> {
private:
    Dot<T> middlePoint;
    T sizeR;
    
    void makeCorners() {
        this->corners.clear();
        for (int j = 0; j < 6; j++) {
            double angleVal = 2.0 * M_PI * j / 6.0;
            T xVal = middlePoint.X() + sizeR * std::cos(angleVal);
            T yVal = middlePoint.Y() + sizeR * std::sin(angleVal);
            this->corners.push_back(std::make_unique<Dot<T>>(xVal, yVal));
        }
    }
    
public:
    SixCorner() : middlePoint(0, 0), sizeR(0) {
        makeCorners();
    }
    
    SixCorner(T mx, T my, T r) : middlePoint(mx, my), sizeR(r) {
        makeCorners();
    }
    
    Dot<T> middle() const override {
        return middlePoint;
    }
    
    void showCorners(std::ostream& out) const override {
        out << "SixCorner points: ";
        for (const auto& c : this->corners) {
            out << *c << " ";
        }
    }
    
    void getFromInput(std::istream& in) override {
        T mx, my, r;
        if (in >> mx >> my >> r) {
            middlePoint = Dot<T>(mx, my);
            sizeR = r;
            makeCorners();
        }
    }
    
    operator double() const override {
        return 1.5 * std::sqrt(3.0) * sizeR * sizeR;
    }
    
    bool sameShape(const BaseShape<T>& other) const override {
        const SixCorner* sc = dynamic_cast<const SixCorner*>(&other);
        if (!sc) return false;
        return middlePoint.same(sc->middlePoint) && sizeR == sc->sizeR;
    }
};

// Восемь углов
template<NumberType T>
class EightCorner : public BaseShape<T> {
private:
    Dot<T> middlePoint;
    T sizeR;
    
    void makeCorners() {
        this->corners.clear();
        for (int j = 0; j < 8; j++) {
            double angleVal = 2.0 * M_PI * j / 8.0;
            T xVal = middlePoint.X() + sizeR * std::cos(angleVal);
            T yVal = middlePoint.Y() + sizeR * std::sin(angleVal);
            this->corners.push_back(std::make_unique<Dot<T>>(xVal, yVal));
        }
    }
    
public:
    EightCorner() : middlePoint(0, 0), sizeR(0) {
        makeCorners();
    }
    
    EightCorner(T mx, T my, T r) : middlePoint(mx, my), sizeR(r) {
        makeCorners();
    }
    
    Dot<T> middle() const override {
        return middlePoint;
    }
    
    void showCorners(std::ostream& out) const override {
        out << "EightCorner points: ";
        for (const auto& c : this->corners) {
            out << *c << " ";
        }
    }
    
    void getFromInput(std::istream& in) override {
        T mx, my, r;
        if (in >> mx >> my >> r) {
            middlePoint = Dot<T>(mx, my);
            sizeR = r;
            makeCorners();
        }
    }
    
    operator double() const override {
        return 2.0 * std::sqrt(2.0) * sizeR * sizeR;
    }
    
    bool sameShape(const BaseShape<T>& other) const override {
        const EightCorner* ec = dynamic_cast<const EightCorner*>(&other);
        if (!ec) return false;
        return middlePoint.same(ec->middlePoint) && sizeR == ec->sizeR;
    }
};

// Шаблонная коробка для хранения
template<class Stuff>
class Box {
private:
    std::shared_ptr<Stuff[]> stuffArray;
    size_t maxSize;
    size_t currentSize;
    
    void makeBigger(size_t newMax) {
        std::shared_ptr<Stuff[]> newArray(new Stuff[newMax]);
        
        for (size_t k = 0; k < currentSize; k++) {
            newArray[k] = std::move(stuffArray[k]);
        }
        
        stuffArray = std::move(newArray);
        maxSize = newMax;
    }
    
public:
    Box() : stuffArray(nullptr), maxSize(0), currentSize(0) {}
    
    Box(size_t startSize) : maxSize(startSize), currentSize(0) {
        stuffArray = std::shared_ptr<Stuff[]>(new Stuff[maxSize]);
    }
    
    ~Box() = default;
    
    void putIn(const Stuff& thing) {
        if (currentSize >= maxSize) {
            makeBigger(maxSize == 0 ? 1 : maxSize * 2);
        }
        stuffArray[currentSize++] = thing;
    }
    
    void putIn(Stuff&& thing) {
        if (currentSize >= maxSize) {
            makeBigger(maxSize == 0 ? 1 : maxSize * 2);
        }
        stuffArray[currentSize] = std::move(thing);
        currentSize++;
    }
    
    void takeOut(size_t idx) {
        if (idx >= currentSize) {
            throw std::out_of_range("No such index");
        }
        
        for (size_t k = idx; k < currentSize - 1; k++) {
            stuffArray[k] = std::move(stuffArray[k + 1]);
        }
        currentSize--;
    }
    
    Stuff& getThing(size_t idx) {
        if (idx >= currentSize) {
            throw std::out_of_range("No such index");
        }
        return stuffArray[idx];
    }
    
    const Stuff& getThing(size_t idx) const {
        if (idx >= currentSize) {
            throw std::out_of_range("No such index");
        }
        return stuffArray[idx];
    }
    
    size_t count() const { return currentSize; }
    
    void emptyBox() {
        currentSize = 0;
    }
    
    double totalSpace() const {
        double total = 0;
        for (size_t k = 0; k < currentSize; k++) {
            total += static_cast<double>(*stuffArray[k]);
        }
        return total;
    }
    
    void showAll() const {
        for (size_t k = 0; k < currentSize; k++) {
            std::cout << "Thing " << k + 1 << ":\n";
            std::cout << "  " << *stuffArray[k] << "\n";
            std::cout << "  Middle: " << stuffArray[k]->middle() << "\n";
            std::cout << "  Space: " << static_cast<double>(*stuffArray[k]) << "\n\n";
        }
    }
};

int main() {
    std::cout << "=== PROGRAM FOR SHAPES ===\n";
    std::cout << "=== FIVE, SIX, EIGHT CORNERS ===\n\n";
    
    try {
        // Первая проверка
        std::cout << "=== Check 1: Box with shapes ===\n";
        Box<std::shared_ptr<BaseShape<double>>> myBox;
        
        // Кладем фигуры в коробку
        myBox.putIn(std::make_shared<FiveCorner<double>>(0, 0, 5.0));
        myBox.putIn(std::make_shared<SixCorner<double>>(2, 2, 3.0));
        myBox.putIn(std::make_shared<EightCorner<double>>(-1, -1, 4.0));
        
        // Показываем что в коробке
        myBox.showAll();
        std::cout << "All space: " << myBox.totalSpace() << "\n\n";
        
        // Убираем одну фигуру
        myBox.takeOut(1);
        std::cout << "After taking out thing at index 1:\n";
        myBox.showAll();
        
        // Вторая проверка
        std::cout << "\n=== Check 2: SixCorner with int ===\n";
        SixCorner<int> scInt(0, 0, 10);
        std::cout << "SixCorner space: " << static_cast<double>(scInt) << "\n";
        std::cout << "Middle: " << scInt.middle() << "\n";
        scInt.showCorners(std::cout);
        std::cout << "\n";
        
        // Третья проверка - ввод с клавиатуры
        std::cout << "\n=== Check 3: Input FiveCorner ===\n";
        std::cout << "Type middle_x middle_y size: ";
        FiveCorner<double> fcInput;
        std::cin >> fcInput;
        std::cout << "FiveCorner space: " << static_cast<double>(fcInput) << "\n";
        std::cout << "Middle: " << fcInput.middle() << "\n";
        
        // Четвертая проверка
        std::cout << "\n=== Check 4: Box with SixCorner<float> ===\n";
        Box<std::shared_ptr<SixCorner<float>>> floatBox;
        floatBox.putIn(std::make_shared<SixCorner<float>>(0.0f, 0.0f, 2.0f));
        floatBox.putIn(std::make_shared<SixCorner<float>>(1.0f, 1.0f, 1.5f));
        
        for (size_t k = 0; k < floatBox.count(); k++) {
            std::cout << "SixCorner " << k + 1 << " space: " 
                      << static_cast<double>(*floatBox.getThing(k)) << "\n";
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Problem: " << e.what() << std::endl;
        return 1;
    }
    
    // Ждем нажатия
    std::cout << "\nPress Enter to finish...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}
