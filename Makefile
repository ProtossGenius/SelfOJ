##Tail
prebuild:

debug:
build:
	rm -f *.out
	g++ Main.cpp
submit: build
	for f in `ls *.in`; do \
		echo "\033[32m Running $$f \033[0m";\
		timeout `cat time.limit` ./a.out < $$f > $$f.out;\
		echo "\033[32m Checking Result $$f  \033[0m"; \
		diff $$f.out $$f.want;\
	  	done

qrun: build
	timeout `cat time.limit` ./a.out < test.in > test.in.out 
	diff test.in.out test.in.want
test:

install:

clean:

