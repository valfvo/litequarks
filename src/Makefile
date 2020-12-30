CXX = g++
CXXFLAGS = -Wall -Wextra -Wfatal-errors -std=c++17 -MMD

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: main.exe

main.exe: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)
