CCX = g++ -std=c++11 -w

INCLUDES = -Isrc 

LIBRARIES_OMPL = `pkg-config --cflags --libs ompl` 
LIBRARIES_BOOST = -lboost_system -lboost_filesystem -lboost_program_options -lboost_thread

LIBRARIES = $(LIBRARIES_OMPL) $(LIBRARIES_BOOST) -pthread -lm -w

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

move:
	mv roboime-intel /home/johnathan/Repositories/roboime/roboime-next/cli/demos/intel
