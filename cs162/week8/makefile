XXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = main.o

SRCS = main.cpp

HEADERS = tournament.h

All: 
	g++ main.cpp -o tournament

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o tournament
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
