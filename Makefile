CC := g++

default: all

all: producer reader

.PHONY: clean
clean:
	rm -rf ./bin/

.PHONY: producer
producer:
	mkdir -p bin
	$(CC) src/main.cpp src/heap-node.cpp src/mapping-table.cpp src/stat-collector.cpp -o bin/producer.o

.PHONY: reader
reader:
	mkdir -p bin
	$(CC) src/reader.cpp -o bin/reader.o
