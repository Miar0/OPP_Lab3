#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <cmath>
#include <iostream>

using namespace std;

class Dyhotomia_class {
    double a;
    double b;
    double eps;

    public:
        Dyhotomia_class();
        ~Dyhotomia_class();
        void setVolumes(double vol_a, double vol_b);
        void setTolerance(double vol_eps);
        double dyhotomiaMethod();
        double newtonMethod();
};

#endif
