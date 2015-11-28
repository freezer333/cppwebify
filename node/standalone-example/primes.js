
var under = 10;

// For this example, we're using the standalone_usr example program - 
// which takes input (under) in directly from stdin, after an initial prompt.

var launch = require('child_process').execFile
var program = "../../cpp/standalone_usr/build/Release/standalone_usr";

var primes = launch(program, 
    function(error, stdout, stderr) {
        // The output of the program consists of a prompt:
        // Please enter the maximum number:
        // Then the user types a number, and then the progam
        // outputs one prime per line.  The entire stdout will be
        // Please enter the maximum number:  2
        // 3
        // ...
        // where the 2 is actually the first prime number.  Interactively, 
        // the user supplies the new line when they type the maximum
        // number they are looking for.
        var outputs = stdout.split(":")[1];
        var lines = outputs.split('\n')
                          .slice(0, -3)
                          .map(function (line) {
                            return parseInt(line);
                          });
        console.log(lines);
    });

primes.stdin.setEncoding('utf-8');
primes.stdin.write(under + "\n");








