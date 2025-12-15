#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <concepts>

using namespace std;

// проверка типа
template<typename T>
concept numtype = is_scalar_v<T>;

#ifndef PI_VAL
#define PI_VAL 3.14159265358979323846
#endif

// точка
template<numtype T>
struct tochka {
    T a, b;
    tochka(T x = 0, T y = 0) : a(x), b(y) {}
    
    T geta() const { return a; }
    T getb() const { return b; }
    
    friend ostream& operator<<(ostream& out, const tochka& t) {
        out << "(" << t.a << "," << t.b << ")";
        return out;
    }
    
    bool ravno(const tochka& t2) const {
        return a == t2.a && b == t2.b;
    }
};

// базовая фигура
template<numtype T>
class osnova {
protected:
    vector<unique_ptr<tochka<T>>> list;
    
public:
    virtual ~osnova() {}
    
    virtual tochka<T> seredina() const = 0;
    virtual void pokazat(ostream& out) const = 0;
    virtual void vvod(istream& in) = 0;
    virtual double ploshad() const = 0;
    
    friend ostream& operator<<(ostream& out, const osnova& o) {
        o.pokazat(out);
        return out;
    }
    
    friend istream& operator>>(istream& in, osnova& o) {
        o.vvod(in);
        return in;
    }
    
    virtual bool sravnit(const osnova& o2) const = 0;
    
    operator double() const { return ploshad(); }
};

// 5 угольник
template<numtype T>
class pyat : public osnova<T> {
    tochka<T> centr;
    T r;
    
    void raschet() {
        this->list.clear();
        for (int i = 0; i < 5; i++) {
            double ugol = 2.0 * PI_VAL * i / 5.0;
            T x = centr.geta() + r * cos(ugol);
            T y = centr.getb() + r * sin(ugol);
            this->list.push_back(make_unique<tochka<T>>(x, y));
        }
    }
    
public:
    pyat() : centr(0, 0), r(0) { raschet(); }
    pyat(T cx, T cy, T rad) : centr(cx, cy), r(rad) { raschet(); }
    
    tochka<T> seredina() const override { return centr; }
    
    void pokazat(ostream& out) const override {
        out << "pyat tochki: ";
        for (const auto& t : this->list) out << *t << " ";
    }
    
    void vvod(istream& in) override {
        T x, y, rad;
        if (in >> x >> y >> rad) {
            centr = tochka<T>(x, y);
            r = rad;
            raschet();
        }
    }
    
    double ploshad() const override {
        return 0.25 * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * r * r;
    }
    
    bool sravnit(const osnova<T>& o2) const override {
        const pyat* p = dynamic_cast<const pyat*>(&o2);
        if (!p) return false;
        return centr.ravno(p->centr) && r == p->r;
    }
};

// 6 угольник
template<numtype T>
class shest : public osnova<T> {
    tochka<T> centr;
    T r;
    
    void raschet() {
        this->list.clear();
        for (int i = 0; i < 6; i++) {
            double ugol = 2.0 * PI_VAL * i / 6.0;
            T x = centr.geta() + r * cos(ugol);
            T y = centr.getb() + r * sin(ugol);
            this->list.push_back(make_unique<tochka<T>>(x, y));
        }
    }
    
public:
    shest() : centr(0, 0), r(0) { raschet(); }
    shest(T cx, T cy, T rad) : centr(cx, cy), r(rad) { raschet(); }
    
    tochka<T> seredina() const override { return centr; }
    
    void pokazat(ostream& out) const override {
        out << "shest tochki: ";
        for (const auto& t : this->list) out << *t << " ";
    }
    
    void vvod(istream& in) override {
        T x, y, rad;
        if (in >> x >> y >> rad) {
            centr = tochka<T>(x, y);
            r = rad;
            raschet();
        }
    }
    
    double ploshad() const override {
        return 1.5 * sqrt(3.0) * r * r;
    }
    
    bool sravnit(const osnova<T>& o2) const override {
        const shest* s = dynamic_cast<const shest*>(&o2);
        if (!s) return false;
        return centr.ravno(s->centr) && r == s->r;
    }
};

// 8 угольник
template<numtype T>
class vosem : public osnova<T> {
    tochka<T> centr;
    T r;
    
    void raschet() {
        this->list.clear();
        for (int i = 0; i < 8; i++) {
            double ugol = 2.0 * PI_VAL * i / 8.0;
            T x = centr.geta() + r * cos(ugol);
            T y = centr.getb() + r * sin(ugol);
            this->list.push_back(make_unique<tochka<T>>(x, y));
        }
    }
    
public:
    vosem() : centr(0, 0), r(0) { raschet(); }
    vosem(T cx, T cy, T rad) : centr(cx, cy), r(rad) { raschet(); }
    
