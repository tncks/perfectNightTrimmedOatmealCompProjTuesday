# Makefile for C-Minus Scanner

CC = gcc
CFLAGS = -W -Wall
LEX = flex
YACC = yacc
LIBS = -lfl -lm

# Source files
PARSER = parser.y
LEXER = cminus.l
MAIN = main.c
UTIL = util.c
SYMBOL = symbol.h

# Output executable name
EXECUTABLE = cminus_lex
YACC_OUTPUT = symbol.h y.tab.c y.tab.h
YACC_SOURCE = symbol.h y.tab.c
LEX_OUTPUT = lex.yy.c

.PHONY: all clean

# Default target
all: $(EXECUTABLE)

# Build the executable
$(EXECUTABLE): $(YACC_OUTPUT) $(LEX_OUTPUT) $(MAIN) $(UTIL)
	$(CC) $(CFLAGS) -o $@ $(YACC_OUTPUT) $(LEX_OUTPUT) $(MAIN) $(UTIL) $(LIBS)

# Generate parser and header files
$(YACC_OUTPUT): $(PARSER)
	$(YACC) -d $<

# Generate lexer source file
$(LEX_OUTPUT): $(LEXER)
	$(LEX) -o $@ $<

clean:
	-rm -vf $(EXECUTABLE) $(LEX_OUTPUT) *.o

# Optionally, run the executable (uncomment if needed)
# run: $(EXECUTABLE)
# 	./$(EXECUTABLE)
