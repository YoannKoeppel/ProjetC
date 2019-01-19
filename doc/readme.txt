----- EXECUTION -----


1. APPLICATION D'EFFET(S) SANS HISTOGRAMME

$ ./bin/minigimp images/image.ppm ADDLUM 10 ADDCON 5 -o images/imageOut.ppm

-> Cette commande applique un effet ADDLUM et ADDCON sur l'image "image.ppm" et la sauvegarde sous "imageOut.ppm" dans le dossier "images".




2. APPLICATION D'EFFET(S) AVEC HISTOGRAMME

$ ./bin/minigimp images/image.ppm -histo ADDLUM 10 ADDCON 5 -o images/imageOut.ppm

-> Cette commande permet de générer en plus dans le dossier "images" l'histogramme initial de l'image et le nouveau histogramme après modification.
