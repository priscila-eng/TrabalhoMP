TARGET = main
CC = g++
FILE = testa_romano.cpp
FILE2 = romano.cpp
OBJ1 = testa_romano.o
OBJ2 = romano.o
OBJS = testa_romano.o romano.o

run: all
	./${TARGET}
all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
 
testa_romano.o: $(FILE)
	$(CC) -c $(FILE) -o ${OBJ1}
 
romano.o: $(FILE2)
	$(CC) -c $(FILE2) -o ${OBJ2}
 
clean:
	rm -f *.o *~ $(TARGET)

check: 
	valgrind --leak-check=full ./${TARGET}
	@echo "====================== CPPCHECK ============================"
	cppcheck --enable=warning .
	@echo "====================== CPPLINT testa_romanos.cpp ============================"
	cpplint ${FILE}
	@echo "====================== CPPLINT romanos.cpp ============================"
	cpplint ${FILE2}

