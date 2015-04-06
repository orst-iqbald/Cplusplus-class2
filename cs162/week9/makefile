XXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = main.o stack.o

SRCS = main.cpp stack.cpp

HEADERS = stack.h

All: 
	g++ main.cpp stack.cpp -o stack

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o stack
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
