class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
		return "0";
	}

	string result;
	long long remainder = numerator;
	unordered_map<long long, int> pattern;

	// Determine sign so that we don't have to care about it later.
	if ((remainder < 0 && denominator > 0) ||
		(remainder > 0 && denominator < 0)) {
		result += "-";
	}

	while (remainder) {
		result += to_string(llabs(remainder / denominator));
		remainder = remainder % denominator;

		// Each time we got a new remainder, check if it matches a repeat pattern. 
		if (pattern.find(remainder) != pattern.end()) {
			result.insert(pattern[remainder], "(");
			result.append(")");
			break;
		}

		// If we are not done by dividing once, we need a ".".
		if (remainder && result.find('.') == result.npos) {
			result += ".";
		}

		// Save the remainder and its correspounding position in the result.
		pattern[remainder] = result.length();

		remainder *= 10;
	}

	return result;
    }
};
