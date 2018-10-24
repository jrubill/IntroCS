# automatic C++ Makefile Generator

with open("Makefile", "w") as f:
	f.write("# C++ Makefile\n\n")
	f.write("CXX = g++\n\n")
	f.write("CXXFLAGS = -g -Wall -std=c++11\n\n")
	f.write("SRC = $(wildcard *.cpp)\n\n")
	f.write("OBJS = $(patsubst %.cpp, %.o, $(SRC))\n\n")
	f.write("TARGET = prog\n\n")
	f.write("%.o: %.cpp %.h\n\t$(CXX) $(CXXFLAGS) -c $< -o $@\n\n")
	f.write("all: $(OBJS)\n\t$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)\n\n")
	f.write("clean:\n\t rm -f $(OBJS) $(TARGET)\n\n")
	f.write("run:\n\t./$(TARGET)")
