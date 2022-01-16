// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SRC_TIFFFRAME_H_
#define SRC_TIFFFRAME_H_
#include <jpeglib.h>
#include <memory>
#include <string>
#include <vector>

#include "src/frame.h"
#include "src/tiffFile.h"


namespace wsiToDicomConverter {

// Frame represents a DICOM image frame from the OpenSlide library or
// downsampled from level captured at higher magnification.
class TiffFrame : public Frame {
 public:
  TiffFrame(
    TiffFile *tiffFile, int64_t locationX, int64_t locationY, int64_t level,
    int64_t frameWidth, int64_t frameHeight);

  bool canDecodeJpeg();
  TiffDirectory *tiffDirectory() const;

  virtual ~TiffFrame();
  // Gets frame by openslide library, performs scaling it and compressing
  virtual void sliceFrame();
  virtual std::string photoMetrInt() const;
  virtual int64_t rawABGRFrameBytes(uint8_t *raw_memory, int64_t memorysize);
  virtual bool hasRawABGRFrameBytes() const;
  virtual void clearDicomMem();
  virtual void clearRawABGRMem();
  virtual void incSourceFrameReadCounter();
  TiffFile *tiffFile() const;
  int64_t tiffFileLevel() const;

 private:
  TiffFile *tiffFile_;
  int64_t level_;
  const J_COLOR_SPACE jpegDecodeColorSpace() const;
};

}  // namespace wsiToDicomConverter

#endif  // SRC_TIFFFRAME_H_
