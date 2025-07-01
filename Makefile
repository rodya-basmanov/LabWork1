CXX = g++
CXXFLAGS = -I./include -std=c++17 -fopenmp
LDFLAGS = -lm -fopenmp

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SOURCES))

MAIN_OBJECT = $(BUILD_DIR)/main.o
LIB_OBJECTS = $(filter-out $(MAIN_OBJECT),$(OBJECTS))

TARGET = image
TEST_TARGET = run_tests

.PHONY: all clean test

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

test: $(BUILD_DIR) $(LIB_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(LIB_OBJECTS) $(TEST_OBJECTS) -o $(TEST_TARGET) $(LDFLAGS) -lgtest -lgtest_main -pthread

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

run_test: test
	./$(TEST_TARGET)