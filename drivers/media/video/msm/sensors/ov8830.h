/* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <mach/board.h>
extern struct platform_driver ov8830_driver;

static struct msm_camera_i2c_reg_conf ov8830_start_settings[] = {
	{0x0100, 0x01},
};

static struct msm_camera_i2c_reg_conf ov8830_stop_settings[] = {
	{0x0100, 0x00},
};

static struct msm_camera_i2c_reg_conf ov8830_groupon_settings[] = {
	{0x3208, 0x00},
};

static struct msm_camera_i2c_reg_conf ov8830_groupoff_settings[] = {
	{0x3208, 0x10},
	{0x3208, 0xA0},
};

static struct msm_camera_i2c_reg_conf ov8830_snap_settings[] = {
/*OV 3280x2464_24fps_4lanes*/
	{0x0103, 0x01},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0102, 0x01},
	{0x3001, 0x2a},
	{0x3002, 0x88},
	{0x3005, 0x00},
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x301b, 0xb4},
	{0x301d, 0x02},
	{0x3021, 0x00},
	{0x3022, 0x00},
	{0x3081, 0x02},
	{0x3083, 0x01},
	{0x3090, 0x02},
	{0x3091, 0x12},
	{0x3092, 0x00},
	{0x3093, 0x00},
	{0x3098, 0x03},
	{0x3099, 0x1e},
	{0x309a, 0x00},
	{0x309b, 0x00},
	{0x30a2, 0x01},
	{0x30b0, 0x05},
	{0x30b2, 0x00},
	{0x30b3, 0x2d},
	{0x30b4, 0x02},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x3104, 0xa1},
	{0x3106, 0x01},
	{0x3400, 0x04},
	{0x3401, 0x00},
	{0x3402, 0x04},
	{0x3403, 0x00},
	{0x3404, 0x04},
	{0x3405, 0x00},
	{0x3406, 0x01},
	{0x3500, 0x00},
	{0x3501, 0x9a},
	{0x3502, 0x80},
	{0x3503, 0x07},
	{0x3504, 0x00},
	{0x3505, 0x30},
	{0x3506, 0x00},
	{0x3507, 0x10},
	{0x3508, 0x80},
	{0x3509, 0x10},
	{0x350a, 0x00},
	{0x350b, 0x38},
	{0x3600, 0x78},
	{0x3601, 0x02},
	{0x3602, 0x1c},
	{0x3604, 0x38},
	{0x3620, 0x64},
	{0x3621, 0xb5},
	{0x3622, 0x03},
	{0x3625, 0x64},
	{0x3630, 0x55},
	{0x3631, 0xd2},
	{0x3632, 0x00},
	{0x3633, 0x34},
	{0x3634, 0x03},
	{0x3660, 0x80},
	{0x3662, 0x10},
	{0x3665, 0x00},
	{0x3666, 0x00},
	{0x3667, 0x00},
	{0x366a, 0x80},
	{0x366c, 0x00},
	{0x366d, 0x00},
	{0x366e, 0x00},
	{0x366f, 0x20},
	{0x3680, 0xe0},
	{0x3681, 0x00},
	{0x3701, 0x14},
	{0x3702, 0xbf},
	{0x3703, 0x8c},
	{0x3704, 0x78},
	{0x3705, 0x02},
	{0x3708, 0xe4},
	{0x3709, 0x03},
	{0x370a, 0x00},
	{0x370b, 0x20},
	{0x370c, 0x0c},
	{0x370d, 0x11},
	{0x370e, 0x00},
	{0x370f, 0x00},
	{0x3710, 0x00},
	{0x371c, 0x01},
	{0x371f, 0x0c},
	{0x3721, 0x00},
	{0x3724, 0x10},
	{0x3726, 0x00},
	{0x372a, 0x01},
	{0x3730, 0x18},
	{0x3738, 0x22},
	{0x3739, 0x08},
	{0x373a, 0x51},
	{0x373b, 0x02},
	{0x373c, 0x20},
	{0x373f, 0x02},
	{0x3740, 0x42},
	{0x3741, 0x02},
	{0x3742, 0x18},
	{0x3743, 0x01},
	{0x3744, 0x02},
	{0x3747, 0x10},
	{0x374c, 0x04},
	{0x3751, 0xf0},
	{0x3752, 0x00},
	{0x3753, 0x00},
	{0x3754, 0xc0},
	{0x3755, 0x00},
	{0x3756, 0x1a},
	{0x3758, 0x00},
	{0x3759, 0x0f},
	{0x375c, 0x04},
	{0x3767, 0x01},
	{0x376b, 0x44},
	{0x3774, 0x10},
	{0x3776, 0x00},
	{0x377f, 0x08},
	{0x3780, 0x22},
	{0x3781, 0x0c},
	{0x3784, 0x2c},
	{0x3785, 0x1e},
	{0x378f, 0xf5},
	{0x3791, 0xb0},
	{0x3795, 0x00},
	{0x3796, 0x64},
	{0x3797, 0x11},
	{0x3798, 0x30},
	{0x3799, 0x41},
	{0x379a, 0x07},
	{0x379b, 0xb0},
	{0x379c, 0x0c},
	{0x37c5, 0x00},
	{0x37c6, 0xa0},
	{0x37c7, 0x00},
	{0x37c9, 0x00},
	{0x37ca, 0x00},
	{0x37cb, 0x00},
	{0x37cc, 0x00},
	{0x37cd, 0x00},
	{0x37ce, 0x01},
	{0x37cf, 0x00},
	{0x37d1, 0x01},
	{0x37de, 0x00},
	{0x37df, 0x00},
	{0x3800, 0x00},
	{0x3801, 0x04},
	{0x3802, 0x00},
	{0x3803, 0x04},
	{0x3804, 0x0c},
	{0x3805, 0xdb},
	{0x3806, 0x09},
	{0x3807, 0xab},
	{0x3808, 0x0c},
	{0x3809, 0xd0},
	{0x380a, 0x09},
	{0x380b, 0xa0},
	{0x380c, 0x0e},
	{0x380d, 0x18},
	{0x380e, 0x09},
	{0x380f, 0xc4},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x52},
	{0x3821, 0x08},
	{0x3823, 0x00},
	{0x3824, 0x00},
	{0x3825, 0x00},
	{0x3826, 0x00},
	{0x3827, 0x00},
	{0x382a, 0x04},
	{0x3a04, 0x09},
	{0x3a05, 0xa9},
	{0x3a06, 0x00},
	{0x3a07, 0xf8},
	{0x3b00, 0x00},
	{0x3b02, 0x00},
	{0x3b03, 0x00},
	{0x3b04, 0x00},
	{0x3b05, 0x00},
	{0x3d00, 0x00},
	{0x3d01, 0x00},
	{0x3d02, 0x00},
	{0x3d03, 0x00},
	{0x3d04, 0x00},
	{0x3d05, 0x00},
	{0x3d06, 0x00},
	{0x3d07, 0x00},
	{0x3d08, 0x00},
	{0x3d09, 0x00},
	{0x3d0a, 0x00},
	{0x3d0b, 0x00},
	{0x3d0c, 0x00},
	{0x3d0d, 0x00},
	{0x3d0e, 0x00},
	{0x3d0f, 0x00},
	{0x3d80, 0x00},
	{0x3d81, 0x00},
	{0x3d84, 0x00},
	{0x4000, 0x18},
	{0x4001, 0x04},
	{0x4002, 0x45},
	{0x4004, 0x02},
	{0x4005, 0x1A},
	{0x4006, 0x16},
	{0x4008, 0x20},
	{0x4009, 0x10},
	{0x4058, 0x00},
	{0x4101, 0x12},
	{0x4104, 0x5b},
	{0x4307, 0x30},
	{0x4315, 0x00},
	{0x4511, 0x05},
	{0x4512, 0x01},
	{0x4805, 0x01},
	{0x4806, 0x00},
	{0x481f, 0x36},
	{0x4831, 0x6c},
	{0x4837, 0x0d},
	{0x4a00, 0xaa},
	{0x4a03, 0x01},
	{0x4a05, 0x08},
	{0x4a0a, 0x88},
	{0x5000, 0x06},
	{0x5001, 0x01},
	{0x5002, 0x80},
	{0x5003, 0x20},
	{0x5013, 0x00},
	{0x5046, 0x4a},
	{0x5780, 0x1c},
	{0x5786, 0x20},
	{0x5787, 0x10},
	{0x5788, 0x18},
	{0x578a, 0x04},
	{0x578b, 0x02},
	{0x578c, 0x02},
	{0x578e, 0x06},
	{0x578f, 0x02},
	{0x5790, 0x02},
	{0x5791, 0xff},
	{0x5a08, 0x02},
	{0x5e00, 0x00},
	{0x5e10, 0x0c}
};

