#include <napi.h>
#include "core/facade.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Facade *f = new Facade(env);
  Napi::Object ex = f->createExports(exports);

  return ex;
}

NODE_API_MODULE(addon, Init)