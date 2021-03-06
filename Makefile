# Compile with debug option and all warnings on. ------------
CXXFLAGS = -g -Wall -O1 -std=c++11 -I/opt/local/include
LIBS = -L/opt/local/lib -lgmp -lgmpxx
CXX = g++

# Object modules comprising this application ----------------
OBJ = BBSTest.o Tester.o bbs.o Blum.o

# Build targets
TARGETS = tester

.PHONY: all clean
all: $(TARGETS)

tester: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LIBS)

# bbs.o: osx/bbs.o
# 	-cp osx/bbs.o .

Blum.o: osx/Blum.o
	-cp osx/Blum.o .

# Delete .o and exe files and force recompilation. ----------
clean:
	rm -f *.o $(TARGETS)

# Dependencies ----------------------------------------------
BBSTest.o: BBSTest.cpp Tester.hpp Blum.hpp bbs.hpp
Tester.o: Tester.cpp Tester.hpp Blum.hpp bbs.hpp
bbs.o: bbs.cpp bbs.hpp
# Blum.o: Blum.cpp Blum.hpp
