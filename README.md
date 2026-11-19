# Checkoff-3-COMP211

In this assignment, I used AI to explore the topic of LZ77 compression. This is a form of lossless compression that forms that foundation for a majority of modern lossless compression algorithms. 
It works by replacing repeated data with references to identical data from earlier in the stream. Along with Huffman coding, LZ77 is the core of the DEFLATE algorithm, which is the 
most popular lossless compression algorithm in the world. It is used in formats like .ZIP and .PNG, that most people will be familiar with and likely even have experience with. 
LZ77 commonly stores references in the format (distance, length, next char). Distance represents the space between the element being encoded and its match earlier in the data stream. Length is the length of this match in characters. It also commonly stores the next unique character that appears after the match.
Many LZ77 algorithms allow "overlap", which allows the length to exceed the distance of the reference, meaning that it can repeatedly copy a small match many times. It achieves this in the decoder by referencing its own current output stream, copying from its own recent output. 
I consulted with AI to help teach myself about the subject, ask clarifying questions, and generate visual aids to assist my own learning and help convey my findings to my classmates.
https://promptlab.lib.unc.edu/share/XzaYRt4-vES7z5oP_m2c0
