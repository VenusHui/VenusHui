a.out: logisim.c
	gcc $(CFLAGS) logisim.c

run: a.out
	./a.out | python3 seven-seg.py  # The UNIX Philosophy

clean:
	rm -f a.out
