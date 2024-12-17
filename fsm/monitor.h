// File : monitor.h
#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<bool> m_a,m_b,m_clk,m_S;
	sc_in< sc_uint<2> > m_state;
	void prc_monitor();

	SC_CTOR(monitor) : m_a("m_a"),m_b("m_b"),
		m_clk("m_clk"),m_S("m_S"), m_state("m_state")
	{
		SC_METHOD(prc_monitor);
		sensitive << m_a << m_b << m_clk<< m_S << m_state;
	}
};

#endif // MONITOR_H
