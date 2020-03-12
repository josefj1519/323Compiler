
#variables
CXX = g++
CXXFLAGS = -Wall -g

###############################################################################


#target for the executable file
varcheck_test: varcheck_test.o var_checker.o 
	$(CXX) $(CXXFLAGS) -o varcheck_test varcheck_test.o var_checker.o



###############################################################################

#headers needed for the targets (what is used to make the .o files)
var_checker.o: var_checker.h
