class Solution {
public:
     int charToInt(char c) {
        return c - '0';
    }

    int containsDigit(const string& str) {
        int val = 0;
        for (char c : str) {
            if (isdigit(c)) {
                val = val * 10 + charToInt(c);
            } else {
                return 0; // If any non-digit character is found, return 0
            }
        }
        return val;
    }

    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> indicesStack; // Stack to store maps of atoms and their counts

        unordered_map<string, int> currentAtoms; // Map to store current atom counts

        int i = 0;
        while (i < formula.length()) {
            if (isupper(formula[i])) {
                string atom;
                atom += formula[i];
                ++i;
                while (i < formula.length() && islower(formula[i])) {
                    atom += formula[i];
                    ++i;
                }
                int count = 0;
                while (i < formula.length() && isdigit(formula[i])) {
                    count = count * 10 + charToInt(formula[i]);
                    ++i;
                }
                count = max(1, count); // If no digit follows, count defaults to 1
                currentAtoms[atom] += count;
            } else if (formula[i] == '(') {
                indicesStack.push(currentAtoms); // Save current atom counts to stack
                currentAtoms.clear(); // Reset for atoms inside parentheses
                ++i;
            } else if (formula[i] == ')') {
                int count = 0;
                ++i;
                while (i < formula.length() && isdigit(formula[i])) {
                    count = count * 10 + charToInt(formula[i]);
                    ++i;
                }
                count = max(1, count); // If no digit follows, count defaults to 1

                // Multiply atom counts inside parentheses by 'count'
                for (auto& entry : currentAtoms) {
                    entry.second *= count;
                }

                if (!indicesStack.empty()) {
                    // Merge current atoms into previous level (from stack)
                    auto& prevAtoms = indicesStack.top();
                    for (const auto& entry : currentAtoms) {
                        prevAtoms[entry.first] += entry.second;
                    }
                    currentAtoms = prevAtoms; // Restore current atoms to merged state
                    indicesStack.pop(); // Remove processed level from stack
                }
            } else {
                ++i;
            }
        }

        // Construct the result string
        string ans;
        vector<string> atoms;
        for (auto& entry : currentAtoms) {
            atoms.push_back(entry.first);
        }
        sort(atoms.begin(), atoms.end());

        for (const string& atom : atoms) {
            ans += atom;
            if (currentAtoms[atom] > 1) {
                ans += to_string(currentAtoms[atom]);
            }
        }

        return ans;
    }
};