
BIN=floorplanner

$(BIN): main.c floorplan.c tLib_graphics.cpp floorplan.h tLib_graphics.h
	g++ -Wall -O3 -c tLib_graphics.cpp -o tLib_graphics.o `pkg-config --libs --cflags cairo`
	g++ -Wall -O3 -c floorplan.c -o floorplan.o  `pkg-config --libs --cflags cairo`
	g++ -Wall -O3 -c main.c -o main.o `pkg-config --libs --cflags cairo`
	g++ -Wall -O3 tLib_graphics.o floorplan.o main.o `pkg-config --libs --cflags cairo` -L./lib -ltest -o $(BIN) 

.PHONY: clean
clean:
	rm floorplanner *.o *.png

circuit1: $(BIN)
	./$(BIN) circuits/circuit1.txt circuit1.png

circuit2: $(BIN)
	./$(BIN) circuits/circuit2.txt circuit2.png

circuit3: $(BIN)
	./$(BIN) circuits/circuit3.txt circuit3.png

circuit4: $(BIN)
	./$(BIN) circuits/circuit4.txt circuit4.png

circuit5: $(BIN)
	./$(BIN) circuits/circuit5.txt circuit5.png
