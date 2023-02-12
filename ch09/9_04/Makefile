SRC = $(wildcard ./*.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))
TARGET = main

CC = $(CXX)

$(TARGET) : $(OBJ)

run :
	./$(TARGET)

.PHONY : clean

clean :
	$(RM) $(OBJ) $(TARGET)