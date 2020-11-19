#!/bin/bash 

OS=`uname`

if [ "$OS" = "Linux"  ]; then
	echo "OS linux"
	sudo apt-get install graphviz qt5-default 
else 
	echo "unknow"
fi
