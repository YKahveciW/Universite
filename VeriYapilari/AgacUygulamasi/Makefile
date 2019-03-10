VPATH= ./src
CXXFLAGS= -I "./include"

all: program1 Calis

program1:Main.o Okul.o Siniflar.o Ogrenci.o
	g++ Main.o Okul.o Siniflar.o Ogrenci.o -o OkulProgrami

Main.o:Main.cpp
	g++ -c $(CXXFLAGS) $<
Ogrenci.o:Ogrenci.cpp
	g++ -c $(CXXFLAGS) $<
Okul.o:Okul.cpp
	g++ -c $(CXXFLAGS) $<
Siniflar.o:Siniflar.cpp
	g++ -c $(CXXFLAGS) $<
Calis:OkulProgrami.exe
	./OkulProgrami.exe