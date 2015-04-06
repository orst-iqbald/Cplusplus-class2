CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = grocery.o main.o open.o

SRCS = main.cpp grocery.cpp open.cpp

HEADERS = grocery.h

All: 
	g++ main.cpp grocery.cpp -o grocery

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o grocery
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
