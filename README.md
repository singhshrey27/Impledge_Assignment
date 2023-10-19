# Impledge_Assignment
Word Composition Problem 

**Program Overview:**
This program is designed to read input files containing alphabetically sorted words and identify the longest and second longest compounded words from the input. A compounded word is one that can be constructed by concatenating shorter words found in the same file.

**Design Decisions and Approach:**
Data Structure: We use a Trie data structure to efficiently store and retrieve words from the input. This allows us to check if a word can be formed by combining shorter words.

Algorithm: We utilize a dynamic programming approach to determine if a word can be formed by combining shorter words. This ensures that we find the longest and second longest compounded words.

The code efficiently identifies the longest and second longest compounded words from alphabetically sorted word lists in input files using a Trie data structure. It reads each input file, processes the words, and utilizes a dynamic programming approach to determine if a word can be formed by combining shorter words. It sorts the words by length to optimize the search for compounded words. After processing, the code outputs the longest and second longest compounded words for each input file, along with the time taken for execution, in a concise and organized manner.


For Input_01.txt:
Longest Compounded Word: ratcatdogcat
Second Longest Compounded Word: catsdogcats
Time Taken: XXX ms(as per the time obtained)

Interpret Output: The longest and second longest compounded words will be displayed in the console along with the time taken for processing.

This program efficiently identifies compounded words and provides the necessary information based on the input files. 
