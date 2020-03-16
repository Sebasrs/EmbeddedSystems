APP=calculadora
LIBRARY=libMathOwn
LIBRARY_ROUTE=../lib/
HEADER_ROUTE=../include/

CC=gcc

# Compile with static library
$(APP)ExecStatic: $(APP)ExecDynamic
		$(CC) -o ../bin/$(APP)ExecStatic calculadora.c $(LIBRARY_ROUTE)$(LIBRARY).a -I$(HEADER_ROUTE) -L$(LIBRARY_ROUTE) -lm

# Compile with dynamic library
$(APP)ExecDynamic:
		$(CC) -o ../bin/$(APP)ExecDynamic calculadora.c -I$(HEADER_ROUTE) -L$(LIBRARY_ROUTE) -lMathOwn -lm