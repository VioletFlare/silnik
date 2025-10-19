class Emitter {
    private:
        Napi::Env env;
        Napi::Function nativeEmitter;
        bool isInitialized = false;

    public:
        void init(const Napi::CallbackInfo& info, Napi::Object exports);
        void emit(Napi::String eventName, Napi::String payload);
        void listen(Napi::String eventName);
}