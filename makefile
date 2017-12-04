CC = gcc


src = \
	$(wildcard test/*.c) \
	$(wildcard app/wojfid/*.c) \
	$(wildcard app/adagac/*.c) \
	$(wildcard app/konswi/*.c) \
	$(wildcard app/pawszy/*.c) \
	$(wildcard app/piogaw/*.c) \
	$(wildcard app/piozar/*.c) \
	$(wildcard app/seblis/*.c) \
    
obj = $(src:.c=.o)






main: $(obj)
	$(CC) -o $@ $^


all: clean main
    
clean:
	rm -f $(obj) *.exe