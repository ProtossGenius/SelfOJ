##Tail
prebuild:
	smdcatalog

debug:
build:
	rm -f *.out
	g++ -g -DONLY_TEST Main.cpp
submit: build
	@for f in `ls *.in`; do \
		echo "\033[32m Running $$f \033[0m";\
		timeout `cat time.limit` ./a.out < $$f > $$f.out;\
		if [ $$? -ne 0 ]; then \
			echo '\033[31m Runtime Error! (Timelimit) \033[0m' ; \
			exit 1; \
		fi; \
		echo "\033[32m Checking Result $$f  \033[0m"; \
		diff --color $$f.out $$f.want;\
		if [ $$? -ne 0 ]; then exit 1; fi; \
	  	done
	@echo '\033[36m Accept! \033[0m';

qrun: build
	timeout `cat time.limit` ./a.out < test.in > test.in.out 
	diff --color test.in.out test.in.want
	@if [ $$? -ne 0 ]; then esit 1 ; fi; 
	@echo '\033[36m Accept! \033[0m';

test:

install:

clean:

