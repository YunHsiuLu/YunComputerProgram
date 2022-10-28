# make
1. compile all files
2. execute all files

# make [number].o
1. compile hw010[number].c
2. execute it

# make compile_all.o

# make exec_all.o

# explaination

* hw0101: 
我用藍色的ansi跳脫字元(\x1b[34m)來標注personal names，以及用紅色的ansi跳脫字元(\x1b[31m)來標注operating system
在每個標示詞的後面加上表示復原的ansi escape code (\x1b[0m)

* hw0102: 
輸入兩個3 digits的整數，輸出相減結果
ex. 
Please enter the first number:  999
Please enter the second number: 111
   9 9 9
-) 1 1 1
-----------
   8 8 8

若輸入不是3 digits的整數，輸出(a or b) is not 3 digits number!
若在輸入第一個整數時，就同時輸入兩個整數(ex. Please enter the first number:  333 111)
會輸出
Please enter the first number:  333 111
Please enter the second number:    3 3 3
-) 1 1 1
-----------
   2 2 2

* hw0103:
輸入三個點座標，會輸出與AB相垂直並且過C的線方程

* hw0104:
這邊我直接輸出了計算之後的結果
作業要求中並無詳細表明測資要輸入哪些資料
所以我在作業要求中的數值範圍取random，
並按照damage計算公式算出要求的結果
為了“美化”程式，我用struct定義pokemon以及env

* hw0105:
先檢查輸入的值是否合法
為了方便判定結果，先把合法的輸入做sorting
(這邊是用bubble sort，為什麼不用效率更高的merge sort，因為太麻煩了)
依照輸入的card number，輸出相對應的card suit以及1 - 13的card number
以及輸出該組手牌為何

* hw0106:
依照測試結果，不難發現printf() return的值是printf()中字串的長度
(不包含\0)
ex.
> Hello
> return value of printf("Hello\n"): 6
> 12345678
> return value of printf("12345678\n"): 9











