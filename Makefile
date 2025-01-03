CXX = g++
EXEC = solarsystem
SOURCES = src/main.cpp src/planet.cpp src/star.cpp src/solar_system.cpp
OBJECTS = main.o planet.o star.o solar_system.o
LDFLAGS = -lglut -lGL -lGLU

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(EXEC)

%.o: src/%.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(EXEC) *.gdb *.o
