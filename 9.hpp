class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		int digit = 0;
		int tmp = x;
		while (tmp > 0) {
			tmp /= 10;
			digit ++;
		}

		int isOdd = 0;
		if (digit % 2 == 1) isOdd = 1;

		int left, right = 0;
		int n = (digit - isOdd) / 2;

		left = x / pow(10, n + isOdd);
		tmp = x % (int)pow(10, n);
		for (int i = 0; i < n; i++) {
			right += ((int)(tmp / pow(10, i)) % 10) * pow(10, n - i - 1);
		}

		return right == left;
	}
};
