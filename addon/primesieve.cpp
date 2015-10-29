#include <node.h>
#include <v8.h>

#include <primesieve.hpp>
#include <iostream>
#include <vector>

using namespace v8;


void GeneratePrimes(const v8::FunctionCallbackInfo<v8::Value>& args) {

  std::vector<int> primes;
  primesieve::generate_primes(1000, 2000, &primes);

  for (auto i: primes) {
  	std::cout << i << std::endl;
  }


  Isolate* isolate = args.GetIsolate();
  Local<Number> retval = v8::Number::New(isolate, 0);
  args.GetReturnValue().Set(retval);
}


void init(Handle <Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(exports, "generate_primes", GeneratePrimes);
}


NODE_MODULE(primesieve, init)  