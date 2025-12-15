#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

#define PI_CHISLO 3.14159265358979323846

// шаблон для чисел
template<typename T>
class chislo_type {
public:
    static bool proverka() {
        return is_scalar_v<T>;
    }
};

// точка
template<typename T>
class tochka {
public:
    T x;
    T y;
    
    tochka(T xx = 0, T yy = 0) {
        x = xx;
        y = yy;
    }
    
    T get_x() { return x; }
    T get_y() { return y; }
    
    void vivod() {
        cout << "(" << x << " " << y << ")";
    }
    
    bool ravna(tochka t) {
        return x == t.x && y == t.y;
    }
};

// база для фигур
template<typename T>
class figura_baza {
public:
    vector<tochka<T>*> tochki;
    
    virtual ~figura_baza() {
        for(auto t : tochki) delete t;
    }
    
    virtual tochka<T> centr() = 0;
    virtual void pokazat_tochki() = 0;
    virtual void prochitat() = 0;
    virtual double plosh() = 0;
    
    virtual bool sravn(figura_baza* drugoi) = 0;
};

// 5 угольник
template<typename T>
class pyatugol : public figura_baza<T> {
public:
    tochka<T> centr_tochka;
    T radius;
    
    pyatugol() {
        centr_tochka = tochka<T>(0, 0);
        radius = 0;
        pereschitat();
    }
    
    pyatugol(T cx, T cy, T r) {
        centr_tochka = tochka<T>(cx, cy);
        radius = r;
        pereschitat();
    }
    
    void pereschitat() {
        for(auto t : this->tochki) delete t;
        this->tochki.clear();
        
        for(int i = 0; i < 5; i++) {
            double ugol = 2.0 * PI_CHISLO * i / 5.0;
            T x = centr_tochka.x + radius * cos(ugol);
            T y = centr_tochka.y + radius * sin(ugol);
            this->tochki.push_back(new tochka<T>(x, y));
        }
    }
    
    tochka<T> centr() override {
        return centr_tochka;
    }
    
    void pokazat_tochki() override {
        cout << "pyatugol: ";
        for(auto t : this->tochki) {
            t->vivod();
            cout << " ";
        }
    }
    
    void prochitat() override {
        T a, b, c;
        cin >> a >> b >> c;
        centr_tochka = tochka<T>(a, b);
        radius = c;
        pereschitat();
    }
    
    double plosh() override {
        return 0.25 * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * radius * radius;
    }
    
    bool sravn(figura_baza<T>* drugoi) override {
        auto p = dynamic_cast<pyatugol<T>*>(drugoi);
        if(!p) return false;
        return centr_tochka.ravna(p->centr_tochka) && radius == p->radius;
    }
    
    operator double() {
        return plosh();
    }
};

// 6 угольник
template<typename T>
class shestiugol : public figura_baza<T> {
public:
    tochka<T> centr_tochka;
    T radius;
    
    shestiugol() {
        centr_tochka = tochka<T>(0, 0);
        radius = 0;
        pereschitat();
    }
    
    shestiugol(T cx, T cy, T r) {
        centr_tochka = tochka<T>(cx, cy);
        radius = r;
        pereschitat();
    }
    
    void pereschitat() {
        for(auto t : this->tochki) delete t;
        this->tochki.clear();
        
        for(int i = 0; i < 6; i++) {
            double ugol = 2.0 * PI_CHISLO * i / 6.0;
            T x = centr_tochka.x + radius * cos(ugol);
            T y = centr_tochka.y + radius * sin(ugol);
            this->tochki.push_back(new tochka<T>(x, y));
        }
    }
    
    tochka<T> centr() override {
        return centr_tochka;
    }
    
    void pokazat_tochki() override {
        cout << "shestiugol: ";
        for(auto t : this->tochki) {
            t->vivod();
            cout << " ";
        }
    }
    
    void prochitat() override {
        T a, b, c;
        cin >> a >> b >> c;
        centr_tochka = tochka<T>(a, b);
        radius = c;
        pereschitat();
    }
    
    double plosh() override {
        return 1.5 * sqrt(3.0) * radius * radius;
    }
    
    bool sravn(figura_baza<T>* drugoi) override {
        auto s = dynamic_cast<shestiugol<T>*>(drugoi);
        if(!s) return false;
        return centr_tochka.ravna(s->centr_tochka) && radius == s->radius;
    }
    
    operator double() {
        return plosh();
    }
};

// 8 угольник
template<typename T>
class vosmiugol : public figura_baza<T> {
public:
    tochka<T> centr_tochka;
    T radius;
    
    vosmiugol() {
        centr_tochka = tochka<T>(0, 0);
        radius = 0;
        pereschitat();
    }
    
