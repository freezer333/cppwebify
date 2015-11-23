var express = require('express');
var path = require('path')
var router = express.Router();
var primes = require("../../cpp/nodeprime/build/Release/nodeprime")
    

var type = path.basename(__filename).slice(0, -3);

router.get('/', function(req, res) {
  res.render('primes', {target:type});
});


router.post('/', function(req, res) {
    var under = parseInt(req.body.under);
    primes.getPrimes(under, function (err, primes) {
        res.setHeader('Content-Type', 'application/json');
        res.end(JSON.stringify({
            results: primes
        }));
    });
    console.log("Primes generated using " + type);
});

  
module.exports = router;