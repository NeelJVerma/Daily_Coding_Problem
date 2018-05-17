"""
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
"""

def construct_sentence(dictionary, string):
    returnlist = []
    checkstring = []

    for char in string:
        checkstring.append(char)

        if ''.join(checkstring) in dictionary:
            returnlist.append(''.join(checkstring))
            checkstring = []

    return returnlist

print(True if construct_sentence(['quick', 'brown', 'the', 'fox'], 'thequickbrownfox') == ['the', 'quick', 'brown', 'fox'] else False)
print(True if construct_sentence(['bed', 'bath', 'bedbath', 'and', 'beyond'], 'bedbathandbeyond') == ['bed', 'bath', 'and', 'beyond'] else False)
print(True if construct_sentence(['a'], 'a') == ['a'] else False)
print(True if construct_sentence(['ab', 'c', 'd'], 'abdc') == ['ab', 'd', 'c'] else False)