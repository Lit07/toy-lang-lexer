EXEC = toy_lang

all:
	flex lexer/lexer.l
	gcc lex.yy.c tables/keywords.c driver/main.c -I tokens -I tables -lfl -o $(EXEC)

run:
	./$(EXEC) < test/test.txt

clean:
	rm -f lex.yy.c $(EXEC)

parser:
	gcc parser/top_down_parser/parser.c parser/top_down_parser/stack.c -o parser_exec