#include "systemc.h"
#include "FIR_4pts.h"
#include "driver.h"
#include "monitor.h"

SC_MODULE(TopModule) {
    sc_fifo<int> e;   
    sc_fifo<int> r;   
    FIR_4pts fir1;    
    Driver driver1;   // Driver instance
    Monitor monitor1; // Monitor instance

    SC_CTOR(TopModule) : fir1("FIR_4pts_Module"), driver1("Driver_Module"), monitor1("Monitor_Module") {
        fir1.e(e); 
        fir1.r(r);  
        driver1.e(e); 
        monitor1.r(r);
    }
};

int sc_main(int argc, char* argv[]) {
    TopModule top("TopModule");

    // Start the simulation
    sc_start(10, SC_NS);

    return 0;
}
