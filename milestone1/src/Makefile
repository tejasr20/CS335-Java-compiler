CC=g++ -w 
BIN=./bin

ans: parser.cpp scanner.cpp tree.cpp
	$(CC) -o $@ $^

scanner.cpp: scanner.l
	flex -o $@ $^
	
parser.cpp: parser.y
	bison -d -o $@ $^

clean:
	rm -rf $(BIN)/ 

allclean: clean
	rm -f scanner.cpp parser.hpp parser.cpp

# CC=g++ -w 
# BIN=../bin

# $(BIN)/parser: parser.cpp scanner.cpp tree.cpp
# 	mkdir -p $(BIN)
# 	$(CC) -o $@ $^

# scanner.cpp: scanner.l
# 	flex -o $@ $^
	
# parser.cpp: parser.y
# 	bison -d -o $@ $^

# clean:
# 	rm -rf $(BIN)/ 

# allclean: clean
# 	rm -f scanner.cpp parser.hpp parser.cpp
