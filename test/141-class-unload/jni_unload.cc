/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "jni.h"

#include <iostream>

#include "jit/jit.h"
#include "runtime.h"
#include "thread-current-inl.h"

namespace art {
namespace {

extern "C" JNIEXPORT void JNICALL Java_IntHolder_waitForCompilation(JNIEnv*, jclass) {
  jit::Jit* jit = Runtime::Current()->GetJit();
  if (jit != nullptr) {
    jit->WaitForCompilationToFinish(Thread::Current());
  }
}

extern "C" JNIEXPORT void JNICALL Java_Main_stopJit(JNIEnv*, jclass) {
  jit::Jit* jit = Runtime::Current()->GetJit();
  if (jit != nullptr) {
    jit->Stop();
  }
}

extern "C" JNIEXPORT void JNICALL Java_Main_startJit(JNIEnv*, jclass) {
  jit::Jit* jit = Runtime::Current()->GetJit();
  if (jit != nullptr) {
    jit->Start();
  }
}

}  // namespace
}  // namespace art
