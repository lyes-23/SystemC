CXX         = g++
CXXFLAGS    = -I/home/skaikru/systemc/include -L/home/skaikru/systemc/lib-linux64 -lsystemc -lm
SRC         = FIR.cpp TopModule.cpp monitor.cpp
OUT         = FIR

# Default target
run: $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)
