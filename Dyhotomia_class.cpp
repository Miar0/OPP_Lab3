#include "Dyhotomia_class.h"

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::f(double x) {
    return x - 2 + sin(1 / x);
}

double Dyhotomia_class::derivative(double x, double delta_x = 1e-6) {
    return (f(x + delta_x) - f(x)) / delta_x;
}

double Dyhotomia_class::dyhotomiaMethod() {
    while (!(f(a) * f(b) > 0)) {
        double c = (a + b) / 2;
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        if (abs(b - a) <= eps) {
            return (a + b) / 2;
        }
    }
    cout << "Немає розв'язку на промужку" << endl;
}

double Dyhotomia_class::newtonMethod() {
    double x = (a + b) / 2;

    if (f(x) * f(b) > 0) {
        x = a;
    } else if (f(x) * f(a) > 0) {
        x = b;
    }

    while (true){
        if (derivative(x) == 0) {
            cout << "Похідна дорівнює нулю, спробуйте інший інтервал" << endl;
            return NAN;
        }
        double xn = x - f(x) / derivative(x);

        if (fabs(xn - x) < eps or abs(f(xn)) < eps){
            return xn;
        }
        x = xn;
    }
}

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}
