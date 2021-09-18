﻿// -----------------------------------------------------------------------------------------
// ffmpegOut by rigaya
// -----------------------------------------------------------------------------------------
// The MIT License
//
// Copyright (c) 2012-2017 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// --------------------------------------------------------------------------------------------

#ifndef _AUO_VIDEO_H_
#define _AUO_VIDEO_H_

#include "output.h"
#include "auo_conf.h"
#include "auo_system.h"

typedef struct {
    DWORD FOURCC;   //FOURCC
    DWORD size;  //1ピクセルあたりバイト数
} COLORFORMAT_DATA;

typedef struct {
    unsigned char b, g, r, a;
} PixelBGRA;

typedef struct {
    int frame_start;
    int frame_end;
    int width;
    int height;
    int rate;
    int scale;
} ExeditData;

typedef struct {
    BOOL(*output_start)(ExeditData* data);
    void(*output_end)();
    PixelBGRA* (*get_image)(int frame);
} ExeditFileMapping;

enum {
    CF_YUY2 = 0,
    CF_YC48 = 1,
    CF_RGB  = 2,
    CF_RGBA = 3,
};
static const char * const CF_NAME[] = { "YUY2", "YC48", "RGB", "RGBA"};
static const COLORFORMAT_DATA COLORFORMATS[] = {
    { MAKEFOURCC('Y', 'U', 'Y', '2'), 2 }, //YUY2
    { MAKEFOURCC('Y', 'C', '4', '8'), 6 }, //YC48
    { NULL,                           3 }, //RGB
    { NULL,                           3 }  //RGBA(Unused)
};

AUO_RESULT video_output(CONF_GUIEX *conf, const OUTPUT_INFO *oip, PRM_ENC *pe, const SYSTEM_DATA *sys_dat);

static BOOL get_exedit_file_mapping(ExeditFileMapping* efm);

#endif //_AUO_VIDEO_H_