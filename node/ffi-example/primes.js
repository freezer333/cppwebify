var ffi = require('ffi')
var ref = require('ref')
var ArrayType = require('ref-array')
var int = ref.types.int
var IntArray = ArrayType(int)



var under = 5000;
var a = new IntArray(under)

var libprime = ffi.Library('../../cpp/lib4ffi/build/Release/prime', {
  'getPrimes': [ int, [ int, IntArray] ]
})


var count = libprime.getPrimes(under, a);

console.log("Found " + count + " primes under " + under);
for (var i = 0; i < count; i++ ) {
    console.log(a[i]);
}

