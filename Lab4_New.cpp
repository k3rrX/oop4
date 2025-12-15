#include <iostream>
#include <cmath>

using namespace std;

#define PI_CHISLO 3.141592653589793

// точка
class tochka_dvum {
public:
    double xx;
    double yy;
    
    tochka_dvum() {
        xx = 0;
        yy = 0;
    }
    
    tochka_dvum(double x1, double y1) {
        xx = x1;
        yy = y1;
    }
    
    void pokazat() {
        cout << "(" << xx << "," << yy << ")";
    }
};

// 5 угольник
class figura_5 {
public:
    tochka_dvum centr_toch;
    double razmer_r;
    tochka_dvum massiv_toch[5];
    
    figura_5() {
        centr_toch = tochka_dvum(0, 0);
        razmer_r = 0;
        raschet_toch();
    }
    
    figura_5(double cx, double cy, double r) {
        centr_toch = tochka_dvum(cx, cy);
        razmer_r = r;
        raschet_toch();
    }
    
    void raschet_toch() {
        for(int i = 0; i < 5; i++) {
            double ugol = 2.0 * PI_CHISLO * i / 5.0;
            massiv_toch[i].xx = centr_toch.xx + razmer_r * cos(ugol);
            massiv_toch[i].yy = centr_toch.yy + razmer_r * sin(ugol);
        }
    }
    
    void pokazat_tochki() {
        cout << "5 ugol: ";
        for(int i = 0; i < 5; i++) {
            massiv_toch[i].pokazat();
            cout << " ";
        }
    }
    
    tochka_dvum centr_fig() {
        return centr_toch;
    }
    
    double ploshad_fig() {
        return 0.25 * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * razmer_r * razmer_r;
    }
    
    void prochitat_s_klav() {
        cout << "Vvedite 3 chisla: ";
        cin >> centr_toch.xx >> centr_toch.yy >> razmer_r;
        raschet_toch();
    }
};

// 6 угольник  
class figura_6 {
public:
    tochka_dvum centr_toch;
    double razmer_r;
    tochka_dvum massiv_toch[6];
    
    figura_6() {
        centr_toch = tochka_dvum(0, 0);
        razmer_r = 0;
        raschet_toch();
    }
    
    figura_6(double cx, double cy, double r) {
        centr_toch = tochka_dvum(cx, cy);
        razmer_r = r;
        raschet_toch();
    }
    
    void raschet_toch() {
        for(int i = 0; i < 6; i++) {
            double ugol = 2.0 * PI_CHISLO * i / 6.0;
            massiv_toch[i].xx = centr_toch.xx + razmer_r * cos(ugol);
            massiv_toch[i].yy = centr_toch.yy + razmer_r * sin(ugol);
        }
    }
    
    void pokazat_tochki() {
        cout << "6 ugol: ";
        for(int i = 0; i < 6; i++) {
            massiv_toch[i].pokazat();
            cout << " ";
        }
    }
    
    tochka_dvum centr_fig() {
        return centr_toch;
    }
    
    double ploshad_fig() {
        return 1.5 * sqrt(3.0) * razmer_r * razmer_r;
    }
};

// 8 угольник
class figura_8 {
public:
    tochka_dvum centr_toch;
    double razmer_r;
    tochka_dvum massiv_toch[8];
    
    figura_8() {
        centr_toch = tochka_dvum(0, 0);
        razmer_r = 0;
        raschet_toch();
    }
    
    figura_8(double cx, double cy, double r) {
        centr_toch = tochka_dvum(cx, cy);
        razmer_r = r;
        raschet_toch();
    }
    
    void raschet_toch() {
        for(int i = 0; i < 8; i++) {
            double ugol = 2.0 * PI_CHISLO * i / 8.0;
            massiv_toch[i].xx = centr_toch.xx + razmer_r * cos(ugol);
            massiv_toch[i].yy = centr_toch.yy + razmer_r * sin(ugol);
        }
    }
    
    void pokazat_tochki() {
        cout << "8 ugol: ";
        for(int i = 0; i < 8; i++) {
            massiv_toch[i].pokazat();
            cout << " ";
        }
    }
    
    tochka_dvum centr_fig() {
        return centr_toch;
    }
    
    double ploshad_fig() {
        return 2.0 * sqrt(2.0) * razmer_r * razmer_r;
    }
};

