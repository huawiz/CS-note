# Computer-System Organization

這一節，我們要介紹電腦基本的組織架構。

## Computer-System Operation

在現代，大多數電腦都有多元處理（Multiprocessing，即多核心）系統，以及許多的設備控制器（例如USB Controller，負責處理I/O設備），這些硬體都共用一個通道和分享記憶體(RAM)，如下圖。


![Image](https://i.imgur.com/Xpe7GNr.png)

在這張圖中，各種不同的設備都連結到各自的設備控制器，這些控制器再進一步連結到RAM，被所有設備共用。現代電腦可以連結多顆CPU，但是這張圖為了簡單說明電腦，因此只有呈現一顆。

## Components

- Central Processing Unit (CPU) : The Brain of Computer. 處理程序與運算。

- Device Controller : Between CPU and Device. 處理設備I/O訊號。

- Memory：Data Storge Unit. 暫存不同來源的資料。

> 所有的設備都共用記憶體，然而這麼多設備，勢必要找一個方法分配記憶體使用，不然記憶體有限的空間一下就被吃滿了。那電腦科學家是怎麼處理這件事的呢？

先再認識幾個名詞：

- Bootstrap Program 啟動程式
  - 當電腦開機或者重開的時候，開啟的第一個程式。
  - 它負責初始化所有事物，依序CPU>Device Controller>memory。
  - 載入OS系統進memory以執行
  - 只存在ROM(Read-Only Memory)

- Kernel 核心
  - OS的心臟，它會被啟動程式載入記憶體中，並且永久駐留在此，是OS和硬體間的功能層，讓應用程式和硬體互動。

![Image](https://i.imgur.com/38u4xTT.png)

- Interrupt [中斷](https://zh.wikipedia.org/wiki/%E4%B8%AD%E6%96%B7)
    - 每當電腦有突發狀況需要優先處理，OS都需要在事情發生前發出訊號，以便如果需要立即完成，CPU可以優先處理。而這個信號就是Interrupt。

- Hardware-initiated interrupts 硬體啟動中斷
  - 透過系統總線向CPU發出訊號。
  - 在獲取輸入以及顯示輸出時需要硬體中斷。

- Software-initiated interrupts 軟體啟動中斷
  - 這種中斷類型又分成兩種：System Call、Monitor Call
  - 為了運作OS的任何函數，電腦會需要使用System Call來從核心模式(Kernek mode)切換成使用者模式(User mode)。
  - System Call有五種主要類型：
    - Process Control
    - File Manipulation
    - Device Management
    - Information Maintenance
    - Communications

> 硬體啟動中斷優先於軟體啟動中斷


## CPU是如何回應中斷的？
所有記憶體都有特別的中斷處理機制，每當CPU軟硬體觸發中斷時，CPU會立刻停止其工作，並且立刻取得Interrupt Service Routine(ISR)的起始位置，並且執行ISR，執行完成後再回到中斷點繼續執行原本的工作。

> 每個中斷都有它的歷程，而當CPU被中斷（插隊）時，就會先去跑完中斷的歷程後，再回來跑原來的歷程。

## 總結
我們已經介紹了計算機結構設計的基礎。它的佈局非常簡陋，並且了解一些專有名詞，例如Bootstrap Program、Interrupt等等。CPU會不時被中斷，並且迅速處理它，處理完之後才能順利地持續運作，然後再回到被中斷點繼續執行工作。


