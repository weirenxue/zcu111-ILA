# ZCU111 ILA的IP使用範例。
##### 開發工具：Vivado2019.1，SDK2019.1，ZCU111開發板與相關資料。
#### 1. 這個專案是用來練習使用ILA的流程，不會介紹ILA。

#### 2. 開啟Vivado專案，在Block Design內加入Zynq UltraScale+ MPSoC、AXI_GPIO、ILA。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Impot_Needed_IP.png"  title="MPSoC GPIO ILA" width="50%"></p>

#### 3. 滑鼠左鍵點開ila，進入設定畫面，按照圖中設定。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/ILA_Setting.png"  title="ILA Setting " width="50%"></p>

#### 4. 按Run Block Automation用以preset MPSoC，再按Run Connection Automation，GPIO的界面選擇led_8bits。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Run_Connection_Automation.png"  title="Run Connection Automation Setting" width="50%"></p>

#### 5. 步驟4做完Run Connection Automation還會在，再按一次把剩下的腳位連接補齊，最後電路圖應該要如下，橘色線的部份是手動拉的。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Final_Block.png"  title="Final Circuit Block Diagram" width="80%"></p>

#### 6. 按f6確認驗證沒有錯誤，且Create HDL Wrapper，就可以開始合成，在PROGRAM AND DEBUG下按Generate Bitstream，最後Export Hardware並開啟SDK。(若不熟悉請參考[zcu111-EMIO](https://github.com/weirenxue/zcu111-EMIO))

#### 7. 接下來的步驟需要PC接上ZCU111開發板，Jtag與其電源，並開啟開發板電源。

#### 8. 在Vivado界面的PROGRAM AND DEBUG下點開Open Hardware Manager，選擇Open New Target。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/New_Hardware_Manager.png"  title="New Hardware Manager" width="30%"></p>

#### 9. 按兩次Next>，若Hardware Devices有看到裝置，表示連線沒問題，按一次Next>與Finish，會顯示一個HARDWARE MANAGER的畫面。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Hardware_Manager_Setting.png"  title="Hardware Manager Setting" width="50%"></p>

#### 10. 在Hardware視窗內選擇xczu28dr_0按滑鼠右鍵，選擇Program Device，按下Program燒錄bit檔案與ltx檔案，等待燒錄完成。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/Program_Device.png"  title="Program Device" width="80%"></p>

#### 11. 到SDK開啟一個Hellow World的Application Project，並燒錄到PS(Run As/Launch on Hardware(GDB))(參考[zcu111-EMIO](https://github.com/weirenxue/zcu111-EMIO))，此步驟的用意是初始化PS，否則ILA無法使用。

#### 12. PS初始化成功後，回到Vivado界面，點擊在步驟10有出現的Refresh device，ILA就會出現！
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/ILA_appear.png"  title="ILA appear" width="80%"></p>

#### 13. 現在還沒有波形，按藍色三角形圖示(Run Trigger)，波形就會出現了，此設計中預設輸出是全部為0。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/ILA_wave_default.png"  title="ILA default wave" width="80%"></p>

#### 14. 燒錄/code/main.c到PS上，程式碼功能為使GPIO輸出為1100_0011。

#### 15. 再按一次Run Trigger，此時ILA的probe量測到的的確為1100_0011。
<p align=center><img src="https://github.com/weirenxue/zcu111-ILA/blob/master/pic/ILA_wave_changed.png"  title="ILA changed wave" width="80%"></p>
