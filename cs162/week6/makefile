XX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = main.o

SRCS = main.cpp

HEADERS = combat.h

All: 
	g++ main.cpp -o combat

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o combat
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