// массив для хранения
class hranilishche {
public:
    figura_5* massiv_5[100];
    figura_6* massiv_6[100];
    figura_8* massiv_8[100];
    int kolvo_5;
    int kolvo_6;
    int kolvo_8;
    
    hranilishche() {
        kolvo_5 = 0;
        kolvo_6 = 0;
        kolvo_8 = 0;
    }
    
    void dobavit_5(figura_5* f) {
        if(kolvo_5 < 100) {
            massiv_5[kolvo_5] = f;
            kolvo_5++;
        }
    }
    
    void dobavit_6(figura_6* f) {
        if(kolvo_6 < 100) {
            massiv_6[kolvo_6] = f;
            kolvo_6++;
        }
    }
    
    void dobavit_8(figura_8* f) {
        if(kolvo_8 < 100) {
            massiv_8[kolvo_8] = f;
            kolvo_8++;
        }
    }
    
    void udalit_5(int nomer) {
        if(nomer >= 0 && nomer < kolvo_5) {
            delete massiv_5[nomer];
            for(int i = nomer; i < kolvo_5 - 1; i++) {
                massiv_5[i] = massiv_5[i + 1];
            }
            kolvo_5--;
        }
    }
    
    double vsego_ploshad() {
        double summa = 0;
        for(int i = 0; i < kolvo_5; i++) {
            summa += massiv_5[i]->ploshad_fig();
        }
        for(int i = 0; i < kolvo_6; i++) {
            summa += massiv_6[i]->ploshad_fig();
        }
        for(int i = 0; i < kolvo_8; i++) {
            summa += massiv_8[i]->ploshad_fig();
        }
        return summa;
    }
    
    void pokazat_vse() {
        int nomer = 1;
        
        for(int i = 0; i < kolvo_5; i++) {
            cout << "Figura " << nomer << ":\n";
            massiv_5[i]->pokazat_tochki();
            cout << "\nCentr: ";
            massiv_5[i]->centr_fig().pokazat();
            cout << "\nPloshad: " << massiv_5[i]->ploshad_fig() << "\n\n";
            nomer++;
        }
        
        for(int i = 0; i < kolvo_6; i++) {
            cout << "Figura " << nomer << ":\n";
            massiv_6[i]->pokazat_tochki();
            cout << "\nCentr: ";
            massiv_6[i]->centr_fig().pokazat();
            cout << "\nPloshad: " << massiv_6[i]->ploshad_fig() << "\n\n";
            nomer++;
        }
        
        for(int i = 0; i < kolvo_8; i++) {
            cout << "Figura " << nomer << ":\n";
            massiv_8[i]->pokazat_tochki();
            cout << "\nCentr: ";
            massiv_8[i]->centr_fig().pokazat();
            cout << "\nPloshad: " << massiv_8[i]->ploshad_fig() << "\n\n";
            nomer++;
        }
    }
};

int main() {
    cout << "=== PROGRAMMA DLYA FIGUR ===\n\n";
    
    hranilishche h;
    
    // добавляем фигуры
    h.dobavit_5(new figura_5(0, 0, 5));
    h.dobavit_6(new figura_6(2, 2, 3));
    h.dobavit_8(new figura_8(-1, -1, 4));
    
    cout << "VSE FIGURI:\n";
    h.pokazat_vse();
    
    cout << "Obshaya ploshad: " << h.vsego_ploshad() << "\n\n";
    
    cout << "Udalim figuru nomer 2:\n";
    h.udalit_5(0); // удаляем первую
    
    cout << "Posle udaleniya:\n";
    h.pokazat_vse();
    
    // тест с вводом
    cout << "\nTEST S VVODOM:\n";
    figura_5 f5_new;
    f5_new.prochitat_s_klav();
    cout << "Ploshad: " << f5_new.ploshad_fig() << "\n";
    cout << "Centr: ";
    f5_new.centr_fig().pokazat();
    cout << "\n";
    
    // тест с разными типами
    cout << "\nTEST S RAZNYMI TIPAMI:\n";
    figura_6 f6_int(0, 0, 10);
    cout << "6 ugol s radiusom 10: " << f6_int.ploshad_fig() << "\n";
    cout << "Tochki: ";
    f6_int.pokazat_tochki();
    cout << "\n";
    
    cout << "\nKONEC PROGRAMMY\n";
    cout << "Najmite Enter...";
    cin.ignore();
    cin.get();
    
    return 0;
}
