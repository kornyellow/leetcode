class Solution {
public:
	string simplifyPath(string path) {
		int ptr = 0;
		while (true) {
			if (ptr + 1 < path.size()) {
				if (path[ptr] == '/' && path[ptr + 1] == '/') path.erase(path.begin() + ptr + 1);
				else if (path[ptr] == '/' && path[ptr + 1] == '.') {
					if (ptr + 2 < path.size() && path[ptr + 2] == '.') {
						if (ptr + 3 < path.size() && path[ptr + 3] != '/') {
							ptr += 3;
						}
						else {
							for (int i = 0; i < 3; i++) {
								if (path.size() == 1) break;
								path.erase(path.begin() + ptr + 2 - i);
							}
							int newPtr = ptr - 1;
							if (newPtr >= 0) {
								while (path[newPtr] != '/') {
									path.erase(path.begin() + newPtr);
									newPtr --;
								}
								ptr = newPtr;
							}
						}
					}
					else if (ptr + 2 < path.size() && path[ptr + 2] == '/') {
						path.erase(path.begin() + ptr + 1);
					}
					else if (ptr + 2 >= path.size()) {
						path.erase(path.begin() + ptr + 1);
					}
					else ptr ++;
				}
				else ptr ++;
			}
			else {
				if (path[ptr] == '/' && ptr != 0) path.erase(path.begin() + ptr);
				break;
			}
		}
		return path;
	}
};