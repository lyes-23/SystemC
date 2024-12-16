#include "monitor.h"

Monitor::Monitor(sc_module_name name) : sc_module(name) {
    // Create the VCD trace file to store signal transitions
    trace_file = sc_create_vcd_trace_file("monitor_trace");
    
    // Trace the signal that holds the filtered data
    sc_trace(trace_file, signal_r, "filtered_output");

    // Register the monitor_data function as a thread in the SystemC simulation
    SC_THREAD(monitor_data);
}

Monitor::~Monitor() {
    // Close the VCD trace file when simulation ends
    sc_close_vcd_trace_file(trace_file);
}

void Monitor::monitor_data() {
    while (true) {
        // Read data from the FIFO
        int result = r.read();
        
        // Write the result to the signal that is being traced
        signal_r.write(result);
        
        // Display the result in the terminal
        std::cout << "Filtered output: " << result << std::endl;
        
        // Wait for 1 ns (adjust based on your clock)
        wait(1, SC_NS);
    }
}
