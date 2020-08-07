# Crunch
A fast command line tool for a variety of lossless compression techniques, like Huffman coding and the LZW algorithm. Crunch works for any file type, however some file types will be able to achieve greater compression.

## Install instructions
Running Crunch requires `cmake`. You can find ways to install it [here](https://cmake.org/install/).

After installing cmake, you can clone the repository, make a build directory, and build the project to get started.
```
git clone https://github.com/vaishnavi17/crunch.git
cd crunch
#creating the build directory
mkdir build
cd build
#this generates the makefile for the project
cmake ..
#running make builds the project and generates an executable called crunch
make
cd ..
#now you can run this executable and supply it with command line arguments
build/crunch [command]
```

## Usage
The format for compression/decompression is: 

`[compression method tag] [compress/decompress tag] [input file path] [output file path]`

The compression method tag defines the algorithm used. To use Huffman coding, use `--huffman`, and to use LZW use `--lzw`.
For compress/decompress tags, use `--compress` or `--c` to compress a file, and `--decompress` or `--d` to decompress a file.


To see the help menu, use the command `--help`.

To quit, use `--quit` or `--q`.


The `res` folder has a lot of example files that can be used (taken from Stanford's CS 106X course). Here's some commands you can try out:

`--huffman --c res/moo.wav res/moo.huff`
`--huffman --d res/moo.huff res/moo_decompressed.wav`
