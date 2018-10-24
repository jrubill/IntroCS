# Makefile for cpp
# Can you alter it for C?
CXX = g++

CXXFLAGS = -g -Wall -std=c++11

SRC = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRC))

TARGET = prog

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

run:
	./$(TARGET)
