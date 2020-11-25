cmake_minimum_required(VERSION 3.17)
project(Projet_ECEMON_V4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet_ECEMON_V4 main.cpp Attaque.cpp Attaque.h Carte.cpp Carte.h Principal.h Collections.cpp Collections.h Creature.cpp Creature.h Deck.cpp Deck.h Energie.cpp Energie.h Joueur.cpp Joueur.h Plateau.cpp Plateau.h menu.cpp sauvegarde.cpp sauvegarde.h Allegro.cpp Allegro.h menu.h)
target_link_libraries(Projet_ECEMON_V4 -lmingw32 -lallegro-5.0.10-monolith-md-debug)