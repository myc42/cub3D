#!/bin/bash

# Chemin vers ton exécutable
EXEC="./cub3D"

# Dossier contenant les maps
MAP_DIR="./maps/bad"

# Boucle sur tous les fichiers .cub du dossier
for map in "$MAP_DIR"/*.cub; do
    echo "=============================="
    echo "Test de la map : $map"
    echo "=============================="

    # Lancer le programme avec valgrind
    valgrind "$EXEC" "$map"

    # Attendre 5 secondes avant le prochain test
    sleep 5
done

echo "Tous les tests sont terminés."

