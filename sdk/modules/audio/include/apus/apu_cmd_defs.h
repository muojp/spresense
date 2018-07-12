/****************************************************************************
 * modules/audio/include/apus/apu_cmd_defs.h
 *
 *   Copyright 2018 Sony Semiconductor Solutions Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Sony Semiconductor Solutions Corporation nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __MODULES_AUDIO_INCLUDE_APUS_APU_CMD_DEFS_H
#define __MODULES_AUDIO_INCLUDE_APUS_APU_CMD_DEFS_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "wien2_common_defs.h"

__WIEN2_BEGIN_NAMESPACE
__APU_BEGIN_NAMESPACE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

enum ApuEventType
{
  InvalidApuEvent = 0xFF,
  BootEvent = 0,
  InitEvent,
  ExecEvent,
  FlushEvent,
  SetParamEvent,
  TuningEvent,
  ErrorEvent,
  ApuEventTypeNum
};

enum ApuProcessMode
{
  InvalidApuProcessMode = 0xFF,
  CommonMode = 0,
  DecMode,
  FilterMode,
  EncMode,
  RecognitionMode,
  ApuProcessModeNum
};

enum ApuFlushType
{
  InvalidApuFlushType = (-1),
  Clear = 0,
  Purge,
  ApuFlushTypeNum
};

enum ApuFilterType
{
  InvalidApuFilterType = 0xFF,
  SRC = 0,
  Downmix,
  MFE,
  XLOUD,
  ApuFilterTypeNum
};

enum ApuRecognitionType
{
  InvalidApuRecognitionType = (-1),
  Vad = 0,
  Wuwsr,
  VadWuwsr,
  FreqDet,
  ApuRecognitionTypeNum
};

enum SetParamType
{
  InvalidSetParamType = 0xFF,
  SetParamBF = 0,
  SetParamNS,
  SetParamAES,
  SetParamREF,
  SetParamMIC,
  SetParamAGC,
  SetParamEQ,
  SetParamMFE,
  SetDebugMFE,
  SetParamXLOUD,
  SetDebugXLOUD,
  SetParamTypeNum
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

__APU_END_NAMESPACE
__WIEN2_END_NAMESPACE

#endif /* __MODULES_AUDIO_INCLUDE_APUS_APU_CMD_DEFS_H */

