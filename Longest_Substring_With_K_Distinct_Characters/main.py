"""
Given an integer k and a string s, find the length of the longest substring
that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct
characters is "bcb", so your function should return 3.
"""

def longest_substring(s, k):
    longest = 0
    characters = []
    count = 0

    for character in s:
        count += 1

        if character in characters:
            characters.remove(character)

        characters.append(character)

        if len(characters) > k:
            count -= 1
            characters.pop(0)

        if count > longest:
            longest = count

    return longest

print(True if longest_substring('aaaaa', 2) == 5 else False)
print(True if longest_substring('abcba', 2) == 3 else False)
print(True if longest_substring('abcda', 3) == 3 else False)
print(True if longest_substring('a', 2) == 1 else False)
print(True if longest_substring('abcd', 0) == 0 else False)
print(True if longest_substring('abcaca', 2) == 4 else False)
print(True if longest_substring('abcde', 4) == 4 else False)