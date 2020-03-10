#!/bin/sh

#Shell Script que mueve el fichero creado en build a la carpeta anterior para poder ejecutarlo y luego lo devuelve a la carpeta build


#Nombre del ejecutable que se genera en build
nombre=Chaospace

cd build
mv $nombre ../
cd ../
$nombre
mv $nombre build/


