var temp = require('temp');
var fs = require('fs');
var path = require('path');

temp.track();

var launch = require('child_process').execFile
var program = "../../cpp/standalone_flex_file/build/Release/standalone_flex_file";

var under = "1000\n";


temp.mkdir('node_example', function(err, dirPath) {
  var inputPath = path.join(dirPath, 'input.txt');
  var outputPath = path.join(dirPath, 'output.txt');
  
  fs.writeFile(inputPath, under, function(err) {
    if (err) throw err;
    var primes = launch(program, [inputPath, outputPath], function(error) {
        if (error ) throw error;
        fs.readFile(outputPath, process_output);
    });
  });
});


var process_output = function(err, data) {
    if (err) throw err;
    var results = data.toString()
                    .split('\n')
                    .slice(0, -3)
                    .map(function (line) {
                        return parseInt(line);
                    });
    console.log(results);
}

