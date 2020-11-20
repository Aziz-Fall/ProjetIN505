# Project encryption / decryption using *Huffman algoritm*

Part_1 is the first part of the project that aims to display a binary tree to a *GUI*.
The *GUI* is build with Qt framework. We used *GraphViz* to generate the binary tree image, and *qmake* to build the project by generating a makefile.

## Project dependencies

If you are on linux as *OS* you can install *Graphviz* and *qt5-default* by the following command
`sudo apt-get install graphviz qt5-default`.

## Build and Run
- ### Building
    To build the application you need to generate a makefile using this command
    ```bash
    qmake part_1.pro -o Makefile
    ```
    then you can build the app by running
    ```bash
    make
    ```
- ### Run
    To run the application you simply type
    ```bash
    ./part_1
    ```