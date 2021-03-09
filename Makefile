CXX = g++
CXX_FLAGS = -I. -std=c++17 -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow

TMPFILE=tmpimg
GEOM?=
VARS?=

ifdef GEOM
VARS += -V geometry:"$(GEOM)"
endif

PRJ = main
SRC = $(PRJ).cpp
BIN = a.out

.PHONY : all solution imgpdf sol2pdf clean test grade
solution: sol2pdf imgpdf clean

imgpdf:
	pdftoppm $(PRJ)-t.pdf $(TMPFILE) -png
	convert $(TMPFILE)*.png $(PRJ).pdf

sol2pdf:
	enscript --color=1 -C -Ecpp -fCourier9 -o - $(PRJ).sol.* | ps2pdf - $(PRJ)-t.pdf

all: $(BIN)

test.o: test.cpp
	$(CXX) $(CXX_FLAGS) test.cpp -c

$(BIN): test.o $(PRJ).o
	g++ $(CXX_FLAGS) test.o $(SRC)

clean:
	@rm $(PRJ)-t.pdf $(TMPFILE)*.png || true
	rm $(BIN) *.o  || true

test: $(BIN)
	./$(BIN)

c1: $(BIN)
	./$(BIN) -c c1

c2: $(BIN)
	./$(BIN) -c c2

c3: $(BIN)
	./$(BIN) -c c3

o1: $(BIN)
	./$(BIN) -c o1

o2: $(BIN)
	./$(BIN) -c o2

o3: $(BIN)
	./$(BIN) -c o3

o4: $(BIN)
	./$(BIN) -c o4

p1: $(BIN)
	./$(BIN) -c p1

p2: $(BIN)
	./$(BIN) -c p2

p3: $(BIN)
	./$(BIN) -c p3

p4: $(BIN)
	./$(BIN) -c p4

