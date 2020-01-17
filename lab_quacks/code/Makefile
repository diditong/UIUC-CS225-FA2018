EX1EXENAME = ex1
EX2EXENAME = ex2
EX3EXENAME = ex3
EX1OBJS = main_ex1.o
EX2OBJS = main_ex2.o
EX3OBJS = main_ex3.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm

all : $(EX1EXENAME) $(EX2EXENAME) $(EX3EXENAME)

$(EX1EXENAME) : $(EX1OBJS)
	$(LD) $(EX1OBJS) $(LDFLAGS) -o $(EX1EXENAME)

$(EX2EXENAME) : $(EX2OBJS)
	$(LD) $(EX2OBJS) $(LDFLAGS) -o $(EX2EXENAME)

$(EX3EXENAME) : $(EX3OBJS)
	$(LD) $(EX3OBJS) $(LDFLAGS) -o $(EX3EXENAME)

main_ex1.o : main_ex1.cpp
	$(CXX) $(CXXFLAGS) main_ex1.cpp

main_ex2.o : main_ex2.cpp
	$(CXX) $(CXXFLAGS) main_ex2.cpp

main_ex3.o : main_ex3.cpp
	$(CXX) $(CXXFLAGS) main_ex3.cpp

clean :
	-rm -f *.o $(EX1EXENAME) $(EX2EXENAME) $(EX3EXENAME)
