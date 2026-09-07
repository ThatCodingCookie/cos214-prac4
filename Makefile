CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = taskforge

SOURCES = main.cpp \
          WorkComponent.cpp \
          WorkComponentDecorator.cpp \
          WorkGroup.cpp \
          Task.cpp \
          DepthFirstIterator.cpp \
          PendingInspectionIterator.cpp \
          PlannedState.cpp \
          InProgressState.cpp \
          BlockedState.cpp \
          CompletedState.cpp \
          SafetyInspectionDecorator.cpp \
          PermitComplianceDecorator.cpp \
          SubcontractorDecorator.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

gdb: $(TARGET)
	gdb ./$(TARGET)

.PHONY: all clean run valgrind gdb