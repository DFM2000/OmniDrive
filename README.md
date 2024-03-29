# OmniDrive

## 使用環境
- mbed-os

## 説明
このライブラリは極座標(or直交座標)で表したマシンの走行速度、進行方向から各車輪の回転速度を演算するライブラリです。  
3~8輪までの車輪数や車輪の位置などを指定できます。    

- ホイールの位置関係(4つの場合)  
  注.4つの場合は0,1,2,3とナンバリングする  

```
       front  
  ┌───────────────┐  
  │     w1←       │  
 l│       y       │r  
 e│       ↑     w0│i  
 f│↓      . →x   ↑│g  
 t│w2             │h  
  │               │t  
  │       →w3     │  
  └───────────────┘  
         back         
```

この場合の配置では0番目の車輪軸の角度fstWheelAngは0度となる

- マシンの進行方向thetaについて  
例)theta=0の場合→right方向に進む  
   theta=90の場合→front方向に進む  
   theta=-90の場合→back方向に進む  
   theta=180(or theta=-180)の場合→left方向に進む  
   
- マシンの回転速度Vrollについて  
　値が正(>0)であれば反時計回り、値が負(<0)であれば時計回りにマシンが回転する  

## サンプルコード
以下が4輪の場合のサンプルコードになります。  
```
 #include "mbed.h"
 #include "OmniDrive/OmniDrive.h" //インクルァぁドしてネ
 
 OmniDrive mekanamu; //TickerやTimerのように宣言
  
 int main(){
     float motor_output[4];//それぞれのモータ出力変数(配列)を用意
     
     mekanamu.setup(4,45); //車輪の個数、位置を設定(1度宣言すればいい)
     
     while(1) {
         
         mekanamu.input_polar(0.5,90,0); //マシンの走行速度、進行方向、回転速度の入力
         
         //配列の先頭アドレスを渡すことでそれぞれのモータ出力変数に値を入力
         mekanamu.output(motor_output);
         
     }
 }
```
