app.out: main.o foo.o bar.o
	gcc -o app.out main.o foo.o bar.o

main.o: foo.h bar.h main.c
	gcc -c main.c

foo.o: foo.c foo.h
	gcc -c foo.c

bar.o: bar.c bar.h
	gcc -c bar.c

clean:
	rm *.o app.out