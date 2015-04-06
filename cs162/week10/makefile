XXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = main.o

SRCS = main.cpp

HEADERS = final.h

All: 
	g++ main.cpp -o final

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o final
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
