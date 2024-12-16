// File : monitor.cpp
#include "monitor.h"

void monitor::prc_monitor()
{
	cout << "At time " << sc_time_stamp() << "::";
	cout << "(a, b, clk): ";
	cout << m_a << m_b << m_clk;
	cout << " (S): " << m_S << endl;
	cout << " (state): " << m_state << endl;
}

