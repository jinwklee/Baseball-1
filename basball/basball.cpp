#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question){

	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true,3,0 };
		}

		int strike_cnt = 0;
		int ball_cnt = 0;
		for (int i = 0; i < 3; i++) {
			if (question[i] == guessNumber[i]) {
				strike_cnt++;
				continue;
			}
			for (int j = 0; j < 3; j++) {
				if (question[i] == guessNumber[j]) {
					ball_cnt++;
				}
			}
		}

		return { false,strike_cnt,ball_cnt };
	}

	bool isDuplicatedNumber(const string& guessNumber) {
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]) {
			return true;
		}
		return false;
	}

	void assertIllegalArgument(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}
private:
	string question;
};