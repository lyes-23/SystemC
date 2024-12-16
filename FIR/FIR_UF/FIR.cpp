#include <systemc.h>
#include "FIR_4pts.h"

int X[5] = {0,0,0,0};
double H[5] = { -0.1, -0.2, 1.6, -0.1, -0.2};

int FIR(int xn){
    for (int i = 0; i < 4; i++) {
        X[i + 1] = X[i];
        };

    X[0] = xn;
    double r = 0;

    for (int i = 0; i < 5; i++) {
        r += X[i] * H[i];
    }
    return round(r);
}

void FIR_4pts::do_fir(){
    int xn;
    while (true) {
        
        xn = e.read();
        int result = FIR(xn);
        r.write(result);
    }
}