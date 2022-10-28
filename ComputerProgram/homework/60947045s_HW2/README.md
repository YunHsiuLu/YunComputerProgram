60947045S 資工碩三 呂昀修
# make
1. compile all files
2. execute all files

# make [number].o
1. compile hw010[number].c
2. execute it

# make compile_all.o

# make exec_all.o

# explaination

* hw0201:
As shown in the screen

* hw0202:
不確定10-10-101這樣算不算回文，我就一樣算進去了，不然第一個回文日期應該會是10-01-1001。有加入日期檢查機制以及閏年機制，所以允許出現02-29-9220這樣的回文日期，剛好9220是閏年。

* hw0203:
As shown in the screen

* hw0204:
這裡有出現一個小問題，為了呈現與老師作業內容相同的結果，我有取小數位至第二位，使得前三列的結果一模一樣，卻導致最後一期的金額會剩下一點點。從老師給的mortgage calculator查詢一模一樣的條件，發現我的結果與模擬器的前359項（30年x12個月）完全一樣，但最後一項模擬器直接使剩餘金額歸零，但按照公式計算，理論上一定會剩下一點點。但整體來說，程式是正確運行的。

* hw0205:
作業中有一個問題，只考慮到terminal screen width = 80的情況，並沒有說明若screen width > 80時，cube要怎麼安排。若要在c裡面自動抓取terminal screen size的話，我不會用，我也怕助教的批改系統無法執行，導致出現並非作業的錯誤，所以我就設定若總寬度超過80就wrap。

* hw0206:
若兩個不同data type的變數相加，會跟隨等級較大的data type做casting。例如：(int16_t)+(int32_t)會cast成(int32_t)，(uint32_t)+(int32_t)會cast成(uint32_t)。所以說就導致了(uint32_t)(0) + (int32_t)(-1)時的-1變成uint32_t的2^32-1，並且兩個數相加。(int32_t)(-1) = 0b111...1111 (有32個1)。
最後再變成(int64_t)時，會去判斷當下的data type為何，去padding 0 or 1。像(uint32_t)(0) + (int32_t)(-1)的結果是(uint32_t)(2^32-1)，int64_t就會padding 0。而(uint16_t)(0) + (int32_t)(-1)的結果會被cast成(int32_t)(-1)，int64_t就會去padding 1，使得int64_t保持為負數。
