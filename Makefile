CCX = g++ -std=c++11 -w

INCLUDES = -Isrc 

LIBRARIES = -pthread -lm -w

SRC := $(shell find -name '*.cpp')
FILE_NAMES_SRC = $(SRC:.cpp=.o)

FILE_NAMES = $(FILE_NAMES_SRC)

EXEC = roboime-intel

.cpp.o:
	@$(CCX) $(INCLUDES) $(LIBRARIES) -Wall -Wformat -c -o $@ $< -w

.cc.o:
	@$(CCX) $(INCLUDES) $(LIBRARIES) -Wall -Wformat -c -o $@ $< -w

all: message_compiling $(EXEC)
	@echo Done ...
	
message_compiling:
	@echo Compiling roboime-intel ...

message_cleaning:
	@echo Cleaning roboime-intel ...

run:
	./$(EXEC)

$(EXEC): $(FILE_NAMES)
	@$(CCX) -o $(EXEC) $(FILE_NAMES) $(LIBRARIES) $(INCLUDES)

clean: message_cleaning
	@rm $(EXEC) $(FILE_NAMES)
