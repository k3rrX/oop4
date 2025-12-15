#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <concepts>

// Проверка чтоб тип был числовой
template<typename TT>
concept NumLike = std::is_scalar_v<TT>;

#ifndef MY_PI
#define MY_PI 3.14159265358979323846
#endif

// Точка с двумя координатами
template<NumLike TT>
class Spot {
    TT x_val, y_val;
public:
    Spot(TT x = 0, TT y = 0) : x_val(x), y_val(y) {}
    
    TT x() const { return x_val; }
    TT y() const { return y_val; }
    
    friend std::ostream& operator<<(std::ostream& os, const Spot& s) {
        os << "[" << s.x_val << "," << s.y_val << "]";
        return os;
    }
    
    bool check(const Spot& s2) const {
        return x_val == s2.x_val && y_val == s2.y_val;
    }
};

// Базовая фигура
template<NumLike TT>
class BaseFigura {
protected:
    std::vector<std::unique_ptr<Spot<TT>>> dots;
    
public:
    virtual ~BaseFigura() {}
    
    virtual Spot<TT> center_point() const = 0;
    virtual void show_dots(std::ostream& os) const = 0;
    virtual void read_data(std::istream& is) = 0;
    virtual double area_value() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const BaseFigura& bf) {
        bf.show_dots(os);
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, BaseFigura& bf) {
        bf.read_data(is);
        return is;
    }
    
    virtual bool compare(const BaseFigura& bf2) const = 0;
    
    operator double() const { return area_value(); }
};

// Фигура с 5 углами
template<NumLike TT>
class Figura5 : public BaseFigura<TT> {
    Spot<TT> cntr;
    TT rad_val;
    
    void calc_dots() {
        this->dots.clear();
        for (int cnt = 0; cnt < 5; cnt++) {
            double ang = 2.0 * MY_PI * cnt / 5.0;
            TT x = cntr.x() + rad_val * std::cos(ang);
            TT y = cntr.y() + rad_val * std::sin(ang);
            this->dots.push_back(std::make_unique<Spot<TT>>(x, y));
        }
    }
    
public:
    Figura5() : cntr(0, 0), rad_val(0) { calc_dots(); }
    Figura5(TT cx, TT cy, TT r) : cntr(cx, cy), rad_val(r) { calc_dots(); }
    
    Spot<TT> center_point() const override { return cntr; }
    
    void show_dots(std::ostream& os) const override {
        os << "Figura5 dots: ";
        for (const auto& d : this->dots) os << *d << " ";
    }
    
    void read_data(std::istream& is) override {
        TT a, b, c;
        if (is >> a >> b >> c) {
            cntr = Spot<TT>(a, b);
            rad_val = c;
            calc_dots();
        }
    }
    
    double area_value() const override {
        return 0.25 * std::sqrt(5.0 * (5.0 + 2.0 * std::sqrt(5.0))) * rad_val * rad_val;
    }
    
    bool compare(const BaseFigura<TT>& bf2) const override {
        const Figura5* f = dynamic_cast<const Figura5*>(&bf2);
        if (!f) return false;
        return cntr.check(f->cntr) && rad_val == f->rad_val;
    }
};

// Фигура с 6 углами
template<NumLike TT>
class Figura6 : public BaseFigura<TT> {
    Spot<TT> cntr;
    TT rad_val;
    
    void calc_dots() {
        this->dots.clear();
        for (int cnt = 0; cnt < 6; cnt++) {
            double ang = 2.0 * MY_PI * cnt / 6.0;
            TT x = cntr.x() + rad_val * std::cos(ang);
            TT y = cntr.y() + rad_val * std::sin(ang);
            this->dots.push_back(std::make_unique<Spot<TT>>(x, y));
        }
    }
    
public:
    Figura6() : cntr(0, 0), rad_val(0) { calc_dots(); }
    Figura6(TT cx, TT cy, TT r) : cntr(cx, cy), rad_val(r) { calc_dots(); }
    
    Spot<TT> center_point() const override { return cntr; }
    
    void show_dots(std::ostream& os) const override {
        os << "Figura6 dots: ";
        for (const auto& d : this->dots) os << *d << " ";
    }
    
    void read_data(std::istream& is) override {
        TT a, b, c;
        if (is >> a >> b >> c) {
            cntr = Spot<TT>(a, b);
            rad_val = c;
            calc_dots();
        }
    }
    
    double area_value() const override {
        return 1.5 * std::sqrt(3.0) * rad_val * rad_val;
    }
    
    bool compare(const BaseFigura<TT>& bf2) const override {
        const Figura6* f = dynamic_cast<const Figura6*>(&bf2);
        if (!f) return false;
        return cntr.check(f->cntr) && rad_val == f->rad_val;
    }
};

// Фигура с 8 углами
template<NumLike TT>
class Figura8 : public BaseFigura<TT> {
    Spot<TT> cntr;
    TT rad_val;
    
