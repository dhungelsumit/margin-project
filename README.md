## Margin Project
 
Computers are widely used to help produce written documents. One desirable capability of a word processing system is margin manipulation. This enables text to be formatted with a left and right margin selected by a user. The word processing program allocates words to lines in order to satisfy the margin requirements.

For this project you are to write a program which will process a text file and produce as output a) a displayed listing of the edited text and also b) save the produced file on your directory (DAT1.TXT). The input data must contain (the text file) two integers (inches) specifying the left and right margins, respectively, to be used in generating the output listing. With these margins in mind, your program should process the remaining text in the file. The program should include as many words as can “fit” between the margins. No words should extend beyond the right margin. (Note: your program need not “right justify” the text! It must simply observe the margins.)

For this problem, a “word” is any sequence of consecutive non-blank characters, and thus may include punctuation or special characters. There may be trailing blanks after words which your program should ignore. Your program should leave 1 blank between words, and 2 blanks between sentences in the output (listing and saved file). You need to be concerned with paragraphs and all lines, including the first, should begin at the left
margin. You may also assume the maximum input line is 80 characters long.

You should create your own data file, as described, and name it DAT1.TXT on your directory. You should develop an algorithm.
The program should be developed using C++ .

