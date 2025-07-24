CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN = mtask

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
