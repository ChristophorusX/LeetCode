#include <iostream>
#include <vector>

using namespace std;


string convert(string s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	string ret = "";
    int startStepSize = std::max(1, 2 * (numRows - 1));
    for (int i = 0; i < numRows; ++i)
    {
        int curStepSize = 2 * i;
        for (int j = i; j < s.size(); j += curStepSize)
        {
            ret.push_back(s[j]);
            if (curStepSize != startStepSize)
                curStepSize = startStepSize - curStepSize;
        }
    }
    return ret;
    }
