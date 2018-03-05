"""
Problem statement: Implement an autocomplete system. That is, given a query
string s and a list of words in a dictionary, return all words that have s as
a prefix.
"""

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.iswordend = False

def insert(root, word):
    crawler = root

    for i in range(len(word)):
        idx = get_index(word[i])

        if not crawler.children[idx]:
            crawler.children[idx] = TrieNode()

        crawler = crawler.children[idx]

    crawler.iswordend = True

def find(root, key):
    crawler = root

    for i in range(len(key)):
        idx = get_index(word[i])

        if not crawler.children[idx]:
            return False

        crawler = crawler.children[idx]

    return (crawler and crawler.iswordend)

def is_end(root):
    for i in range(26):
        if root.children[i]:
            return False

    return True

def get_index(char):
    return ord(char) - ord('a')

def autocomplete_helper(root, word):
    word = list(word)

    if root.iswordend:
        print(''.join(word))

    if is_end(root):
        return

    for i in range(26):
        if root.children[i]:
            word.append(chr(97 + i))

            autocomplete_helper(root.children[i], word)

            word.pop(-1)

def autocomplete(root, word):
    word = list(word)
    crawler = root

    for i in range(len(word)):
        idx = get_index(word[i])

        if not crawler.children[idx]:
            return

        crawler = crawler.children[idx]

    isword = crawler.iswordend
    isend = is_end(crawler)

    if isword and isend:
        print(''.join(word))

        return

    if not isend:
        wordcopy = word

        autocomplete_helper(crawler, wordcopy)

root = TrieNode()

insert(root, 'ab')
insert(root, 'abc')
insert(root, 'def')
insert(root, 'cel')
insert(root, 'fed')
insert(root, 'npc')
insert(root, 'aqr')

autocomplete(root, 'a')