static struct msm_camera_i2c_reg_conf ov8830_prev_settings[] = {
/*OV 2592x1944_30fps_4lanes*/
	{0x0103, 0x01},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0102, 0x01},
	{0x3000, 0x00},
	{0x3001, 0x2a},
	{0x3002, 0x88},
	{0x3003, 0x00},
	{0x3004, 0x00},
	{0x3005, 0x00},
	{0x3006, 0x00},
	{0x3007, 0x00},
	{0x3008, 0x00},
	{0x3009, 0x00},
	{0x3011, 0x41},
	{0x3012, 0x08},
	{0x3013, 0x10},
	{0x3014, 0x00},
	{0x3015, 0x08},
	{0x3016, 0xf0},
	{0x3017, 0xf0},
	{0x3018, 0xf0},
	{0x301b, 0xb4},
	{0x301d, 0x02},
	{0x3021, 0x00},
	{0x3022, 0x00},
	{0x3024, 0x00},
	{0x3026, 0x00},
	{0x3027, 0x00},
	{0x3081, 0x02},
	{0x3083, 0x01},
	{0x3090, 0x02},
	{0x3091, 0x12},
	{0x3092, 0x00},
	{0x3093, 0x00},
	{0x3098, 0x03},
	{0x3099, 0x1e},
	{0x309a, 0x00},
	{0x309b, 0x00},
	{0x30a2, 0x01},
	{0x30b0, 0x05},
	{0x30b2, 0x00},
	{0x30b3, 0x2d},
	{0x30b4, 0x02},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x3104, 0xa1},
	{0x3106, 0x01},
	{0x3300, 0x00},
	{0x3400, 0x04},
	{0x3401, 0x00},
	{0x3402, 0x04},
	{0x3403, 0x00},
	{0x3404, 0x04},
	{0x3405, 0x00},
	{0x3406, 0x01},
	{0x3500, 0x00},
	{0x3501, 0x4c},
	{0x3502, 0x80},
	{0x3503, 0x07},
	{0x3504, 0x00},
	{0x3505, 0x30},
	{0x3506, 0x00},
	{0x3507, 0x08},
	{0x3508, 0x80},
	{0x3509, 0x10},
	{0x350a, 0x00},
	{0x350b, 0x38},
	{0x350c, 0x00},
	{0x350d, 0x00},
	{0x3600, 0x78},
	{0x3601, 0x02},
	{0x3602, 0x1c},
	{0x3604, 0x38},
	{0x3620, 0x44},
	{0x3625, 0x44},
	{0x3621, 0xb5},
	{0x3622, 0x0b},
	{0x3630, 0x55},
	{0x3631, 0xd2},
	{0x3632, 0x00},
	{0x3633, 0x34},
	{0x3634, 0x03},
	{0x3660, 0x80},
	{0x3662, 0x10},
	{0x3665, 0x00},
	{0x3666, 0x00},
	{0x3667, 0x00},
	{0x366a, 0x80},
	{0x366c, 0x00},
	{0x366d, 0x00},
	{0x366e, 0x00},
	{0x366f, 0x20},
	{0x3680, 0xe0},
	{0x3681, 0x00},
	{0x3701, 0x14},
	{0x3702, 0xbf},
	{0x3703, 0x8c},
	{0x3704, 0x78},
	{0x3705, 0x02},
	{0x3708, 0xe4},
	{0x3709, 0x03},
	{0x370a, 0x00},
	{0x370b, 0x20},
	{0x370c, 0x0c},
	{0x370d, 0x11},
	{0x370e, 0x00},
	{0x370f, 0x00},
	{0x3710, 0x00},
	{0x371c, 0x01},
	{0x371f, 0x0c},
	{0x3721, 0x00},
	{0x3724, 0x10},
	{0x3726, 0x00},
	{0x372a, 0x01},
	{0x3730, 0x18},
	{0x3738, 0x22},
	{0x3739, 0x08},
	{0x373a, 0x51},
	{0x373b, 0x02},
	{0x373c, 0x20},
	{0x373f, 0x02},
	{0x3740, 0x42},
	{0x3741, 0x02},
	{0x3742, 0x18},
	{0x3743, 0x01},
	{0x3744, 0x02},
	{0x3747, 0x10},
	{0x374c, 0x04},
	{0x3751, 0xf0},
	{0x3752, 0x00},
	{0x3753, 0x00},
	{0x3754, 0xc0},
	{0x3755, 0x00},
	{0x3756, 0x1a},
	{0x3758, 0x00},
	{0x3759, 0x0f},
	{0x375c, 0x04},
	{0x3767, 0x01},
	{0x376b, 0x44},
	{0x3774, 0x10},
	{0x3776, 0x00},
	{0x377f, 0x08},
	{0x3780, 0x22},
	{0x3781, 0x0c},
	{0x3784, 0x2c},
	{0x3785, 0x1e},
	{0x378f, 0xf5},
	{0x3791, 0xb0},
	{0x3795, 0x00},
	{0x3796, 0x64},
	{0x3797, 0x11},
	{0x3798, 0x30},
	{0x3799, 0x41},
	{0x379a, 0x07},
	{0x379b, 0xb0},
	{0x379c, 0x0c},
	{0x37c0, 0x00},
	{0x37c1, 0x00},
	{0x37c2, 0x00},
	{0x37c3, 0x00},
	{0x37c4, 0x00},
	{0x37c5, 0x00},
	{0x37c6, 0xa0},
	{0x37c7, 0x00},
	{0x37c8, 0x00},
	{0x37c9, 0x00},
	{0x37ca, 0x00},
	{0x37cb, 0x00},
	{0x37cc, 0x00},
	{0x37cd, 0x00},
	{0x37ce, 0x01},
	{0x37cf, 0x00},
	{0x37d1, 0x01},
	{0x37de, 0x00},
	{0x37df, 0x00},
	{0x3800, 0x01},
	{0x3801, 0x5c},
	{0x3802, 0x01},
	{0x3803, 0x08},
	{0x3804, 0x0b},
	{0x3805, 0x83},
	{0x3806, 0x08},
	{0x3807, 0xa7},
	{0x3808, 0x0a},
	{0x3809, 0x20},
	{0x380a, 0x07},
	{0x380b, 0x98},
	{0x380c, 0x0e},
	{0x380d, 0x18},
	{0x380e, 0x07},
	{0x380f, 0xcb},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x52},
	{0x3821, 0x08},
	{0x3823, 0x00},
	{0x3824, 0x00},
	{0x3825, 0x00},
	{0x3826, 0x00},
	{0x3827, 0x00},
	{0x382a, 0x04},
	{0x3a04, 0x07},
	{0x3a05, 0x49},
	{0x3a06, 0x00},
	{0x3a07, 0xf8},
	{0x3a18, 0x00},
	{0x3a19, 0x00},
	{0x3b00, 0x00},
	{0x3b01, 0x00},
	{0x3b02, 0x00},
	{0x3b03, 0x00},
	{0x3b04, 0x00},
	{0x3b05, 0x00},
	{0x3d00, 0x00},
	{0x3d01, 0x00},
	{0x3d02, 0x00},
	{0x3d03, 0x00},
	{0x3d04, 0x00},
	{0x3d05, 0x00},
	{0x3d06, 0x00},
	{0x3d07, 0x00},
	{0x3d08, 0x00},
	{0x3d09, 0x00},
	{0x3d0a, 0x00},
	{0x3d0b, 0x00},
	{0x3d0c, 0x00},
	{0x3d0d, 0x00},
	{0x3d0e, 0x00},
	{0x3d0f, 0x00},
	{0x3d80, 0x00},
	{0x3d81, 0x00},
	{0x3d84, 0x00},
	{0x3e07, 0x20},
	{0x4000, 0x10},
	{0x4001, 0x04},
	{0x4002, 0x45},
	{0x4004, 0x02},
	{0x4005, 0x18},
	{0x4006, 0x16},
	{0x4008, 0x20},
	{0x4009, 0x28},
	{0x400c, 0x00},
	{0x400d, 0x00},
	{0x4058, 0x00},
	{0x4101, 0x12},
	{0x4104, 0x5b},
	{0x4303, 0x00},
	{0x4304, 0x08},
	{0x4307, 0x30},
	{0x4315, 0x00},
	{0x4511, 0x05},
	{0x4512, 0x01},
	{0x4750, 0x00},
	{0x4751, 0x00},
	{0x4752, 0x00},
	{0x4753, 0x00},
	{0x4805, 0x01},
	{0x4806, 0x00},
	{0x481f, 0x36},
	{0x4831, 0x6c},
	{0x4837, 0x0d},
	{0x4a00, 0xaa},
	{0x4a03, 0x01},
	{0x4a05, 0x08},
	{0x4a0a, 0x88},
	{0x5000, 0x06},
	{0x5001, 0x01},
	{0x5002, 0x80},
	{0x5003, 0x20},
	{0x5013, 0x00},
	{0x5046, 0x4a},
	{0x5780, 0x1c},
	{0x5786, 0x20},
	{0x5787, 0x10},
	{0x5788, 0x18},
	{0x578a, 0x04},
	{0x578b, 0x02},
	{0x578c, 0x02},
	{0x578e, 0x06},
	{0x578f, 0x02},
	{0x5790, 0x02},
	{0x5791, 0xff},
	{0x5a08, 0x02},
	{0x5e00, 0x00},
	{0x5e10, 0x0c}
};

