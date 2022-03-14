class Solution {
public:
	bool isValid(string s) {
		vector <char> queue;

		int ptr = 0;
		int sSize = s.size();
		while (ptr != sSize) {
			if (s.at(ptr) == '(') queue.insert(queue.begin(), ')');
			else if (s.at(ptr) == '{') queue.insert(queue.begin(), '}');
			else if (s.at(ptr) == '[') queue.insert(queue.begin(), ']');
			else {
				if (queue.empty() || s.at(ptr) != queue.front()) return false;
				queue.erase(queue.begin());
			}
			ptr++;
		}
		return queue.empty();
	}
};
