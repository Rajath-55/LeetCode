class Solution {
public:
    string reverseWords(string input) {
       stack<string>storage;
    string temp = "";
    for (int i = 0; i < input.size(); i++) {
        if (temp == "")  while (input[i] == ' ') i++; //skip whitesapces
        if (!isspace(input[i])) temp += input[i];     //append characters into a string if they are not a space
        if (input[i] == ' ' || i == input.length() - 1) { //when you reach the end of the word/line;
            if (temp != "")   storage.push(temp); //if word is not empty, push it into the stack
            temp = "";  //reset string
        }
    }
    string output = "";
    while (!storage.empty()) {
        output += storage.top(); storage.pop();
        if (!storage.empty()) {
            output += ' ';
        }
    }
    return output;
    }
};