static struct msm_camera_i2c_reg_conf ov8830_recommend_settings[] = {
/*init_4lanes*/
	{0x0100, 0x00},
	{0x0103, 0x01},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0100, 0x00},
	{0x0102, 0x01},
	{0x3000, 0x00},
	{0x3001, 0x2a},
	{0x3002, 0x88},
	{0x3003, 0x00},
	{0x3004, 0x00},
	{0x3005, 0x00},
	{0x3006, 0x00},
	{0x3007, 0x00},
	{0x3008, 0x00},
	{0x3009, 0x00},
	{0x3011, 0x41},
	{0x3012, 0x08},
	{0x3013, 0x10},
	{0x3014, 0x00},
	{0x3015, 0x08},
	{0x3016, 0xf0},
	{0x3017, 0xf0},
	{0x3018, 0xf0},
	{0x301b, 0xb4},
	{0x301d, 0x02},
	{0x3021, 0x00},
	{0x3022, 0x00},
	{0x3024, 0x00},
	{0x3026, 0x00},
	{0x3027, 0x00},
	{0x3081, 0x02},
	{0x3083, 0x01},
	{0x3090, 0x02},
	{0x3091, 0x12},
	{0x3092, 0x00},
	{0x3093, 0x00},
	{0x3098, 0x03},
	{0x3099, 0x1e},
	{0x309a, 0x00},
	{0x309b, 0x00},
	{0x30a2, 0x01},
	{0x30b0, 0x05},
	{0x30b2, 0x00},
	{0x30b3, 0x4b},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x3104, 0xa1},
	{0x3106, 0x01},
	{0x3300, 0x00},
	{0x3400, 0x04},
	{0x3401, 0x00},
	{0x3402, 0x04},
	{0x3403, 0x00},
	{0x3404, 0x04},
	{0x3405, 0x00},
	{0x3406, 0x01},
	{0x3500, 0x00},
	{0x3501, 0x9a},
	{0x3502, 0x80},
	{0x3503, 0x07},
	{0x3504, 0x00},
	{0x3505, 0x30},
	{0x3506, 0x00},
	{0x3507, 0x10},
	{0x3508, 0x80},
	{0x3509, 0x10},
	{0x350a, 0x00},
	{0x350b, 0x38},
	{0x350c, 0x00},
	{0x350d, 0x00},
	{0x3600, 0x78},
	{0x3601, 0x02},
	{0x3602, 0x1c},
	{0x3604, 0x38},
	{0x3620, 0x64},
	{0x3625, 0x64},
	{0x3621, 0xb5},
	{0x3622, 0x03},
	{0x3630, 0x55},
	{0x3631, 0xd2},
	{0x3632, 0x00},
	{0x3633, 0x34},
	{0x3634, 0x03},
	{0x3660, 0x80},
	{0x3662, 0x10},
	{0x3665, 0x00},
	{0x3666, 0x00},
	{0x3667, 0x00},
	{0x366a, 0x80},
	{0x366c, 0x00},
	{0x366d, 0x00},
	{0x366e, 0x00},
	{0x366f, 0x20},
	{0x3680, 0xe0},
	{0x3681, 0x00},
	{0x3701, 0x14},
	{0x3702, 0xbf},
	{0x3703, 0x8c},
	{0x3704, 0x78},
	{0x3705, 0x02},
	{0x3708, 0xe4},
	{0x3709, 0x03},
	{0x370a, 0x00},
	{0x370b, 0x20},
	{0x370c, 0x0c},
	{0x370d, 0x11},
	{0x370e, 0x00},
	{0x370f, 0x00},
	{0x3710, 0x00},
	{0x371c, 0x01},
	{0x371f, 0x0c},
	{0x3721, 0x00},
	{0x3724, 0x10},
	{0x3726, 0x00},
	{0x372a, 0x01},
	{0x3730, 0x18},
	{0x3738, 0x22},
	{0x3739, 0x08},
	{0x373a, 0x51},
	{0x373b, 0x02},
	{0x373c, 0x20},
	{0x373f, 0x02},
	{0x3740, 0x42},
	{0x3741, 0x02},
	{0x3742, 0x18},
	{0x3743, 0x01},
	{0x3744, 0x02},
	{0x3747, 0x10},
	{0x374c, 0x04},
	{0x3751, 0xf0},
	{0x3752, 0x00},
	{0x3753, 0x00},
	{0x3754, 0xc0},
	{0x3755, 0x00},
	{0x3756, 0x1a},
	{0x3758, 0x00},
	{0x3759, 0x0f},
	{0x375c, 0x04},
	{0x3767, 0x01},
	{0x376b, 0x44},
	{0x3774, 0x10},
	{0x3776, 0x00},
	{0x377f, 0x08},
	{0x3780, 0x22},
	{0x3781, 0x0c},
	{0x3784, 0x2c},
	{0x3785, 0x1e},
	{0x378f, 0xf5},
	{0x3791, 0xb0},
	{0x3795, 0x00},
	{0x3796, 0x64},
	{0x3797, 0x11},
	{0x3798, 0x30},
	{0x3799, 0x41},
	{0x379a, 0x07},
	{0x379b, 0xb0},
	{0x379c, 0x0c},
	{0x37c0, 0x00},
	{0x37c1, 0x00},
	{0x37c2, 0x00},
	{0x37c3, 0x00},
	{0x37c4, 0x00},
	{0x37c5, 0x00},
	{0x37c6, 0xa0},
	{0x37c7, 0x00},
	{0x37c8, 0x00},
	{0x37c9, 0x00},
	{0x37ca, 0x00},
	{0x37cb, 0x00},
	{0x37cc, 0x00},
	{0x37cd, 0x00},
	{0x37ce, 0x01},
	{0x37cf, 0x00},
	{0x37d1, 0x01},
	{0x37de, 0x00},
	{0x37df, 0x00},
	{0x3800, 0x00},
	{0x3801, 0x0c},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0c},
	{0x3805, 0xe3},
	{0x3806, 0x09},
	{0x3807, 0xa3},
	{0x3808, 0x0c},
	{0x3809, 0xd0},
	{0x380a, 0x09},
	{0x380b, 0x90},
	{0x380c, 0x0e},
	{0x380d, 0x18},
	{0x380e, 0x09},
	{0x380f, 0xb4},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10},
	{0x3821, 0x0e},
	{0x3823, 0x00},
	{0x3824, 0x00},
	{0x3825, 0x00},
	{0x3826, 0x00},
	{0x3827, 0x00},
	{0x382a, 0x04},
	{0x3a04, 0x09},
	{0x3a05, 0xa9},
	{0x3a06, 0x00},
	{0x3a07, 0xf8},
	{0x3a18, 0x00},
	{0x3a19, 0x00},
	{0x3b00, 0x00},
	{0x3b01, 0x00},
	{0x3b02, 0x00},
	{0x3b03, 0x00},
	{0x3b04, 0x00},
	{0x3b05, 0x00},
	{0x3d00, 0x00},
	{0x3d01, 0x00},
	{0x3d02, 0x00},
	{0x3d03, 0x00},
	{0x3d04, 0x00},
	{0x3d05, 0x00},
	{0x3d06, 0x00},
	{0x3d07, 0x00},
	{0x3d08, 0x00},
	{0x3d09, 0x00},
	{0x3d0a, 0x00},
	{0x3d0b, 0x00},
	{0x3d0c, 0x00},
	{0x3d0d, 0x00},
	{0x3d0e, 0x00},
	{0x3d0f, 0x00},
	{0x3d80, 0x00},
	{0x3d81, 0x00},
	{0x3d84, 0x00},
	{0x3e07, 0x20},
	{0x4000, 0x10},
	{0x4001, 0x04},
	{0x4002, 0x45},
	{0x4004, 0x02},
	{0x4005, 0x18},
	{0x4006, 0x16},
	{0x4008, 0x20},
	{0x4009, 0x10},
	{0x400c, 0x00},
	{0x400d, 0x00},
	{0x4058, 0x00},
	{0x4101, 0x12},
	{0x4104, 0x5b},
	{0x4303, 0x00},
	{0x4304, 0x08},
	{0x4307, 0x30},
	{0x4315, 0x00},
	{0x4511, 0x05},
	{0x4512, 0x01},
	{0x4750, 0x00},
	{0x4751, 0x00},
	{0x4752, 0x00},
	{0x4753, 0x00},
	{0x4805, 0x01},
	{0x4806, 0x00},
	{0x481f, 0x36},
	{0x4831, 0x6c},
	{0x4837, 0x0d},
	{0x4a00, 0xaa},
	{0x4a03, 0x01},
	{0x4a05, 0x08},
	{0x4a0a, 0x88},
	{0x5000, 0x06},
	{0x5001, 0x01},
	{0x5002, 0x80},
	{0x5003, 0x20},
	{0x5013, 0x00},
	{0x5046, 0x4a},
	{0x5780, 0x1c},
	{0x5786, 0x20},
	{0x5787, 0x10},
	{0x5788, 0x18},
	{0x578a, 0x04},
	{0x578b, 0x02},
	{0x578c, 0x02},
	{0x578e, 0x06},
	{0x578f, 0x02},
	{0x5790, 0x02},
	{0x5791, 0xff},
	{0x5a08, 0x02},
	{0x5e00, 0x00},
	{0x5e10, 0x0c},
	{0x0100, 0x01}
};