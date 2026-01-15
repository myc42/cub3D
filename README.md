🧊 Cub3D — Raycasting Engine

Moteur de rendu 3D old-school inspiré de Wolfenstein 3D, développé en C (projet 42).

![Cub3D Preview](./preview.gif)

📌 Description

Cub3D simule une vue FPS dans un univers 2D grâce à la technique du Raycasting.
Le projet met en œuvre le rendu temps réel, la gestion des collisions, le parsing strict et les calculs trigonométriques.

🎮 Fonctionnalités

Rendu 3D temps réel via Raycasting (DDA)

Textures directionnelles (Nord / Sud / Est / Ouest)

Système de collision

Parsing robuste des fichiers .cub

Mini-map et rotation à la souris (bonus)

🛠️ Installation
git clone https://github.com/myc42/cub3D
cd cub3D
make

▶️ Utilisation
./cub3D maps/subject.cub

🕹️ Contrôles

W A S D : déplacement

← / → ou souris : rotation

ESC : quitter

📄 Fichier .cub (extrait)
NO ./north.xpm
SO ./south.xpm
F 220,100,0
C 225,30,0

111111
10N001
111111

