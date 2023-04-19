CC=g++ -std=c++14 -w 
BIN=./bin

ans: parser.cpp scanner.cpp tree.cpp symbol_table.cpp typecheck.cpp 3ac.cpp codegen.cpp
	$(CC) -o $@ $^

scanner.cpp: scanner.l
	flex -o$@ $^
	
parser.cpp: parser.y
	bison -d -o $@ $^ 

clean:
	rm -rf $(BIN)/ 
	rm -rf *.csv

asm: code.s
	as -g -o code.o code.s 
	ld -no-pie -o code code.o -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 
	./code

x:	asm.s 
	as -g -o asm.o asm.s 
	ld -no-pie -o asm asm.o -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 
	./asm 

s:	asm.s
	gcc -o asm asm.s
	./asm

allclean:	clean
	rm -f scanner.cpp parser.hpp parser.h parser.cpp ans
	rm -rf *.csv
	rm -rf *.dot
	rm -rf *.asm
	rm -rf *.asm
	rm -rf final_3AC.txt

