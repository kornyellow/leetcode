class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		int k = day;
		int m;

		if (month > 2) m = month;
		else {
			m = (12 + month);
			year --;
		}

		int c = year / 100;
		int y = year % 100;

		int w = (k + floor((13*(m+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
		w = w % 7;
		if (w == 0) return "Saturday";
		if (w == 1) return "Sunday";
		if (w == 2) return "Monday";
		if (w == 3) return "Tuesday";
		if (w == 4) return "Wednesday";
		if (w == 5) return "Thursday";
		return "Friday";
	}
};