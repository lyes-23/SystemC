// File : fsm.cpp
#include "fsm.h"

void fsm::fsm_thread()
{
    // Define the states of the FSM
    typedef enum {S0 = 0, S1 = 1, S2 = 2, S3 = 3} state_e;
    state_e state = S0;

    while (true)
    {
        wait(); // Synchronize with the clock

        S.write(false); // Default output
        state_out.write(static_cast< sc_uint<2> > (state)); // Write state to output signal

        switch (state)
        {
            case S0:
                if (a.read())
                    state = S1;
                else
                    state = S0;
                break;

            case S1:
                if (b.read())
                    state = S2;
                else
                    state = S1;
                break;

            case S2:
                if (!a.read())
                    state = S1;
                else if (b.read())
                    state = S3; // Transition to S3 if b becomes true
                break;

            case S3:
                if (!b.read())
                    state = S2;
                else
                    state = S3;
                break;

            default:
                state = S0; // Reset to S0 for invalid states
                break;
        }

        if (state == S3)
        {
            S.write(true); // Set the output in state S3
        }
    }
}