    void calc_dots() {
        this->dots.clear();
        for (int cnt = 0; cnt < 8; cnt++) {
            double ang = 2.0 * MY_PI * cnt / 8.0;
            TT x = cntr.x() + rad_val * std::cos(ang);
            TT y = cntr.y() + rad_val * std::sin(ang);
            this->dots.push_back(std::make_unique<Spot<TT>>(x, y));
        }
    }
    
public:
    Figura8() : cntr(0, 0), rad_val(0) { calc_dots(); }
    Figura8(TT cx, TT cy, TT r) : cntr(cx, cy), rad_val(r) { calc_dots(); }
    
    Spot<TT> center_point() const override { return cntr; }
    
    void show_dots(std::ostream& os) const override {
        os << "Figura8 dots: ";
        for (const auto& d : this->dots) os << *d << " ";
    }
    
    void read_data(std::istream& is) override {
        TT a, b, c;
        if (is >> a >> b >> c) {
            cntr = Spot<TT>(a, b);
            rad_val = c;
            calc_dots();
        }
    }
    
    double area_value() const override {
        return 2.0 * std::sqrt(2.0) * rad_val * rad_val;
    }
    
    bool compare(const BaseFigura<TT>& bf2) const override {
        const Figura8* f = dynamic_cast<const Figura8*>(&bf2);
        if (!f) return false;
        return cntr.check(f->cntr) && rad_val == f->rad_val;
    }
};

// Контейнер для хранения
template<class ItemType>
class Storage {
    std::shared_ptr<ItemType[]> items;
    size_t max_items;
    size_t item_count;
    
    void resize_storage(size_t new_max) {
        std::shared_ptr<ItemType[]> new_items(new ItemType[new_max]);
        for (size_t i = 0; i < item_count; i++) {
            new_items[i] = std::move(items[i]);
        }
        items = std::move(new_items);
        max_items = new_max;
    }
    
public:
    Storage() : items(nullptr), max_items(0), item_count(0) {}
    
    void add_item(const ItemType& item) {
        if (item_count >= max_items) {
            resize_storage(max_items == 0 ? 1 : max_items * 2);
        }
        items[item_count++] = item;
    }
    
    void add_item(ItemType&& item) {
        if (item_count >= max_items) {
            resize_storage(max_items == 0 ? 1 : max_items * 2);
        }
        items[item_count] = std::move(item);
        item_count++;
    }
    
    void remove_item(size_t pos) {
        if (pos >= item_count) return;
        for (size_t i = pos; i < item_count - 1; i++) {
            items[i] = std::move(items[i + 1]);
        }
        item_count--;
    }
    
    ItemType& get_item(size_t pos) {
        return items[pos];
    }
    
    const ItemType& get_item(size_t pos) const {
        return items[pos];
    }
    
    size_t size() const { return item_count; }
    
    double total_area() const {
        double sum = 0;
        for (size_t i = 0; i < item_count; i++) {
            sum += static_cast<double>(*items[i]);
        }
        return sum;
    }
    
    void display_all() const {
        for (size_t i = 0; i < item_count; i++) {
            std::cout << "Item " << i + 1 << ":\n";
            std::cout << "  " << *items[i] << "\n";
            std::cout << "  Center: " << items[i]->center_point() << "\n";
            std::cout << "  Area: " << static_cast<double>(*items[i]) << "\n\n";
        }
    }
};

int main() {
    std::cout << "Program start\n";
    std::cout << "Working with shapes\n\n";
    
    // Часть 1
    std::cout << "Part 1: Storage test\n";
    Storage<std::shared_ptr<BaseFigura<double>>> store1;
    
    store1.add_item(std::make_shared<Figura5<double>>(0, 0, 5.0));
    store1.add_item(std::make_shared<Figura6<double>>(2, 2, 3.0));
    store1.add_item(std::make_shared<Figura8<double>>(-1, -1, 4.0));
    
    store1.display_all();
    std::cout << "Total area: " << store1.total_area() << "\n\n";
    
    store1.remove_item(1);
    std::cout << "After remove:\n";
    store1.display_all();
    
    // Часть 2
    std::cout << "\nPart 2: Figura6 with int\n";
    Figura6<int> f6(0, 0, 10);
    std::cout << "Area: " << static_cast<double>(f6) << "\n";
    std::cout << "Center: " << f6.center_point() << "\n";
    f6.show_dots(std::cout);
    std::cout << "\n";
    
    // Часть 3
    std::cout << "\nPart 3: Input Figura5\n";
    std::cout << "Enter 3 numbers: ";
    Figura5<double> f5_input;
    std::cin >> f5_input;
    std::cout << "Area: " << static_cast<double>(f5_input) << "\n";
    std::cout << "Center: " << f5_input.center_point() << "\n";
    
    // Часть 4
    std::cout << "\nPart 4: Float shapes\n";
    Storage<std::shared_ptr<Figura6<float>>> store2;
    store2.add_item(std::make_shared<Figura6<float>>(0.0f, 0.0f, 2.0f));
    store2.add_item(std::make_shared<Figura6<float>>(1.0f, 1.0f, 1.5f));
    
    for (size_t i = 0; i < store2.size(); i++) {
        std::cout << "Shape " << i + 1 << " area: " 
                  << static_cast<double>(*store2.get_item(i)) << "\n";
    }
    
    std::cout << "\nPress Enter to end...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}
