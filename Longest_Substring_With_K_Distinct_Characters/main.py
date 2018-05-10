"""
Given an integer k and a string s, find the length of the longest substring
that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct
characters is "bcb", so your function should return 3.
"""

def get_all_substrings(s):
	substrings = []

	for i in range(len(s)):
		for j in range(i + 1, len(s) + 1):
			substrings.append(s[i:j])

	return substrings

def longest_substring_helper(l, k):
	counts = {}

	for substring in l:
		characters = set()
		count = 0

		for character in substring:
			if character not in characters:
				characters.add(character)
				count += 1

		if count <= k:
			counts[substring] = count

	longest = 0

	for substring in counts:
		if len(substring) > longest:
			longest = len(substring)

	return longest

def longest_substring(s, k):
	substrings = get_all_substrings(s)

	return longest_substring_helper(substrings, k)

print(True if longest_substring('aaaaa', 2) == 5 else False)
print(True if longest_substring('abcba', 2) == 3 else False)
print(True if longest_substring('abcda', 3) == 3 else False)
print(True if longest_substring('a', 2) == 1 else False)
print(True if longest_substring('abc', 0) == 0 else False)