const fs = require('fs');

/**
 * Trie Node
 */
function TrieNode() {
  this.children = {};
  this.isEndOfWord = false;
}

/**
 * Trie
 */
function Trie() {
  this.root = new TrieNode();
}

/**
 * Insert a word into the trie
 * @param {string} word
 */
Trie.prototype.insert = function (word) {
  let node = this.root;
  for (const char of word) {
    if (!node.children[char]) {
      node.children[char] = new TrieNode();
    }
    node = node.children[char];
  }
  node.isEndOfWord = true;
};

/**
 * Check if a word can be formed by combining smaller words in the trie
 * @param {string} word
 * @param {Trie} trie
 * @param {boolean} isOriginalWord - Check if the word is the original word (not a combination)
 * @returns {boolean}
 */
function canBeFormed(word, trie, isOriginalWord = true) {
  if (!word) {
    return false;
  }
  let node = trie.root;
  for (let i = 0; i < word.length; i++) {
    const char = word[i];
    if (node.children[char]) {
      node = node.children[char];
      if (node.isEndOfWord) {
        if (i === word.length - 1) {
          if (isOriginalWord) {
            // If it's an original word, the entire word should exist in the trie
            return false;
          }
          return true;
        }
        if (canBeFormed(word.substring(i + 1), trie, false)) {
          return true;
        }
      }
    } else {
      return false;
    }
  }
  return false;
}

/**
 * Find the longest and second longest compounded words in a list of words
 * @param {string[]} words
 * @returns {string[]} - [longest, secondLongest]
 */
function findLongestAndSecondLongestCompoundWords(words) {
  const trie = new Trie();
  words.sort((a, b) => b.length - a.length);

  for (const word of words) {
    if (canBeFormed(word, trie)) {
      return [word];
    }
    trie.insert(word);
  }

  return [];
}

/**
 * Main function to read and process the input file
 * @param {string} fileName
 */
function processInputFile(fileName) {
  const start = new Date().getTime();
  const words = fs.readFileSync(fileName, 'utf-8').split('\n').map((word) => word.trim());
  const [longest, secondLongest] = findLongestAndSecondLongestCompoundWords(words);
  const end = new Date().getTime();
  const timeTaken = end - start;

  console.log(`For ${fileName}:`);
  console.log(`Longest Compounded Word: ${longest}`);
  console.log(`Second Longest Compounded Word: ${secondLongest}`);
  console.log(`Time Taken: ${timeTaken} ms`);
}

const inputFiles = ['Input_01.txt', 'Input_02.txt'];

inputFiles.forEach((inputFile) => {
  processInputFile(inputFile);
});
