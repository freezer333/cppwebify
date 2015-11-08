var ffi = require('ffi')

var libprime = ffi.Library('./libprimesieve', {
  'generate_primes': [ 'void', [ 'int' ] ]
})


libprime.generate_primes(parseInt(100000))
