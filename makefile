#
# Sam Chew
# 933191613
#
# CS325_2018Winter
# TSP Project Group 14


# compiler specific variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

# project specific variables
TOPPRG = tsp_group14
ZIPID = CS325_TSP_Group14.zip

OBJS = chews_tsp.o tspCity.o tspFileHandler.o

SRCS = chews_tsp.cpp tspCity.cpp tspFileHandler.cpp

HEADERS = tspCity.hpp tspFileHandler.hpp

UTILTXT = 


# makefile main content
${TOPPRG}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${TOPPRG}
	@for i in . . . . . . .; do \
		echo $i; \
	done

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


.PHONY : cleantsp
cleantsp :
	rm ${TOPPRG} $(OBJS) ${UTILTXT} *.tour


.PHONY : zip
zip :
	zip -D ${ZIPID} ${HEADERS} ${SRCS} ${UTILTXT} README.txt makefile



