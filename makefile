CC = gcc


src = \
	$(wildcard test/*.c) \
	$(wildcard app/*/*.c) \
    
obj = $(src:.c=.o)






main: $(obj)
	$(CC) -o $@ $^


all: clean main
    
clean:
	rm -f $(obj) *.exe