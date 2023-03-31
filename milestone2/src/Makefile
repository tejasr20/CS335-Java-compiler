CC=g++ -std=c++14 -w 
BIN=./bin

ans: parser.cpp scanner.cpp tree.cpp symbol_table.cpp typecheck.cpp 3ac.cpp
	$(CC) -o $@ $^

scanner.cpp: scanner.l
	flex -o$@ $^
	
parser.cpp: parser.y
	bison -d -o $@ $^ 

clean:
	rm -rf $(BIN)/ 
	rm -rf *.csv

allclean:	clean
	rm -f scanner.cpp parser.h parser.cpp 
	rm -rf *.csv
	rm -rf final_3AC.txt

