CXX = clang++
CXXFLAGS = -std=c++17 -O3

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main 

run: main
	./main > image.ppm

clean: 
	rm -f main image.ppm