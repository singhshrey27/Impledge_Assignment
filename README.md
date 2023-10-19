# Impledge_Assignment
Word Composition Problem 

**Program Overview:**\
This program is designed to read input files containing alphabetically sorted words and identify the longest and second longest compounded words from the input. A compounded word is one that can be constructed by concatenating shorter words found in the same file.

**Design Decisions and Approach:**\
Data Structure: We use a Trie data structure to efficiently store and retrieve words from the input. This allows us to check if a word can be formed by combining shorter words.

**Algorithm and Explaination**:\

1.First of all inputs of the files are taken and sended it to the function, here in this function I have created a vector and pushed the input words into the vector\
2.Then words are being sorted according to their decreasing length,longest one first then second longest one and so on.\
3.Then we are here iterating over the vector and checking for the composition using the trie.\
4.If it's a required composition then pushing into it to the result only.

**Input and Output**\
For Input_01.txt:
Longest Compounded Word: ratcatdogcat\
Second Longest Compounded Word: catsdogcats\
Time taken will also be displayed 

Interpret Output: The longest and second longest compounded words will be displayed in the console along with the time taken for processing.
This program efficiently identifies compounded words and provides the necessary information based on the input files. 
