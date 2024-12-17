// File : fsm_main.cpp
#include "driver.h"
#include "monitor.h"
#include "fsm.h"

int sc_main(int argc,char *argv[])
{
	sc_signal<bool> t_a("a"), t_b("b"), t_clk("clk"), t_S("S");
	sc_signal< sc_uint<2> > t_state("state");
 

	driver d1("GenerateWaveforms");
	// Connect using named association:
	d1.d_a(t_a);
	d1.d_b(t_b);
	d1.clk(t_clk);

	monitor mo1("MonitorWaveforms");
    mo1.m_a(t_a); // Corrected to named binding
    mo1.m_b(t_b);
    mo1.m_clk(t_clk);
    mo1.m_S(t_S);
    mo1.m_state(t_state); // Bind the FSM state signal

    // Instantiate the FSM module
    fsm fsm1("FSM");
    fsm1.a(t_a);
    fsm1.b(t_b);
    fsm1.clk(t_clk);
    fsm1.S(t_S);
    fsm1.state_out(t_state); // Assuming FSM outputs its state as sc_uint<2>

	sc_trace_file* tfp = sc_create_vcd_trace_file("fsm_main");
	sc_trace(tfp, t_a, t_a.name());
    sc_trace(tfp, t_b, t_b.name());
    sc_trace(tfp, t_clk, t_clk.name());
    sc_trace(tfp, t_S, t_S.name());
	sc_trace(tfp, t_state, t_state.name()); 

   	sc_start(100,SC_NS);
	sc_close_vcd_trace_file(tfp);

	return 0;
}