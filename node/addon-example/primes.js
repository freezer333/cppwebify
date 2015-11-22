var primes = require("../../cpp/nodeprime/build/Release/nodeprime")

var under = 50000;

var count = primes.getPrimes(under, function (err, primes) {
    primes.forEach( function (p) { console.log(" - " + p + " - ")});
});
