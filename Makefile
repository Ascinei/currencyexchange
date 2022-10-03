all: 
	@g++ -o main.exe main.cpp
	@./main
	@rm main.exe

build:
	g++ -o main.exe main.cpp

run:
	./main

clean:
	rm main.exe