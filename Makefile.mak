CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJ = main.o banque.o compte.o Money.o

# Cible principale
gestion_banque: $(OBJ)
	$(CXX) $(CXXFLAGS) -o gestion_banque $(OBJ)

# Compilation des objets
main.o: main.cpp banque.h compte.h Money.h
	$(CXX) $(CXXFLAGS) -c main.cpp

banque.o: banque.cpp banque.h
	$(CXX) $(CXXFLAGS) -c banque.cpp

compte.o: compte.cpp compte.h
	$(CXX) $(CXXFLAGS) -c compte.cpp

Money.o: Money.cpp Money.h
	$(CXX) $(CXXFLAGS) -c Money.cpp

clean:
	rm -f *.o gestion_banque