// factorial.cc
#include <node.h>

namespace haddley
{

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Uint32;
  using v8::Value;

  double fac(int n)
  {
    if (n >= 1)
      return n * fac(n - 1);
    else
      return 1;
  }

  void Method(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();

    Local<v8::Context> context = isolate->GetCurrentContext();
    double d = args[0]->NumberValue(context).ToChecked();
    int n = (int)(unsigned)d;

    double value = fac(n);

    Local<Number> retval = Number::New(isolate, value);

    args.GetReturnValue().Set(retval);
  }

  void init(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "factorial", Method);
  }

  NODE_MODULE(factorial, init)

} // namespace haddley
