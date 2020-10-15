FILE_NAME0 := main
FILE_NAME1 := read
FILE_NAME2 := stack
FILE_NAME3 := balancecheck

EXE_NAME   := project
CC	       := gcc 
#FLAGS      := -Wall -Os 

default: compile run clean

build: compile clean

compile:
	@$(CC) $(FLAGS) -c $(FILE_NAME0).c -o $(FILE_NAME0).o
	@$(CC) $(FLAGS) -c $(FILE_NAME1).c -o $(FILE_NAME1).o
	@$(CC) $(FLAGS) -c $(FILE_NAME2).c -o $(FILE_NAME2).o
	@$(CC) $(FLAGS) -c $(FILE_NAME3).c -o $(FILE_NAME3).o
	
	@$(CC) -o $(EXE_NAME).run $(FILE_NAME0).o $(FILE_NAME1).o $(FILE_NAME2).o $(FILE_NAME3).o 

run:
	@./$(EXE_NAME).run

clean:
	@rm $(FILE_NAME0).o
	@rm $(FILE_NAME1).o
	@rm $(FILE_NAME2).o
	@rm $(FILE_NAME3).o
	
	
