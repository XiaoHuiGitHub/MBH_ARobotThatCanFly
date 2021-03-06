/*
 * driver.h
 *
 *  Created on: Apr 16, 2016
 *
 *  四轴飞行控制器  Copyright (C) 2016  李德强
 */

#ifndef _INCLUDE_DRIVER_H_
#define _INCLUDE_DRIVER_H_

#include <typedef.h>

//摇控器接收机的3个通道引脚
#define GPIO_FB				(12)
#define GPIO_LR				(14)
#define GPIO_PW				(13)

//4个电机的GPIO引脚
//#define PORT_SPEED0	  		(1)
//#define PORT_SPEED1	  		(15)
//#define PORT_SPEED2	  		(6)
//#define PORT_SPEED3	  		(16)
#define PORT_SPEED0	  		(27)
#define PORT_SPEED1	  		(28)
#define PORT_SPEED2	  		(26)
#define PORT_SPEED3	  		(29)

//摇控器接收机的3个通道读数范围
#define CTL_PWM_MIN				(980)
#define CTL_PWM_MAX				(2020)

//最大调试时长10秒
#define MAX_INIT_MS			(10000)
//PWM信号时长
#define TIME_PWM_WIDTH		(2000)
//电调起始时长
#define TIME_DEP			(1000)

//PWM信号结构
typedef struct
{
	//高电平时长
	int time_m;
	//低电平时长
	int time_w;
} driver_pwm;

//电机实际速度
typedef struct
{
	//电机实际速度
	int speed;
} s_driver;

typedef struct
{
	struct timeval timer_start;
	struct timeval timer_end;
	long timer_avg;
	long timer_sum;
	long timer_max;
	long timer_min;
	long timer_n;
} s_ctl_pwm;

//驱动程序初始化
void driver_setup();

//电机调试
void driver_ent_run(int en_port, int en_speed, int en_msecs);

//读取摇控器接收机的PWM信号“前后”
void driver_ctl_pwm_fb();

//读取摇控器接收机的PWM信号“左右”
void driver_ctl_pwm_lr();

//读取摇控器接收机的PWM信号“油门”
void driver_ctl_pwm_pw();

//读取摇控器接收机的PWM信号
void driver_ctl_pwm();

//清理驱动
void driver_clear();

//将电机速度转为PWM信号
void driver_set_pwm(int speed, driver_pwm *pwm);

//对电机0发送PWM信号
void driver_run_pwm0(driver_pwm *pwm);

//对电机1发送PWM信号
void driver_run_pwm1(driver_pwm *pwm);

//对电机2发送PWM信号
void driver_run_pwm2(driver_pwm *pwm);

//对电机3发送PWM信号
void driver_run_pwm3(driver_pwm *pwm);

//向电机0发送PWM信号
void driver_run0();
//向电机1发送PWM信号
void driver_run1();

//向电机2发送PWM信号
void driver_run2();

//向电机3发送PWM信号
void driver_run3();

//设置电机0实际速度
void driver_set_speed0(int speed);

//设置电机1实际速度
void driver_set_speed1(int speed);

//设置电机2实际速度
void driver_set_speed2(int speed);

//设置电机3实际速度
void driver_set_speed3(int speed);

#endif /* INCLUDE_DRIVER_H_ */
