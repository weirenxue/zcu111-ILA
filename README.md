# ZCU111 ILA的IP使用範例。
##### 開發工具：Vivado2019.1，SDK2019.1，ZCU111開發板與相關資料。
#### 1. 這個專案是用來練習使用ILA的流程，不會介紹ILA。

#### 2. 開啟Vivado專案，在Block Design內加入Zynq UltraScale+ MPSoC、AXI_GPIO、ILA。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Impot_Needed_IP.png"  title="MPSoC GPIO ILA" width="30%"></p>

#### 3. 滑鼠左鍵點開ila，進入設定畫面，按照圖中設定。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/ILA_Setting.png"  title="ILA Setting " width="30%"></p>

#### 4. 按Run Block Automation用以preset MPSoC，再按Run Connection Automation，GPIO的界面選擇led_8bits。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Run_Connection_Automation.png"  title="Run Connection Automation Setting" width="30%"></p>

#### 5. 步驟4做完Run Connection Automation還會在，再按一次把剩下的腳位連接補齊，最後電路圖應該要如下，橘色線的部份是手動拉的。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Final_Block.png"  title="Final Circuit Block Diagram" width="80%"></p>

#### 6. 按f6確認驗證沒有錯誤，且Create HDL Wrapper，就可以開始合成，在PROGRAM AND DEBUG下按Generate Bitstream，最後Export Hardware並開啟SDK。(若不熟悉請參考[zcu111-EMIO](https://github.com/weirenxue/zcu111-EMIO))
