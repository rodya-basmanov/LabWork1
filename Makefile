TARGET = image

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = main.cpp bmp.cpp image.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean