CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRC = main.cpp \
      models/board.cpp \
      models/controller.cpp \
      models/task.cpp \
      factories/objectfactory.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = mtask

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
