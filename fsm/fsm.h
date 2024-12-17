// File : fsm.h
#ifndef FSM_H
#define FSM_H

#include <systemc.h>

SC_MODULE(fsm)
{
    // Inputs
    sc_in<bool> a, b, clk;

    // Output
    sc_out<bool> S;
    sc_out< sc_uint<2> > state_out; 

    // Process declaration
    void fsm_thread();

    // Constructor
    SC_CTOR(fsm)
    {
        SC_THREAD(fsm_thread);
        sensitive << clk.pos(); // Trigger the thread on the positive edge of the clock
    }

    // Destructor
    ~fsm()
    {
        // Cleanup if necessary
    }
};

#endif
