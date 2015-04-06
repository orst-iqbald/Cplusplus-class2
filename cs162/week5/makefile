XX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = encryption.o main.o

SRCS = main.cpp encryption.cpp

HEADERS = encryption.h

All: 
	g++ main.cpp encryption.cpp -o encryption

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o encryption
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

