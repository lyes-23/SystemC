// File : driver.cpp
#include "driver.h"
//#include<systemc.h>

void driver::prc_driver()
{
	 
	sc_logic clk_t = SC_LOGIC_0; ;
	clk_t = '0';
	sc_uint <2> pattern;
	pattern = 0 ;

	while (1)
	{
		 clk = (clk_t == SC_LOGIC_1); // Convert sc_logic to bool
        d_a = pattern[0];
        d_b = pattern[1];
        wait(5, SC_NS);
        clk_t = (clk_t == SC_LOGIC_1) ? SC_LOGIC_0 : SC_LOGIC_1; // Toggle sc_logic
        pattern++;
	}
}

