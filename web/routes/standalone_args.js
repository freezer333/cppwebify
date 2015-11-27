var express = require('express');
var path = require('path')
var router = express.Router();

var type = path.basename(__filename).slice(0, -3)

router.get('/', function(req, res) {
  res.render('primes', {target:type});
});

router.post('/', function(req, res) {

    // I'm using sync mode here, but if you don't want to
    // buffer all the output, but use it incrementally, 
    // you'd use the asynchronous methods (ie. exectFile).
    // That would be far more effective if you were
    // streaming the results to the browser, but here
    // we need all the primes to render the response anyway...
    var exec = require('child_process').execFileSync
    var program = "../cpp/standalone_stdio/build/Release/standalone";


    var under = parseInt(req.body.under);
    var output = exec(program, [under]).toString();

    var primes = output.split("\n")
                       .slice(0, -3)
                       .map(function (line) {
                           return parseInt(line);
                       });

    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify({
      results: primes
    }));

    console.log("Primes generated using " + type);
});

  
module.exports = router;