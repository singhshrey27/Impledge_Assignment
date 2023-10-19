# Impledge_Assignment
Word Composition Problem 

**Program Overview:**\
This program is designed to read input files containing alphabetically sorted words and identify the longest and second longest compounded words from the input. A compounded word is one that can be constructed by concatenating shorter words found in the same file.


**Approach**:

**1.Trie Data Structure:** The code uses a Trie data structure to efficiently store and retrieve words. It helps in checking if a word can be formed by combining shorter words in the input list.\
**2.Insertion:** The Trie class includes an insert method, which inserts a word character by character into the Trie, creating nodes for each character.\
**3.Can Be Formed Function:** The canBeFormed function checks if a word can be formed by combining smaller words. It traverses the Trie while considering different combinations and returns true if the word is a compounded word.\
**4.Sorting by Length:** Words are sorted by length in descending order to optimize the search for compounded words. This ensures that the code examines longer words before shorter ones.\
**5.Processing Input Files:** The code processes each input file individually. It reads the file, stores words in a vector, and then calls the findLongestAndSecondLongestCompoundWords function to identify compounded words.\
**6.Output:** The code outputs the longest and second longest compounded words for each input file, along with the time taken to process them. The time is measured using the chrono library to ensure efficient execution.


**Explaination**
1.The code initializes a Trie data structure.\
2.First of all inputs of the files are taken and sended it to the function, here in this function I have created a vector and pushed the input words into the vector\
3.The words are sorted by length in descending order to optimize the search for compounded words.\
4.For each word, the code uses the Trie to check if it can be formed by combining shorter words. If found, it adds the word to the result and breaks out of the loop.\
5.The code measures the time taken for each input file's processing and outputs the results, including the longest and second longest compounded words.

**Input and Output**\
For Input_01.txt:
Longest Compounded Word: ratcatdogcat\
Second Longest Compounded Word: catsdogcats\
Time taken will also be displayed 
 
