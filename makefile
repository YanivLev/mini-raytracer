CXX = clang++
CXXFLAGS = -std=c++17 -Wall -O3

main: main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp

run: main
	./main