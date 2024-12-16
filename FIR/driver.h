#ifndef DRIVER_H
#define DRIVER_H

#include "systemc.h"

SC_MODULE(Driver) {
    public:
        sc_fifo_out<int> e;  // FIFO output to send data to FIR filter

        SC_CTOR(Driver) {
            SC_THREAD(send_data);  // Trigger the sending of data
        }

    private:
        // Function to send data into the FIFO
        void send_data() {
            // Send a sequence of test samples to the FIR filter
            e.write(1);
            e.write(2);
            e.write(3);
            e.write(4);
            e.write(5);
            e.write(6);
            e.write(7);
            e.write(8);
            e.write(9);
            e.write(10);
        }
};

#endif
