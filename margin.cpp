#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void margin(ifstream&, int, int);
vector<string> split(char , string);
bool isNumber (string);
    

int main(){
    ifstream inFile;//declaration of input file
    inFile.open("file.txt");//opening the input file
    if (inFile.fail()) {
		cout << "Problem opening file: " << endl;
		exit(1);
	}
    string leftMarginStr = "";
    string rightMarginStr = "";
    inFile >> leftMarginStr;
    inFile >> rightMarginStr;
    if ((leftMarginStr.length()==0) && (rightMarginStr.length()==0)){
        cout << "Error: The text file is empty"<<endl;
        inFile.close();
        exit(1);
    }
    int leftMargin = 0;
    int rightMargin = 0;
    if (isNumber(leftMarginStr) && isNumber(rightMarginStr)){
        leftMargin = stoi(leftMarginStr);
        rightMargin = stoi(rightMarginStr);
    }  
    else{
        cout << "Error: Please enter correct values for left and right margin" <<endl;
        inFile.close();
        exit(1);
    }
    if ((leftMargin + rightMargin) >= 80){
        cout << "Error: The margin size is very large. Please provide smaller number. "<<endl;
        exit(1);
    }
    margin(inFile, leftMargin, rightMargin);
    inFile.close();
}

/* Check if the string contains all number */
bool isNumber(string number){
    for (int i=0; i<number.length(); i++ ){
        if (!isdigit(number[i])){
            return false;
        }
    }
    return true;
}

/* Split a  sentence into vectors containing different strings. */ 
vector<string> split(string sentence, string delimiter){
    vector<string> list;
    size_t pos = 0;
    string token;
    while ((pos = sentence.find(delimiter)) != string::npos) {
        token = sentence.substr(0, pos);
        list.push_back(token);
        sentence.erase(0, pos + delimiter.length());
    }
    // If some element is still remaining in sentence.
    if (sentence.length() >0){
        list.push_back(sentence);
    }
    return list;
}

/* Assuming one space as one inch. */
void margin(ifstream& inFile, int leftMargin, int rightMargin){
    ofstream outFile;//declaration of output file
    outFile.open ("DAT1.txt");//opening the output file    
    // Add left margin.
    for(int i = 0 ; i < leftMargin ; i++){
        outFile << " ";
    }
    string tempWord = "";
    string tempSentence ="";
    int wordLen = 0;
    int lineLen = 0;
    int counter = 0;
    while(!inFile.eof()){
        getline(inFile, tempSentence);
        counter++;
        // Splitting a line into various words.
        vector <string> wordList = split(tempSentence, " ");
        for(int i = 0; i < wordList.size(); i++){
            tempWord = wordList[i];
            wordLen = tempWord.length();
            lineLen += wordLen;
            // If the length of word is greater than the length of line.
            if (wordLen > (80-leftMargin-rightMargin)){
                cout << "Error: The file contain very long word. Please remove it "<<endl;
                exit(1);
            }
            if (lineLen > (80-leftMargin-rightMargin)){
                outFile << "\n";
                // Add left margin.
                for(int i = 0 ; i < leftMargin ; i++){
                    outFile << " ";
                }
                lineLen = wordLen;
                outFile << tempWord;
                char lastChar = tempWord.at(tempWord.length() - 1 );
                if (lastChar == '.'){
                    lineLen += 2;
                    outFile <<"  ";
                } else {
                    lineLen += 1;
                    outFile <<" ";
                }
                tempWord = "";
            } else {
                outFile << tempWord;
                char lastChar = tempWord.at(tempWord.length() - 1 );
                if (lastChar == '.'){
                    lineLen += 2;
                    outFile <<"  ";
                } else {
                    lineLen += 1;
                    outFile <<" ";
                }
            }
          }
          lineLen = 0;
          wordLen = 0;
          // Change of paragraph.
          if (counter > 1){
            outFile << "\n";
            for(int i = 0 ; i < leftMargin ; i++){
                outFile << " ";
            }
        }
    }
    outFile.close();
}