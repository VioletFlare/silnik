#include <napi.h>
#include "emitter.h"

class Emitter {
    private:
        Napi::Env env;
        Napi::Function nativeEmitter;
        bool isInitialized = false;


    public:
        void init(const Napi::CallbackInfo& info) {
            this.env = info.Env();
            this.nativeEmitter = info[0].As<Napi::Function>();
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