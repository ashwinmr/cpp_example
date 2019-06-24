#include <iostream>
#include <regex>
#include <string>

using namespace std;

// Creating the input
#include <sstream> // Needed for string streams
#define multi_line_input(a) #a // This turns a into a string
const char* mli = multi_line_input( // Enter the input in the following lines
	input
);
stringstream ss(mli); // Turns the input into a stringstream
#define cin ss // Replaces all cin with the string stream

int main() {

	{
		// Regex expressiosn for matching
		string str;
		while (cin >> str) {
			{
				

				regex e("inpu.", regex_constants::icase); // .    any character except newline
				// regex e("abc?"); // ?     zero or one of the preceding character
				// regex e("abc*"); // *     zero or more of the preceding character
				// regex e("abc+"); // +     one or more of the preceding character
				// regex e("a[bc]*"); // [...]     anything inside can be matched
				// regex e("a[^bc]*"); // [^...]     anything not inside can be matched
				// regex e("ab[cd]{3}"); // {n}     axactly n occurrences of the preceding character
				// regex e("ab[cd]{3,}"); // {n,}     n or more occurances of the preceding character
				// regex e("ab[cd]{3,5}"); // {n,m}	n to m occurances of the preceding character can be matched
				// regex e("abc|de[fg]"); // a|b	either a or b can be matched
				// regex e("abc|de[\\]fg]"); // \\]	escape the square bracket to include in the list. \ is required to escape the 2nd backslash and allow it to escape the ]
				// regex e("(abc)de+\\1"); // (...) group, \\1 group number, \ is needed to escape the backslash
				// regex e("(ab)c(de+)\\2\\1"); // multiple groups
				// regex e("[[:w:]]+@[[:w:]]+\.com"); // [:w:] word character class, [[:w:]] any character within word character class. This is email address
				// regex e("^abc."); // ^ nothing else can be at the beginning.
				// regex e("abc.$"); // $	expression before it has to be at the end
				// regex e("([[:w:]]+)@([[:w:]]+)\.com"); // 2 groups of everything within (...)

				//Regex operations
				bool match = regex_match(str, e); // Matching exactly
				// bool match = regex_search(str, e); // Searching for something that matches

				cout << str << endl;
				cout << (match ? "Matches" : "Not Matched") << endl << endl;

			}
		}
	}
		
	// {
	// 	// Storing results:

	// 	string str = "bog@gmail.com;";
	// 	regex e("([[:w:]]+)@([[:w:]]+)\\.com");

	// 	smatch m; // Storing match results
	// 	bool found = regex_search(str, m, e); // Stores only the first match in smatch

	// 	cout << "m.size() " << m.size() << endl;
	// 	for (int i = 0; i < m.size(); i++)
	// 		cout << "m[" << i << "]: str()=" << m[i].str() << endl;
	// 	// m will store the match and each submatch that is specified in brackets

	// 	cout << "m.prefix().str(): " << m.prefix().str() << endl; // Prefix stores everything before a matched string
	// 	cout << "m.suffix().str(): " << m.suffix().str() << endl; // Suffix is everyhting after the matched string
	// }

	// {
	// 	// Regex Iterators - This is for multiple match storage in string

	// 	string str = "bog@gmail.com;   boqian@hotmail.com;; ash@gmail.com";

	// 	regex e("([[:w:]]+)@([[:w:]]+)\\.com");

	// 	regex_iterator<string::iterator> pos(str.begin(),str.end(), e);
	// 	regex_iterator<string::iterator> end; // Default constructor defines past-the-end iterator
	// 	for (; pos != end; pos++) {
	// 		cout << "Matched: " << pos->str(0) << endl;
	// 		cout << "user name: " << pos->str(1) << endl;
	// 		cout << "Domain: " << pos->str(2) << endl;
	// 		cout << endl;
	// 	}
	// 	// This assumes that a submatch is there in each match. So there has to be a username and domain in each match. Otherwise (0) or (1) will be empty for that match. Therefore, the submatches do not belong to each match
	// }

	// {
	// 	// Regex Token Iterators - This is for multiple match storage in string but you can select one of the tokens

	// 	string str = "bog@gmail.com;   boqian@hotmail.com;; ash@gmail.com";

	// 	regex e("([[:w:]]+)@([[:w:]]+)\\.com");

	// 	regex_token_iterator<string::iterator> pos(str.begin(), str.end(), e,0); // Last input is the token selector. Either full or submatches. Can also be -1
	// 	regex_token_iterator<string::iterator> end; // Default constructor defines past-the-end iterator
	// 	for (; pos != end; pos++) {
	// 		cout << "Matched: " << pos->str() << endl;
	// 		cout << endl;
	// 	}
	// }

	// {
	// 	// Regex replace - This is for replacing

	// 	string str = "bog@gmail.com;   boqian@hotmail.com;; ash@gmail.com";

	// 	regex e("([[:w:]]+)@([[:w:]]+)\\.com");

	// 	cout << regex_replace(str, e, "$1 is on $2") << endl; // Replaces with group 1 is on group 2
	// 	cout << regex_replace(str, e, "$1 is on $2",regex_constants::format_no_copy) << endl; // Removes unmatched stuff
	// 	cout << regex_replace(str, e, "$1 is on $2", regex_constants::format_no_copy | regex_constants::format_first_only) << endl; // Other flags can be added
	// }

	// system("pause");
	return 0;

}