    tochka<T> seredina() const override { return centr; }
    
    void pokazat(ostream& out) const override {
        out << "vosem tochki: ";
        for (const auto& t : this->list) out << *t << " ";
    }
    
    void vvod(istream& in) override {
        T x, y, rad;
        if (in >> x >> y >> rad) {
            centr = tochka<T>(x, y);
            r = rad;
            raschet();
        }
    }
    
    double ploshad() const override {
        return 2.0 * sqrt(2.0) * r * r;
    }
    
    bool sravnit(const osnova<T>& o2) const override {
        const vosem* v = dynamic_cast<const vosem*>(&o2);
        if (!v) return false;
        return centr.ravno(v->centr) && r == v->r;
    }
};

// массив
template<class typ>
class massiv {
    shared_ptr<typ[]> data;
    size_t cap;
    size_t sz;
    
    void uvelichit(size_t newcap) {
        shared_ptr<typ[]> newdata(new typ[newcap]);
        for (size_t i = 0; i < sz; i++) {
            newdata[i] = move(data[i]);
        }
        data = move(newdata);
        cap = newcap;
    }
    
public:
    massiv() : data(nullptr), cap(0), sz(0) {}
    
    void dobavit(const typ& item) {
        if (sz >= cap) {
            uvelichit(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = item;
    }
    
    void dobavit(typ&& item) {
        if (sz >= cap) {
            uvelichit(cap == 0 ? 1 : cap * 2);
        }
        data[sz] = move(item);
        sz++;
    }
    
    void udalit(size_t pos) {
        if (pos >= sz) return;
        for (size_t i = pos; i < sz - 1; i++) {
            data[i] = move(data[i + 1]);
        }
        sz--;
    }
    
    typ& operator[](size_t pos) {
        return data[pos];
    }
    
    const typ& operator[](size_t pos) const {
        return data[pos];
    }
    
    size_t razmer() const { return sz; }
    
    double vseploshad() const {
        double sum = 0;
        for (size_t i = 0; i < sz; i++) {
            sum += static_cast<double>(*data[i]);
        }
        return sum;
    }
    
    void pokazatvse() const {
        for (size_t i = 0; i < sz; i++) {
            cout << "Figura " << i + 1 << ":\n";
            cout << "  " << *data[i] << "\n";
            cout << "  Seredina: " << data[i]->seredina() << "\n";
            cout << "  Ploshad: " << static_cast<double>(*data[i]) << "\n\n";
        }
    }
};

int main() {
    cout << "Start programmi\n";
    cout << "Rabota s figurami\n\n";
    
    // test 1
    cout << "Test 1: massiv figur\n";
    massiv<shared_ptr<osnova<double>>> m1;
    
    m1.dobavit(make_shared<pyat<double>>(0, 0, 5.0));
    m1.dobavit(make_shared<shest<double>>(2, 2, 3.0));
    m1.dobavit(make_shared<vosem<double>>(-1, -1, 4.0));
    
    m1.pokazatvse();
    cout << "Obshaya ploshad: " << m1.vseploshad() << "\n\n";
    
    m1.udalit(1);
    cout << "Posle udaleniya:\n";
    m1.pokazatvse();
    
    // test 2
    cout << "\nTest 2: shest s int\n";
    shest<int> s1(0, 0, 10);
    cout << "Ploshad: " << static_cast<double>(s1) << "\n";
    cout << "Seredina: " << s1.seredina() << "\n";
    s1.pokazat(cout);
    cout << "\n";
    
    // test 3
    cout << "\nTest 3: Vvod pyat\n";
    cout << "Vvedite 3 chisla: ";
    pyat<double> p1;
    cin >> p1;
    cout << "Ploshad: " << static_cast<double>(p1) << "\n";
    cout << "Seredina: " << p1.seredina() << "\n";
    
    // test 4
    cout << "\nTest 4: Float figuri\n";
    massiv<shared_ptr<shest<float>>> m2;
    m2.dobavit(make_shared<shest<float>>(0.0f, 0.0f, 2.0f));
    m2.dobavit(make_shared<shest<float>>(1.0f, 1.0f, 1.5f));
    
    for (size_t i = 0; i < m2.razmer(); i++) {
        cout << "Figura " << i + 1 << " ploshad: " 
             << static_cast<double>(*m2[i]) << "\n";
    }
    
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
    return 0;
}
