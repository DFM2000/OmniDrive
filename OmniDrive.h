#ifndef OmniDrive_H
#define OmniDrive_H

#include "mbed.h"

class OmniDrive
{
public:
    /*
    セットアップ関数
    nWheel:車輪の個数(3~8),fstWheelAng:x軸と0番目の車輪軸のなす角度(deg) */
    void setup(int nWheel,float fstWheelAng);
    
    /*
    全方位移動入力関数(極座標)
    r:マシンの速度(0~1),theta:マシンの進行方向(角度deg ex.90,-45)
    Vroll:マシンの回転速度(-1~1)     */
    void input_polar(float r,float theta,float Vroll);
    
    /*
    マシンの傾き角度を考慮した全方位移動入力関数(極座標)
    MachineAng:マシンの現在角度(角度deg ex.90,-45)  */
    void input_polar(float r,float theta,float Vroll,float MachineAng);
    
    /*
    全方位移動入力関数(直交座標)
    x:マシンのx方向速度(-1~1),y:マシンのy方向速度(-1~1)
    Vroll:マシンの回転速度(-1~1)    */
    void input_cartesian(float x,float y,float Vroll);
    
    /*
    マシンの傾き角度を考慮した全方位移動入力関数(直交座標)
    MachineAng:マシンの現在角度(角度deg ex.90,-45)  */
    void input_cartesian(float x,float y,float Vroll,float MachineAng);
    
    /*
    全方位移動出力関数(アドレスよくわからん人用)
    引数:n番目の車輪の回転速度  */
    float output_(int n);
    
    /*
    全方位移動出力関数
    *v:車輪回転速度の配列の先頭アドレス  */
    void output(float *V);

private:
    int i,nWheel;
    float Vx_wheel[8],Vy_wheel[8],Vx,Vy,Vroll,r,theta;
    
    float limit(float min,float max,float _value);
    float conv_deg(float _rad);
    float conv_rad(float _deg);
};

#endif
