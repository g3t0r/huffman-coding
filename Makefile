CC := g++

default: clean all

.PHONY: all
all: producer reader

.PHONY: clean
clean:
	rm -rf ./bin/ compressed.bin

.PHONY: producer
producer:
	mkdir -p bin
	$(CC) src/main.cpp src/heap-node.cpp src/mapping-table.cpp src/stat-collector.cpp src/bit-writer.cpp -o bin/producer.o

.PHONY: reader
reader:
	mkdir -p bin
	$(CC) src/reader.cpp src/heap-node.cpp src/mapping-table.cpp src/stat-collector.cpp src/bit-writer.cpp -o bin/reader.o
