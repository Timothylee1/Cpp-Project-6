# name of C++ compiler
CXX       = g++
# options to C++ compiler
CXX_FLAGS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror
# flag to linker to make it link with math library
LDLIBS    = -lm
# list of object files
OBJS      = q-driver.o q.o
# name of executable program
EXEC      = q.out

# by convention the default target (the target that is built when writing
# only make on the command line) should be called all and it should
# be the first target in a makefile
all : $(EXEC)

# however, the problem that arises with the previous rule is that make
# will think all is the name of the target file that should be created
# so, we tell make that all is not a file name
.PHONY : all

# this rule says that target $(EXEC) will be built if prerequisite
# files $(OBJS) have changed more recently than $(EXEC)
# text $(EXEC) will be replaced with value q.out
# text $(OBJS) will be substituted with list of prerequisites in line 10
# line 31 says to build $(EXEC) using command $(CXX) with
# options $(CXX_FLAGS) specified on line 6
$(EXEC) : $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(EXEC) $(LDLIBS)

# target qdriver.o depends on both qdriver.cpp and q.h
# and is created with command $(CXX) given the options $(CXX_FLAGS)
q-driver.o : q-driver.cpp q.hpp
	$(CXX) $(CXX_FLAGS) -c q-driver.cpp -o q-driver.o
	
# target q.o depends on both q.cpp and q.hpp
# and is created with command $(CXX) given the options $(CXX_FLAGS)
q.o : q.cpp q.hpp
	$(CXX) $(CXX_FLAGS) -c q.cpp -o q.o

# says that clean is not the name of a target file but simply the name for
# a recipe to be executed when an explicit request is made
.PHONY : clean
# clean is a target with no prerequisites;
# typing the command in the shell: make clean
# will only execute the command which is to delete the object files
clean :
	rm -f $(OBJS) $(EXEC)

# says that rebuild is not the name of a target file but simply the name
# for a recipe to be executed when an explicit request is made
.PHONY : rebuild
# rebuild is for starting over by removing cleaning up previous builds
# and starting a new one
rebuild :
	$(MAKE) clean
	$(MAKE)

.PHONY : test
test : $(EXEC)
	./$(EXEC) english-words.txt your-pig-latin-words.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-pig-latin-words.txt pig-latin-words.txt