CC     = gcc
CFLAGS = -Wall -O2 -Wno-unused-result -g
LIB    = -lm
OBJ    = main.o image.o histogram.o lut.o
RM     = rm -f
BIN    = bin/minigimp
DIRNAME = $(shell basename $$PWD)
BACKUP  = $(shell date +`basename $$PWD`-%m.%d.%H.%M.zip)
STDNAME = $(DIRNAME).zip

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(BIN)
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: $(BIN) &"
	@echo "--------------------------------------------------------------"

lut.o : src/lut.c src/lut.h src/image.h
	@echo "compile image"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

histogram.o : src/histogram.c src/histogram.h src/image.h
	@echo "compile image"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

image.o : src/image.c src/image.h
	@echo "compile image"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

main.o : src/main.c src/image.h src/histogram.h src/lut.h
	@echo "compile main"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

clean :	
	@echo "**************************"
	@echo "CLEAN"
	@echo "**************************"
	$(RM) *~ $(OBJ) $(BIN)    

bigclean :
	@echo "**************************"
	@echo "BIG CLEAN"
	@echo "**************************"
	find . -name '*~' -exec rm -fv {} \;
	$(RM) *~ $(OBJ) $(BIN)

zip : clean 
	@echo "**************************"
	@echo "ZIP"
	@echo "**************************"
	cd .. && zip -r $(BACKUP) $(DIRNAME)
