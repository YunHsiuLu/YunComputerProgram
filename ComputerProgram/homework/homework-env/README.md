# TA 批改環境
這是程設 TA 的批改環境，基本上基於 docker 與 Linux 權限做隔離（我沒做多少隔離拉 XD ），
請使用 `./start.sh` 啟動環境

另外注意，此環境特地降權到一般使用者，並且不打算開放管理員權限，因此也沒有 sudo 指令。請勿詢問「可否開啟 root 權限」這種問題。

## Overlay FS
Overlay FS 可以使的在保證 `./share`  資料夾裡面的東西不動的狀況下，容器內部可以看到裡面的內容並做「退出後就無效的寫入」，也就是形成一個安全且可讀寫的檔案系統。

這個檔案系統會在啟動時掛載，因為需要掛載檔案系統，因此需要管理員權限，請記得授予管理員密碼（誤必要安裝 sudo ，並具備足夠權限）。離開時會自動清理環境，會 unmount 你的 overlayfs ，因此也需要管理員密碼，也請務必提供。

# 運行你的程式
在這個環境中有些事情是你需要你注意的，包括消除 alpine linux 環境帶來的影響與使用 valgrind 上的一些技巧

## Inject TA Code
因為遇到 alpine linux 中預帶的 libc 實作： musl 的 stdout buffer 機制，使得我們會需要在程式中注入一些我預先寫好的 code 使得 stdout 可以不做 buffer （具體病徵就是 scanf 時看不到前面 printf 的內容，看起來會很奇怪）。

執行程式時，請加上環境變量： `LD_PRELOAD=libinject.so` ，具體來說會長成這樣：
```sh
LD_PRELOAD=libinject.so <你的程式>
```
## Valgrind
使用 valgrind 非常簡單，以下是使用方法：
```sh
valgrind <你的程式>
```
這樣他就會在你的程式出現非法記憶體存取錯誤時直接崩潰並告訴你出現錯誤的地方在哪裡，且在程式結束時報告記憶體使用的狀況，包括是否有記憶體洩漏

使用 valgrind 時也要記得加上 `LD_PRELOAD` 的環境變量，因此整個指令會變成：
```sh
LD_PRELOAD=libinject.so valgrind <你的程式>
```