    vosmiugol(T cx, T cy, T r) {
        centr_tochka = tochka<T>(cx, cy);
        radius = r;
        pereschitat();
    }
    
    void pereschitat() {
        for(auto t : this->tochki) delete t;
        this->tochki.clear();
        
        for(int i = 0; i < 8; i++) {
            double ugol = 2.0 * PI_CHISLO * i / 8.0;
            T x = centr_tochka.x + radius * cos(ugol);
            T y = centr_tochka.y + radius * sin(ugol);
            this->tochki.push_back(new tochka<T>(x, y));
        }
    }
    
    tochka<T> centr() override {
        return centr_tochka;
    }
    
    void pokazat_tochki() override {
        cout << "vosmiugol: ";
        for(auto t : this->tochki) {
            t->vivod();
            cout << " ";
        }
    }
    
    void prochitat() override {
        T a, b, c;
        cin >> a >> b >> c;
        centr_tochka = tochka<T>(a, b);
        radius = c;
        pereschitat();
    }
    
    double plosh() override {
        return 2.0 * sqrt(2.0) * radius * radius;
    }
    
    bool sravn(figura_baza<T>* drugoi) override {
        auto v = dynamic_cast<vosmiugol<T>*>(drugoi);
        if(!v) return false;
        return centr_tochka.ravna(v->centr_tochka) && radius == v->radius;
    }
    
    operator double() {
        return plosh();
    }
};

// массив
template<typename T>
class massiv_figur {
    T** data;
    int capacity;
    int size;
    
    void uvelichit() {
        int noviy = capacity == 0 ? 1 : capacity * 2;
        T** noviy_massiv = new T*[noviy];
        
        for(int i = 0; i < size; i++) {
            noviy_massiv[i] = data[i];
        }
        
        delete[] data;
        data = noviy_massiv;
        capacity = noviy;
    }
    
public:
    massiv_figur() {
        data = nullptr;
        capacity = 0;
        size = 0;
    }
    
    ~massiv_figur() {
        for(int i = 0; i < size; i++) {
            delete data[i];
        }
        delete[] data;
    }
    
    void dobavit(T* figura) {
        if(size >= capacity) {
            uvelichit();
        }
        data[size] = figura;
        size++;
    }
    
    void udalit(int index) {
        if(index < 0 || index >= size) return;
        
        delete data[index];
        
        for(int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
    
    T* get(int index) {
        if(index < 0 || index >= size) return nullptr;
        return data[index];
    }
    
    int kolvo() {
        return size;
    }
    
    double vsego_ploshad() {
        double sum = 0;
        for(int i = 0; i < size; i++) {
            sum += (double)(*data[i]);
        }
        return sum;
    }
    
    void pokazat_vse() {
        for(int i = 0; i < size; i++) {
            cout << "Figura " << i+1 << ":\n";
            data[i]->pokazat_tochki();
            cout << "\nCentr: ";
            data[i]->centr().vivod();
            cout << "\nPloshad: " << (double)(*data[i]) << "\n\n";
        }
    }
};

int main() {
    cout << "START\n\n";
    
    // тест 1
    cout << "TEST 1:\n";
    massiv_figur<figura_baza<double>> m;
    
    m.dobavit(new pyatugol<double>(0, 0, 5));
    m.dobavit(new shestiugol<double>(2, 2, 3));
    m.dobavit(new vosmiugol<double>(-1, -1, 4));
    
    m.pokazat_vse();
    cout << "Vsego ploshad: " << m.vsego_ploshad() << "\n\n";
    
    m.udalit(1);
    cout << "Posle udaleniya:\n";
    m.pokazat_vse();
    
    // тест 2
    cout << "\nTEST 2:\n";
    shestiugol<int> s(0, 0, 10);
    cout << "Ploshad: " << (double)s << "\n";
    cout << "Centr: ";
    s.centr().vivod();
    cout << "\nTochki: ";
    s.pokazat_tochki();
    cout << "\n";
    
    // тест 3
    cout << "\nTEST 3:\n";
    cout << "Vvedite 3 chisla: ";
    pyatugol<double> p;
    p.prochitat();
    cout << "Ploshad: " << (double)p << "\n";
    cout << "Centr: ";
    p.centr().vivod();
    cout << "\n";
    
    // тест 4
    cout << "\nTEST 4:\n";
    massiv_figur<shestiugol<float>> m2;
    m2.dobavit(new shestiugol<float>(0, 0, 2));
    m2.dobavit(new shestiugol<float>(1, 1, 1.5));
    
    for(int i = 0; i < m2.kolvo(); i++) {
        cout << "Figura " << i+1 << " ploshad: " << (double)(*m2.get(i)) << "\n";
    }
    
    cout << "\nEND\nPress Enter...";
    cin.ignore();
    cin.get();
    
    return 0;
}
