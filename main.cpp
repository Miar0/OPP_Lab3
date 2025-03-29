#include <iomanip>
#include <Windows.h>
#include "Dyhotomia_class.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Dyhotomia_class * dyh = new Dyhotomia_class();
    dyh -> setVolumes(0.9, 2);
    dyh -> setTolerance(1e-6);
    double err = dyh -> dyhotomiaMethod();
    double err1 = dyh -> newtonMethod();

    cout << err << endl;
    cout << err1 << endl;

    delete dyh;
    return 0;
}