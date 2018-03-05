// factorial.cc
#include <node.h>

namespace haddley
{

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    unsigned long long fac(int n)
    {
        if (n >= 1)
            return n * fac(n - 1);
        else
            return 1;
    }

    void Method(const FunctionCallbackInfo<Value> &args)
    {

        int n = (int)(unsigned)args[0]->NumberValue();

        long value = fac(n);

        args.GetReturnValue().Set(value);
    }

    void init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "factorial", Method);
    }

    NODE_MODULE(factorial, init)

} // namespace haddley