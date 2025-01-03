CXX = g++
EXEC = solarsystem

SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/planet.cpp $(SRC_DIR)/star.cpp $(SRC_DIR)/solar_system.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

LDFLAGS = -lglut -lGL -lGLU

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) -c $< -o $@

clean:
	rm -f $(EXEC) *.gdb $(BUILD_DIR)/*.o

.PHONY: all clean
