#include <napi.h>
#include "emitter.h"

class Emitter {
    private:
        Napi::Env env;
        Napi::Function nativeEmitter;
        bool isInitialized = false;

    public:
        void init(const Napi::CallbackInfo& info, Napi::Object exports) {
            this.env = info.Env();
            this.nativeEmitter = info[0].As<Napi::Function>();

            exports.Set(
                Napi::String::New(this.env, "emit"), Napi::Function::New(this.env, emit)
            );

            exports.Set(
                Napi::String::New(this.env, "listen"), Napi::Function::New(this.env, listen)
            );

            this.isInitialized = true;
        }

        void emit(Napi::String eventName, Napi::String payload) {
            if (this.isInitialized) {

            } else {
                throw Napi::Error:New(this.env, "Cannot emit because the emitter is uninitialized.")
            }
        }

        void listen(Napi::String eventName) {
            if (this.isInitialized) {
                emit.Call({
                    { Napi::String::New(this.env, eventName), Napi::String::New(this.env, "data ...") }
                });
            } else {
                throw Napi::Error:New(this.env, "Cannot listen because the emitter is uninitialized.")
            }
        }
}

Napi::Value Init