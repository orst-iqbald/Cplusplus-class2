GS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = Program.o FibonacciR.o FibonacciNR.o

SRCS = Program.cpp FibonacciR.cpp FibonacciNR.cpp

HEADERS = FibonacciR.h FibonacciNR.h

All: 
	g++ Program.cpp FibonacciR.cpp FibonacciNR.cpp -o FibonacciR.h FibonacciNR.h

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Program
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
