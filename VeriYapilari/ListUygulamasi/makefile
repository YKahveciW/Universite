VPATH= ./src
CXXFLAGS= -I "./include"

all: PROGRAM Calis

PROGRAM:Main.o  Agac.o AltAgaclar.o Islemler.o 
	g++ Main.o Agac.o AltAgaclar.o Islemler.o  -o PROGRAM

Agac.o:Agac.cpp
	g++ -c $(CXXFLAGS) $<
AltAgaclar.o:AltAgaclar.cpp
	g++ -c $(CXXFLAGS) $<
Islemler.o:Islemler.cpp
	g++ -c $(CXXFLAGS) $<
Main.o:Main.cpp
	g++ -c $(CXXFLAGS) $<
Calis: PROGRAM.exe
		./PROGRAM.exe
