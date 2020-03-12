
#variables
CXX = g++
CXXFLAGS = -Wall -g

###############################################################################


#target for the executable file
logger_test: logger_test.o logger.o 
	$(CXX) $(CXXFLAGS) -o logger_test logger_test.o logger.o

#target for the logger_test.o
logger_test.o: longer_test.cc logger.h
	$(CXX) $(CXXFLAGS) -c longer_test.cc

###############################################################################

#headers needed for the targets (what is used to make the .o files)
logger.o: logger.h
