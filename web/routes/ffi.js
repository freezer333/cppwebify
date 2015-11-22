var express = require('express');
var filename = require('filename');
var router = express.Router();


router.get('/', function(req, res) {
  res.render('primes', {target:filename()});
});


router.post('/', function(req, res) {
    var ffi = require('ffi')
    var ref = require('ref')
    var ArrayType = require('ref-array')
    var int = ref.types.int
    var IntArray = ArrayType(int)

    var under = parseInt(req.body.under);
    var a = new IntArray(under);

    
    var libprime = ffi.Library('../cpp/lib4ffi/build/Release/prime', {
      'getPrimes': [ int, [ int, IntArray] ]
    })

    var count = libprime.getPrimes(under, a);
    var primes = a.toArray().slice(0, count);
    
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify({
      results: primes
    }));
});

  
module.exports = router;