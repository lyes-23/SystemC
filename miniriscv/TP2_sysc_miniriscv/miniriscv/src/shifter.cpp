#include "shifter.h"

void shifter::operation() {
    sc_uint<32> input_val = DIN_SE.read();
    sc_uint<5> shift_val = SHIFT_VAL_SE.read();
    sc_uint<2> cmd = CMD_SE.read();
    sc_uint<32> output_val;

    switch (cmd) {
        case 0: // Shift Left Logical (sll)
            output_val = input_val << shift_val;
            break;
        case 1: // Shift Right Logical (srl)
            output_val = input_val >> shift_val;
            break;
        case 2: // Shift Right Arithmetic (sra)
            output_val = static_cast<sc_int<32>>(input_val) >> shift_val;
            break;
        default:
            output_val = 0; // Default case (invalid command)
            break;
    }

    DOUT_SE.write(output_val);

}

void shifter::trace(sc_trace_file* tf) {
    sc_trace(tf, DIN_SE, GET_NAME(DIN_SE));
    sc_trace(tf, SHIFT_VAL_SE, GET_NAME(SHIFT_VAL_SE));
    sc_trace(tf, CMD_SE, GET_NAME(CMD_SE));
    sc_trace(tf, DOUT_SE, GET_NAME(DOUT_SE));
}
