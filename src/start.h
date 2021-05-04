/**
 * 
 * ESP Start/SetUP
 * 
 */

#ifndef _ESP_REMOTE_CONTROL_START_
#define _ESP_REMOTE_CONTROL_START_

#include <Arduino.h>
#include <IR.h>
#include <WIFI.h>
#include <Config.h>

//-----------宏定义---------------------------
#define SERIAL_BAUD 115200       //串口波特率
#define IR_RECV_PIN  4           //recPin
#define IR_RECV_BUFFER_SIZE 300  //bufSize
#define IR_SEND_PIN 5            //sendPin
#define LED_PIN 2                //ledPin
#define USE_LED true             //是否启用led


//-----------静态变量初始化--------------------
Config *Config::_config = nullptr;
IR *IR::_ir = nullptr;


void start(){
    Serial.begin(SERIAL_BAUD);       //设置串口波特率
    if(USE_LED){
        pinMode(LED_PIN,OUTPUT);       //led脚输出，低电平点亮
        digitalWrite(LED_PIN, HIGH);   //默认高电平，关闭led
    }
    Config::start();                 //读取config，必须在其他功能前启动
    WIFI::start();                   //启动WIFI
    IR::start(IR_RECV_PIN, IR_RECV_BUFFER_SIZE, IR_SEND_PIN, USE_LED, LED_PIN);   //启动红外
}

#endif
