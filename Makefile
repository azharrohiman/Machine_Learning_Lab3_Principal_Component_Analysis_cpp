CC=g++

driver: driver.o
	$(CC) driver.o -o driver

driver.o: driver.cpp
	$(CC) -c driver.cpp

run: driver
	./driver

clean:
	rm *.o driver
