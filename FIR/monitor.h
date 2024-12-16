#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"
#include <fstream>  // For file output

// Monitor module to read data from a FIFO and output to a VCD file
SC_MODULE(Monitor) {
public:
    sc_fifo_in<int> r;  // FIFO input to receive filtered data
    sc_trace_file* trace_file;  // Trace file for VCD output
    sc_signal<int> signal_r;  // Signal to hold the value of r for tracing

    SC_CTOR(Monitor);  // Constructor declaration
    ~Monitor();  // Destructor declaration

private:
    // Function to monitor and display the filtered data
    void monitor_data();
};

#endif  // MONITOR_H
