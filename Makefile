CXX = clang++-3.5
CCX = $(CXX) -std=c++11 -w -lboost_system -lompl

INCLUDES = -Isrc 

LIBRARIES = -pthread -lm -w

CLIFLAGS  =  

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

cli: $(EXEC)
	roboime-next-cli $(CLIFLAGS) ./$(EXEC)
	
gui: $(EXEC)
	roboime-next-gui $(CLIFLAGS) ./$(EXEC)

$(EXEC): $(FILE_NAMES)
	@$(CCX) -o $(EXEC) $(FILE_NAMES) $(LIBRARIES) $(INCLUDES)

clean: message_cleaning
	@rm -f $(EXEC) $(FILE_NAMES)
