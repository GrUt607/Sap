CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCS = main.cpp Sap.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = sap_game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp Sap.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
