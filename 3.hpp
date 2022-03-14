class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty()) return 0;
		string longest = s.substr(0, 1);

		int ptr1 = 0;
		int ptr2 = 1;
		while (true) {
			if (ptr2 == s.size()) break;
			string newSubstr = s.substr(ptr1, ptr2 - ptr1 + 1);

			bool isLongest = true;
			for (int i = 0; i < newSubstr.size() - 1; i++) {
				if (newSubstr[i] == s[ptr2]) {
					isLongest = false;
					break;
				}
			}
			if (isLongest) {
				if (newSubstr.size() > longest.size()) longest = newSubstr;
				ptr2 ++;
			} else if (ptr1 == ptr2) {
				ptr2 ++;
			} else ptr1 ++;
		}
		return longest.size();
	}
};