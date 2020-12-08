# Project encryption / decryption using *Huffman algoritm*

Part_3 is the last part of the project that aims to encrypt and decrypt a given file or text, display a binary tree. We used *GraphViz* to generate the binary tree image, the framework Qt to create a *GUI*, and *qmake* to build the project by generating a makefile.

## Project dependencies

If you are on linux as *OS* you can install *Graphviz* and *qt5-default* by the following command
`sudo apt-get install graphviz qt5-default`.

## Build and Run
- ### Building
    To build the application you need to generate a makefile using this command
    ```bash
    qmake part_3.pro -o Makefile
    ```
    then you can build the app by running
    ```bash
    make
    ```
- ### Run
    To run the application you simply type
    ```bash
    ./part_3
    ```