from typing import List

# Define map_ as a global dictionary


class Solution:
    dictionary= {}
    def encode(self, strs: List[str]) -> str:
        key = " ".join(strs)  # Create a unique key
        self.dictionary[key] = strs  # Store the original list
        return key  # Return the encoded string (key)

    def decode(self, s: str) -> List[str]:
        return self.dictionary.get(s, [])  # Retrieve the list from the dictionary