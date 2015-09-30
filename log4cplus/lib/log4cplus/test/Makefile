INCLUDE=-I ../include
LIB_DIR =-L ../lib
LIBARY = -lpthread -llog4cplus

CFLAG = -g -O3 -Wall -mcmodel=medium -Wno-deprecated
VERSION = $(shell svn log -l1 | awk -F'|' 'NR==2{print $$1}')
AUTHOR = $(shell svn log -l1 | awk -F'|' 'NR==2{print $$2}' | tr -d ' ')

SERVICE_NAME = test_log

all: server

log: test_log.o
	g++ -o ${SERVICE_NAME} ${CFLAG} ${INCLUDE}  ${LIB_DIR} \
    test_log.o \
    ${LIBARY}

    
test_log.o: test_log.cpp
	gcc -c ${INCLUDE} ${CFLAG} ./test_log.cpp

log_file: log_file.o
	g++ -o log_file ${CFLAG} ${INCLUDE} ${LIB_DIR} \
	log_file.o \
	${LIBARY}

log_file.o: log_file.cpp
	g++ -c ${INCLUDE} ${CFLAG} ./log_file.cpp


clean: main_clean
main_clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ${SERVICE_NAME}
glog:
	 g++ test_glog.cc -o test_glog -I ../lib/glog/include/ -I ../lib/gflags/include/ -L ../lib/glog/lib/ -L ../lib/gflags/lib/  -lpthread -lglog -lgflags
#g++ test1.cpp -o test -I ../lib/log4cplus/include/ -L ../lib/log4cplus/lib/ -lpthread -llog4cplus 
