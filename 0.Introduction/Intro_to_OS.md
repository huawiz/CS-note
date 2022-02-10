# Intro to Operating System

> 這篇會稍微介紹OS。

## Introduction

Operation System (OS) 是一個管理電腦硬體的程式，它提供使用者與計算機硬體間溝通的橋樑，一般我們常看到的系統有Windows,Linux,Mac OS，手機系統也有iOS,Android等等，這些都是OS。

## OS的基本元件
一套電腦系統，我們會把他分成四個基本元件：
1.硬體
2.OS
3.應用程式
4.使用者

一部電腦的運作能分成很多個層級，而每個層級大概能被歸類成這四種基本元件，可以用下圖表示關係。

![](https://firebasestorage.googleapis.com/v0/b/neso-c53c4.appspot.com/o/ImageResource%2FNotesImages%2FOperating%20Systems%2FOS1_01%2F101.svg?alt=media&token=2b3c1e9f-55bc-4933-ae36-d9c410ef0f4a)


在最低的硬體層級，有CPU,記憶體(memory),I/O devices(例如鍵盤滑鼠)等等，還有其他實體存在的設備。再上一層有OS，提供上層程式與硬體間的溝通橋樑，而上層程式又分成兩個類型，系統程式與應用程式。

### 系統程式 System Programs

用來直接修改硬體或是對硬體發出某些指令的程式，我們稱其為系統程式，例如所有作業系統、程式語言以及驅動程式。

### 應用程式 Application Programs
用於執行特定任務，讓使用者可以直接使用的軟體，稱為應用程式。例如Word、Spreadsheets、文字編輯器、瀏覽器等等。

## OS扮演的角色

以使用者使用Word編輯文件來舉例，如果今天有位使用者想使用電腦來寫文件，但是這台電腦並沒有作業系統，那他若還想使用這台電腦，他就要親自出馬寫一些硬體看得懂的語言來控制系統。

首先他需要把Word程式載入記憶體當中，以便他可以使用。完成這個大工程後（要和硬體溝通可不容易），他才能開始打字，但是他還必須檢查他輸入的內容是否真的有確實輸入成功，他還必須要求硬體，從記憶體把資料顯示到螢幕上，最後他要保存的時候，又要再和硬體溝通，好讓他確實把資料存進硬碟裡。

若是沒有OS，每個硬體間的切換將會變得很複雜，我們操作起來就會變得很不順，每一個工作都會變得很繁瑣，這也是為什麼我們需要一套程式來幫助我們做溝通，好讓我們每次工作，都不用再花大成本與電腦溝通，只要點點滑鼠、敲敲鍵盤就能使用應用程式。

## OS類型

最常見的OS類型如下：
- Batch Operating System 
- Time Sharing Operating System
- Distributed Operating System
- Network Operating System
- Real time Operating System
- Multiprogramming/Processing/Tasking Operating System (這些很像但不太一樣)

## OS功能

OS有許多的功能，這編列幾個主要的：
- 充當使用者與硬體的介面
- 分配硬體與軟體的資源
- 管理記憶體使用，並且處理安全問題

OS還有其他很多功能，最重要的OS幫助我們達成便利與效率，讓我們和硬體間的溝通變得容易，讓生活變得更加簡單。

## 總結

我們知道OS系統是一種軟體，被用來作為不同設備間溝通的介面。OS管理硬體為應用程式提供良好的運作基底，降低使用者的操作難度，讓使用者可以快快樂樂的使用電腦，當然OS也是讓系統程式能順跑的關鍵。
