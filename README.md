[![Build Status](https://travis-ci.org/maitesin/tries.svg?branch=master)](https://travis-ci.org/maitesin/tries)  <a href="https://scan.coverity.com/projects/maitesin-tries"> <img alt="Coverity Scan Build Status" src="https://scan.coverity.com/projects/7354/badge.svg"/> </a>  [![Coverage Status](https://coveralls.io/repos/maitesin/tries/badge.svg?branch=master&service=github)](https://coveralls.io/github/maitesin/tries?branch=master) 

Trie / Ternary Search Tree (TST) / Radix Tree
=====
##Description of this project
I have created three data structures that are implementations of the <b>abstract data type dictionary</b>. But they are enhanced with an <b>extra method</b> called <b>"keys"</b>, this returns the keys with that share a provided prefix. This can be useful to use it in tasks such as autocomplete searches.

The aim of this study is to <b>compare the performance</b> of these three data structures in <b>different scenarios</b> and against the <b>std::map</b> and <b>std::unordered_map</b>. Moreover, the second aim of this project is to practice new things added in the standard <b>C++11</b> and the <b>Google Test</b> as a unit test framework.

##Operations supported by the three data structures tested in this project.
Operation|Description
---------|-----------
clear|Removes all the content of the data structure
find|Returns the value stored in the data structure for a specific key provided
insert|Adds a new pair of key and value to the data structure
size|Returns the amount of elements stored in the data structure
show|Prints the content of the data structure in the [dot](https://en.wikipedia.org/wiki/DOT_(graph_description_language)) format
erase|Removes the value stored in the data structure for a specific key provided
contains|Returns true if there is a value associated to the key provided
keys|Returns a std::vector with all the keys in the data structure that have the provided prefix. If no prefix is provided returns a std::vector with all the keys in the data structure.

##Scenarios tested
I have develop several test scenarios (and I am still developing new ones) to compare the performance of these five data structures.
* Memory
  - Random values
  - Dictionaries
* Insert
  - Random values
* Remove
  - Random values
    * Found
    * Not found
  - Dictionaries
    * Found
    * Not found
* Seach
  - Random values
    * Found
    * Not found
  - Dictionaries
    * Found
    * Not found
* Get Keys
  - Random values
  - Dictionaries
* Get Keys with Prefix
  - Random values
  - Dictionaries
