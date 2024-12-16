#ifndef FIR_4PTS_H
#define FIR_4PTS_H
#include <systemc.h>

SC_MODULE(FIR_4pts){
    public: 
    sc_fifo_in<int> e;
    sc_fifo_out<int> r;

    SC_CTOR(FIR_4pts){
        SC_THREAD(do_fir);
    }
    void do_fir();
};

#endif