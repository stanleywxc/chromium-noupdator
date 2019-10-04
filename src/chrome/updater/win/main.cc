// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <windows.h>

#include "chrome/updater/updater.h"

int APIENTRY wWinMain(HINSTANCE instance, HINSTANCE prev, wchar_t*, int) {

  // Commented out for updater and sending crash report to google
  // return updater::UpdaterMain(0, nullptr);

  return -1;
}
