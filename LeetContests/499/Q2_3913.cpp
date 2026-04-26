#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, int> first_occurrence;
        vector<char> extracted_vowels;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isVowel(c)) {
                freq[c]++;
                if (first_occurrence.find(c) == first_occurrence.end()) {
                    first_occurrence[c] = i;
                }
                extracted_vowels.push_back(c);
            }
        }

        sort(extracted_vowels.begin(), extracted_vowels.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return first_occurrence[a] < first_occurrence[b];
            });

        int vowel_idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = extracted_vowels[vowel_idx];
                vowel_idx++;
            }
        }

        return s;
    }
};