GS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = main.o stack.o

SRCS = main.cpp queue.cpp

HEADERS = queue.h

All: 
	g++ main.cpp queue.cpp -o queue

f: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o queue
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
