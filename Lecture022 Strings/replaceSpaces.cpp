#include<string>
#include<iostream>
using namespace std;

//----------Approach-1------------
string replaceSpaces(string &str){
	string temp = "";
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}

//----------Approach-2------------
//Replace spaces in a string with '@40' in-place method without using extra space
// 1 Count Spaces
// 2 Resize String
// 3 In-Place Replacement

void replaceSpaces2(string& str) {
    int originalLength = str.length();

    // Count the number of spaces to calculate the final length of the modified string
    int spaceCount = 0;
    for (char ch : str) {
        if (ch == ' ') {
            spaceCount++;
        }
    }

    // Calculate the final length of the modified string 
    // The term + 2 * spaceCount is used because one space is already present in the original string.
    // We add an additional 2 spaces to accommodate the replacement of each space by three characters
    // ('@', '4', '0') in the modified string.
    int modifiedLength = originalLength + 2 * spaceCount;

    // Resize the string to accommodate the modified length
    str.resize(modifiedLength);

    // Iterate from the end to perform the replacement in-place
    int i = originalLength - 1;
    int j = modifiedLength - 1;

    while (i >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}

int main() {
    // Example usage
    string input = "Hello World!";
    
    // Perform in-place replacement
    replaceSpaces2(input);

    // Output the modified string
    cout << "Modified String: " << input << endl;

    return 0;
}