#!/bin/bash 

OS=`uname`

if [ "$OS" = "Linux"  ]; then
	echo "OS linux"
	sudo apt-get install graphviz cmake
else 
	echo "unknow"
fi
